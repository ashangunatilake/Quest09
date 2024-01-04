#pragma once
#include "Account.h"

class CurrentAccount : public Account
{
private:
    double overdraft_limit;

public:
    CurrentAccount(int number);
    double getOverdraftLimit();
    void setOverdraftLimit(double amount);
};