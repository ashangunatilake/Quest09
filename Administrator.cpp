#include "Administrator.h"
#include <string>

using namespace std;

Administrator::Administrator() : User() {}

Administrator::Administrator(string name) : User(name, 'A') {}
	
void Administrator::addEmployee(Bank& bank, string name)
{
	Employee* employee = new Employee(name);
	bank.employees.push_back(employee);
}

void Administrator::setAnnualSavingInterest(Bank bank, double rate)
{
	bank.annual_saving_rate = rate;
}

void Administrator::setOverdraftCharge(Bank bank, double charge)
{
	bank.overdraft_charge = charge;
}

void Administrator::addDailyInterest(Bank& bank)
{
	for (const auto& a : bank.saving_accounts)
	{
		a->setBalance(a->getBalance() + a->getBalance() * (bank.annual_saving_rate / 365));
	}
}

void Administrator::chargeDailyOverdraftPenalty(Bank bank)
{
	for (const auto& c : overdrafts)
	{
		c->setOverdraftCharges(c->getOverdraftCharges() + bank.overdraft_charge);
	}
}

void Administrator::increaseDate(Bank& bank)
{
	bank.current_date++;
	chargeDailyOverdraftPenalty(bank);
}
