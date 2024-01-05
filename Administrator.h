#pragma once
#include <string>
#include "User.h"
#include "Bank.h"

class Bank;

using namespace std;

class Administrator : public User
{
public:
	Administrator(string name);

	void addEmployee(Bank bank, string name);
	void increaseDate(Bank bank);
	void setAnnualSavingInterest(Bank bank, double rate);
	void addDailyInterest(Bank bank, double rate);
	void setOverdraftCharge(Bank bank, double charge);
};