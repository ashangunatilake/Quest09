#pragma once
#include <string>

using namespace std;

class Transaction
{
public:
	int date;
	string type;
	double amount;
	string senders_account_number;
	double balance;

	Transaction(int d, string type, double a, string n, double b);
	void displayTransaction();
};

