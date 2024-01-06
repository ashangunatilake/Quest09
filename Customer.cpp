#include "Customer.h"
#include <fstream>
#include <iostream>

Customer::Customer(string name, string c_number) : User(name, 'C', c_number)
{
    saving_account = NULL;
    current_account = NULL;
    overdraft_charges = 0;
}

Customer::~Customer(){}

SavingAccount* Customer::getSavingAccount()
{
    return saving_account;
}

void Customer::setSavingAccount(SavingAccount* account)
{
    saving_account = account;
}

CurrentAccount* Customer::getCurrentAccount()
{
    return current_account;
}

void Customer::setCurrentAccount(CurrentAccount* account)
{
    current_account = account;
}

double Customer::getOverdraftCharges()
{
    return overdraft_charges;
}

vector<Transaction*>* Customer::getTransactions()
{
    return &transactions;
}

void Customer::setOverdraftCharges(double overdraft)
{
    overdraft_charges = overdraft;
}

void  Customer::writeTransaction(Transaction* transaction)
{
    ofstream transactionFile;
    transactionFile.open("Transactions/" + username + "_transactions.txt", ios::app);

    if (transactionFile.is_open())
    {
        transactionFile << "Date: " << transaction->date << "\n";
        transactionFile << "Type: " << transaction->type << "\n";
        transactionFile << "Amount: " << transaction->amount << "\n";
        transactionFile << "Sender's Account Number: " << transaction->senders_account_number << "\n";
        transactionFile << "Balance: " << transaction->balance << "\n\n";

        transactionFile.close();
        cout << "Transaction written to file." << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

void  Customer::viewTransactions()
{
    ifstream transactionFile("Transactions/"+ username + "_transactions.txt");

    if (transactionFile.is_open())
    {
        string line;
        if (!getline(transactionFile, line))
        {
            cout << "No transactions found for this customer." << endl;
            return;
        }

        while (getline(transactionFile, line))
        {
            cout << line << endl;
        }

        transactionFile.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}


void Customer::depositMoney(Bank& bank, int number, double amount)
{
	Account* account;
	if ((account = bank.getSavingAccount(number)) != NULL)
	{
		saving_account->setBalance(saving_account->getBalance() + amount);
		Transaction* transaction = new Transaction(bank.current_date, "deposit", amount, username, saving_account->getBalance());
		transactions.push_back(transaction);	
	}
	else if ((account = bank.getCurrentAccount(number)) != NULL)
	{
		current_account->setBalance(current_account->getBalance() + amount);
		Transaction* transaction = new Transaction(bank.current_date, "deposit", amount, username, current_account->getBalance());
		transactions.push_back(transaction);
	}
	else
	{
		cout << "Account not found!" << endl;
	}
}

void Customer::withdrawMoney(Bank& bank, int number, double amount)
{
	Account* account;
	if ((account = bank.getSavingAccount(number)) != NULL)
	{
		if (saving_account->getBalance() < amount)
		{
			cout << "Insufficient Balance!" << endl;
			return;
		}
		else
		{
			saving_account->setBalance(account->getBalance() - amount);
			Transaction* transaction = new Transaction(bank.current_date, "withdraw", amount, username, saving_account->getBalance());
			transactions.push_back(transaction);
		}
	}
	else if ((account = bank.getCurrentAccount(number)) != NULL)
	{
		int yet_to_withdraw;
		if (current_account->getBalance() < amount)
		{
			yet_to_withdraw = amount - current_account->getBalance();
			if (current_account->getOverdraftLimit() < yet_to_withdraw)
			{
				cout << "Withdraw Amount Exceeds Overdraft Limit!" << endl;
				return;
			}
			else
			{
				current_account->setBalance(0);
				bank.bank_account->setBalance(bank.bank_account->getBalance() - yet_to_withdraw);
				bank.admin->overdrafts.push_back(current_account->getCustomer());
				Transaction* transaction = new Transaction(bank.current_date, "withdraw", amount, username, account->getBalance());
				transactions.push_back(transaction);
			}
		}
		else
		{
			current_account->setBalance(current_account->getBalance() - amount);
			Transaction* transaction = new Transaction(bank.current_date, "withdraw", amount, username, account->getBalance());
			transactions.push_back(transaction);
		}
	}
	else
	{
		cout << "Account not found!" << endl;
	}
}