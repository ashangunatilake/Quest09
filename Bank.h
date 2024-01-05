#pragma once
#include <vector>
#include <string>
#include "Administrator.h"
#include "Employee.h"
#include "Customer.h"
#include "Account.h"
#include "SavingAccount.h"
#include "CurrentAccount.h"

class Administrator;
class Employee;

using namespace std;

class Bank
{
public:
	Administrator* admin;
	int current_date;
	double annual_saving_rate;
	double overdraft_charge;
	Account* bank_account;
	vector<Employee*> employees;
	vector<Customer*> customers;
	vector<Account*> accounts;
	vector<SavingAccount*> saving_accounts;
	vector<CurrentAccount*> current_accounts;

	Bank(int date, double rate, double charge);
	Customer* getCustomer(string name);
	Account* getSavingAccount(int number);
	Account* getCurrentAccount(int number);
};