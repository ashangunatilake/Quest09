#include "Transaction.h"

Transaction::Transaction(int d, string type, double a, string n, double b)
{
	date = d;
	type = type;
	amount = a;
	senders_account_number = n;
	balance = b;
}

void Transaction::displayTransaction()
{

}

