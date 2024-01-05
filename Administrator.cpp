#include <string>
#include "Administrator.h"

using namespace std;

Administrator::Administrator(string name) : User(name) {}
	
void Administrator::addEmployee(Bank bank, string name)
{
	Employee* employee = new Employee(name);
	bank.employees.push_back(employee);
}

void Administrator::increaseDate(Bank bank)
{
	bank.current_date++;
}

void Administrator::setAnnualSavingInterest(Bank bank, double rate)
{
	bank.annual_saving_rate = rate;
}

void Administrator::addDailyInterest(Bank bank, double rate)
{
	for (const auto& a : bank.saving_accounts)
	{
		a->setBalance(a->getBalance() + a->getBalance() * rate);
		//a.amount = a.amount + a.amount * rate;
	}
}

void setOverdraftCharge(Bank bank, double charge)
{
	bank.overdraft_charge = charge;
}