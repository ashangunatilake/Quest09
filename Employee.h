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

class Bank;

using namespace std;

class Employee : public User
{
public:
	Employee(string name);
	void addCustomer(Bank bank, string name);
	void createSavingAccount(Bank bank, string name);
	void createCurrentAccount(Bank bank, string name, double overdraft = 0);
	void closeCustomerAccount(Bank bank, int number);
	void depositMoney(Bank bank, int number, double amount);
	void withdrawMoney(Bank bank, int number, double amount);
	void viewTransactions();
};