#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "Bank.h"
#include "Customer.h"

class Bank;

using namespace std;

class Administrator : public User
{
public:
	Administrator(string name);
	vector<Customer*> overdrafts;

	void addEmployee(Bank bank, string name);
	void increaseDate(Bank bank);
	void setAnnualSavingInterest(Bank bank, double rate);
	void setOverdraftCharge(Bank bank, double charge);
	void addDailyInterest(Bank bank);
	void chargeDailyOverdraftPenalty(Bank bank);
};