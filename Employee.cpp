#include "Employee.h"
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

Employee::Employee(string name) : User(name, 'E', "non") {}

void Employee::addCustomer(Bank &bank, string name, string c_number)
{
	Customer* customer = new Customer(name, c_number);
	bank.customers.push_back(customer);
}

void Employee::createSavingAccount(Bank &bank, string name)
{
	Customer* customer;

	if ((customer = bank.getCustomer(name)) != NULL)
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		int account_number = rand() % (800000 - 900000 + 1);

		//account is created with 0 balance
		SavingAccount* saving_account = new SavingAccount(customer->getUsername(), account_number, 0);
		bank.saving_accounts.push_back(saving_account);
	}
	else
	{
		cout << "There is no customer with that username!" << endl;
	}
	
}

void Employee::createCurrentAccount(Bank &bank, string name, double overdraft)
{
	Customer* customer;

	if ((customer = bank.getCustomer(name)) != NULL)
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		int account_number = rand() % (800000 - 900000 + 1);

		//account is created with 0 balance and 0 overdraft limit
		CurrentAccount* current_account = new CurrentAccount(customer->getUsername(), account_number, 0, 0);
		current_account->setOverdraftLimit(overdraft);
		bank.current_accounts.push_back(current_account);
	}
	else
	{
		cout << "There is no customer with that username!" << endl;
	}
	
}

void Employee::closeCustomerAccount(Bank &bank, int number)
{
	Account* account;
	if ((account = bank.getSavingAccount(number)) != NULL)
	{
		bank.saving_accounts.erase(remove(bank.saving_accounts.begin(), bank.saving_accounts.end(), account), bank.saving_accounts.end());
		cout << "Savings account deleted" << endl;
	}
	else if ((account = bank.getCurrentAccount(number)) != NULL)
	{
		bank.current_accounts.erase(remove(bank.current_accounts.begin(), bank.current_accounts.end(), account), bank.current_accounts.end());
		cout << "Current accout deleted" << endl;
	}
	else
	{
		cout << "Account not found!" << endl;
	}
}

void Employee::depositMoney(Bank &bank, string s_name, int r_number, double amount)
{
	Account* account;
	if ((account = bank.getSavingAccount(r_number)) != NULL)
	{
		account->setBalance(account->getBalance() + amount);
		Transaction* transaction = new Transaction(bank.current_date, "deposit", amount, s_name, account->getBalance());
		vector<Transaction*>* vecPtr = account->getCustomer()->getTransactions();
		vecPtr->push_back(transaction);
	}
	else if ((account = bank.getCurrentAccount(r_number)) != NULL)
	{
		account->setBalance(account->getBalance() + amount);
		Transaction* transaction = new Transaction(bank.current_date, "deposit", amount, s_name, account->getBalance());
		vector<Transaction*>* vecPtr = account->getCustomer()->getTransactions();
		vecPtr->push_back(transaction);
	}
	else
	{
		cout << "Account not found!" << endl;
	}
}

void Employee::withdrawMoney(Bank &bank, string s_name, int r_number, double amount)
{
	Account* account;
	if ((account = bank.getSavingAccount(r_number)) != NULL)
	{
		if (account->getBalance() < amount)
		{
			cout << "Insufficient Balance!" << endl;
			return;
		}
		else
		{
			account->setBalance(account->getBalance() - amount);
			Transaction* transaction = new Transaction(bank.current_date, "withdraw", amount, s_name, account->getBalance());
			vector<Transaction*>* vecPtr = account->getCustomer()->getTransactions();
			vecPtr->push_back(transaction);
		}
	}
	else if ((account = bank.getCurrentAccount(r_number)) != NULL)
	{
		CurrentAccount* c_account = static_cast<CurrentAccount*>(account);
		int yet_to_withdraw;
		if (c_account->getBalance() < amount)
		{
			yet_to_withdraw = amount - c_account->getBalance();
			if (c_account->getOverdraftLimit() < yet_to_withdraw)
			{
				cout << "Withdraw Amount Exceeds Overdraft Limit!" << endl;
				return;
			}
			else
			{
				bank.bank_account->setBalance(bank.bank_account->getBalance() - yet_to_withdraw);
				bank.admin->overdrafts.push_back(c_account->getCustomer());
				Transaction* transaction = new Transaction(bank.current_date, "withdraw", amount, s_name, account->getBalance());
				vector<Transaction*>* vecPtr = account->getCustomer()->getTransactions();
				vecPtr->push_back(transaction);
			}
		}
		else
		{
			account->setBalance(c_account->getBalance() - amount);
			Transaction* transaction = new Transaction(bank.current_date, "withdraw", amount, s_name, account->getBalance());
			vector<Transaction*>* vecPtr = account->getCustomer()->getTransactions();
			vecPtr->push_back(transaction);
		}
	}
	else
	{
		cout << "Account not found!" << endl;
	}
}

void Employee::viewTransactions(Bank &bank, int number)
{
	Customer* customer;
	Account* account;
	if ((account = bank.getSavingAccount(number)) != NULL)
	{
		customer = account->getCustomer();
		customer->viewTransactions();
		
	}
	else if ((account = bank.getCurrentAccount(number)) != NULL)
	{
		customer = account->getCustomer();
		customer->viewTransactions();
	}
}