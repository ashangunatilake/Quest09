#pragma once
#include <cstdlib>
#include <ctime>
#include <string>
#include "Bank.h"
#include "User.h"
#include "Customer.h"
#include "Account.h"
#include "SavingAccount.h"
#include "CurrentAccount.h"
#include "Transaction.h"

class Bank;

using namespace std;

class Employee : public User
{
public:
	Employee(string name, string c_number);
	void addCustomer(Bank &bank, string name, string c_number);
	void createSavingAccount(Bank &bank, string name);
	void createCurrentAccount(Bank &bank, string name, double overdraft = 0);
	void closeCustomerAccount(Bank &bank, int number);
	void depositMoney(Bank &bank, string s_name, int r_number, double amount);
	void withdrawMoney(Bank &bank, string s_name, int r_number, double amount);
	void viewTransactions(Bank &bank, int number);
};
