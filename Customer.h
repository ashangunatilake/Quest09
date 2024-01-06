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
     //int saving_account_number;
     //int current_account_number;
     SavingAccount* saving_account;
     CurrentAccount* current_account;
     double overdraft_charges;
     vector<Transaction*> transactions;

 public:
    Customer(string name, string c_number);
    //Customer(string name, int s_number, int c_number);
    ~Customer();
    SavingAccount* getSavingAccount();
    void setSavingAccount(SavingAccount* account);
    CurrentAccount* getCurrentAccount();
    void setCurrentAccount(CurrentAccount* account);
    double getOverdraftCharges();
    vector<Transaction*>* getTransactions();
    void setOverdraftCharges(double overdraft);
    void writeTransaction(Transaction* transaction);
    void viewTransactions();
};