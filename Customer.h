#pragma once
#include <string>
#include <iostream>
#include <list>
#include "User.h"
#include "SavingAccount.h"
#include "CurrentAccount.h"

using namespace std;

class Customer : public User
{
 private:
     SavingAccount *saving_account;
     CurrentAccount *current_account;
    

 public:
    Customer(string name);
    ~Customer();
    SavingAccount* getSavingAccount();
    CurrentAccount* getCurrentAccount();
    //void ShowCustomerDetails();
};