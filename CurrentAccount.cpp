#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(int number) : Account(number)
{
    overdraft_limit = 0;
}

double CurrentAccount::getOverdraftLimit()
{
    return overdraft_limit;
}

void CurrentAccount::setOverdraftLimit(double amount)
{
    overdraft_limit = amount;
}