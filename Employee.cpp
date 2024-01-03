#include "Bank.cpp"
#include <cstdlib>
#include <ctime>

using namespace std;

class Employee: User
{
public:
	Employee(string username, string password) : User(username, password) {}

	addCustomer(string name)
	{
		Bank.customers.push_back(Customer(name));
	}

	createSavingAccount(string name)
	{
		Customer customer = getCustomer(name);

		srand(static_cast<unsigned int>(time(nullptr);
		int account_number = rand() % (800000 - 900000 + 1);

		SavingAccount* saving_account = new SavingAccount(account_number);
		saving_accounts.push_back(saving_account);
	}

	createCurrentAccount(string name)
	{
		Customer customer = getCustomer(name);

		srand(static_cast<unsigned int>(time(nullptr);
		int account_number = rand() % (800000 - 900000 + 1);

		CurrentAccount* current_account = new CurrentAccount(account_number);
		current_accounts.push_back(current_account);
	}

	closeCustomerAccount(number)
	{
		Bank.accounts.erase(getAccount(number));
	}

	depositMoney(number, amount)
	{
		Account* account = getAccount(number);
		account.amount =+ amount;
	}

	withdrawMoney(number, amount)
	{
		Account* account = getAccount(number);
		account.amount =- amount;
	}

	viewTransactions()
	{

	}
};