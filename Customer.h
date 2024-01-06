#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "User.h"
#include "SavingAccount.h"
#include "CurrentAccount.h"
#include "Transaction.h"

using namespace std;

class Customer : public User
{
 private:
     SavingAccount *saving_account;
     CurrentAccount *current_account;
     double overdraft_charges;
     vector<Transaction*> transactions;

 public:
    Customer(string name);
    ~Customer();
    SavingAccount* getSavingAccount();
    CurrentAccount* getCurrentAccount();
    double getOverdraftCharges();
    vector<Transaction*>* getTransactions();
    void setOverdraftCharges(double overdraft);
    void writeTransaction(Transaction* transaction);
    void viewTransactions();
};