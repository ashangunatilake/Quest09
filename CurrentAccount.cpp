#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(int number) : Account(number)
{
    overdraft_limit = 0;
}

CurrentAccount::CurrentAccount(string h, int number, double b, double ol) : Account(h, number, b)
{
    overdraft_limit = ol;
}

double CurrentAccount::getOverdraftLimit()
{
    return overdraft_limit;
}

void CurrentAccount::setOverdraftLimit(double amount)
{
    overdraft_limit = amount;
}