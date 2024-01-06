#pragma once
#include "Account.h"

class CurrentAccount : public Account
{
private:
    double overdraft_limit;

public:
    CurrentAccount(string h, string c, int number, double b, double ol);
    double getOverdraftLimit();
    void setOverdraftLimit(double amount);
};