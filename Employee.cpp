#include "Employee.h"
#include <string>

using namespace std;

Employee::Employee(string name) : User(name) {}

void Employee::addCustomer(Bank bank, string name)
{
	Customer* customer = new Customer(name);
	bank.customers.push_back(customer);
}

void Employee::createSavingAccount(Bank bank, string name)
{
	Customer* customer = bank.getCustomer(name);

	srand(static_cast<unsigned int>(time(nullptr)));
	int account_number = rand() % (800000 - 900000 + 1);

	SavingAccount* saving_account = new SavingAccount(account_number);
	bank.saving_accounts.push_back(saving_account);
}

void Employee::createCurrentAccount(Bank bank, string name, double overdraft)
{
	Customer* customer = bank.getCustomer(name);

	srand(static_cast<unsigned int>(time(nullptr)));
	int account_number = rand() % (800000 - 900000 + 1);
	CurrentAccount* current_account = new CurrentAccount(account_number);
	current_account->setOverdraftLimit(overdraft);
	bank.current_accounts.push_back(current_account);
}

void Employee::closeCustomerAccount(Bank bank, int number)
{
	Account* account;
	if (account = bank.getSavingAccount(number))
	{
		bank.saving_accounts.erase(remove(bank.saving_accounts.begin(), bank.saving_accounts.end(), account), bank.saving_accounts.end());
	}
	else if (account = bank.getCurrentAccount(number))
	{
		bank.current_accounts.erase(remove(bank.current_accounts.begin(), bank.current_accounts.end(), account), bank.current_accounts.end());
	}
}

void Employee::depositMoney(Bank bank, int number, double amount)
{
	Account* account;
	if (account = bank.getSavingAccount(number))
	{
		account->setBalance(amount);
	}
	else if (account = bank.getCurrentAccount(number))
	{
		account->setBalance(amount);
	}
}

void Employee::withdrawMoney(Bank bank, int number, double amount)
{
	Account* account;
	if (account = bank.getSavingAccount(number))
	{
		if (account->getBalance() < amount)
		{
			cout << "Insufficient Balance!" << endl;
			return;
		}
		else
		{
			account->setBalance(account->getBalance() - amount);
		}
	}
	else if (account = bank.getCurrentAccount(number))
	{
		//CurrentAccount* c_account = account;
		int yet_to_withdraw;
		if (account->getBalance() < amount)
		{
			//////////////////////////////////////////////////
			yet_to_withdraw = amount - account->getBalance();
			/*if (account->overdraft_limit < yet_to_withdraw)
			{
				cout << "Withdraw Amount Exceeds Overdraft Limit!" << endl;
				return;
			}
			else
			{
				bank.bank_account->setBalance(bank.bank_account->getBalance() - yet_to_withdraw);
			}*/
		}
		else
		{
			account->setBalance(amount);
		}
	}	
}

void Employee::viewTransactions()
{

}