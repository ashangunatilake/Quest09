#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(string h, string c, int number, double b, double ol) : Account(h, c, number, b)
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