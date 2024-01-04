#include "Bank.h"
#include <string>

using namespace std;

Bank::Bank(int date, double rate, double charge)
{
	admin = NULL;
	current_date = date;
	annual_saving_rate = rate;
	overdraft_charge = charge;
	bank_account->setBalance(1000000);
}

Customer* Bank::getCustomer(string name)
{
	for (const auto& c : customers) 
	{
		if (c->getUsername() == name)
		{
			return c;
		}
	}
}

Account* Bank::getSavingAccount(int number)
{
	for (const auto& a : saving_accounts)
	{
		if (a->getAccountNumber() == number)
		{
			return a;
		}
	}
}

Account* Bank::getCurrentAccount(int number)
{
	for (const auto& a : current_accounts)
	{
		if (a->getAccountNumber() == number)
		{
			return a;
		}
	}

	/*for (const auto& a : accounts)
	{
		if (a.account_number == number)
		{
			return a;
		}
	}*/
}

/*Account* getAccount(int number)
{
		
}*/
