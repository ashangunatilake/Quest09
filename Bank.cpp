#include <vector>
#include "Account.h"
#include "Employee.cpp"

using namespace std;

class Bank
{
public:
	int current_date;
	double annual_saving_rate;
	double overdraft_charge;
	Account* bank_account;
	vector<Employee> employees;
	vector<Customer> customers;
	vector<Accounts*> accounts;
	vector<SavingAccount*> saving_accounts;
	vector<CurrentAccount*> current_accounts;

	Bank(int date, double rate, double charge)
	{
		current_date = date;
		annual_saving_rate = rate;
		overdraft_charge = charge;
		bank_account = 1000000;
	}

	Customer* getCustomer(string name)
	{
		for (const auto& c : customers) 
		{
			if (c.username == name) 
			{
				return c;
			}
		}
	}

	Account* getAccount(number)
	{
		/*for (const auto& a : saving_accounts)
		{
			if (a.account_number == number)
			{
				return a;
			}
		}

		for (const auto& a : current_accounts)
		{
			if (a.account_number == number)
			{
				return a;
			}
		}*/

		for (const auto& a : accounts)
		{
			if (a.account_number == number)
			{
				return a;
			}
		}
	}
};