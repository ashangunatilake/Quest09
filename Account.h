#pragma once
#include <string>
#include <list>

class Customer;

using namespace std;

class Account
{
private:
    Customer* customer;
    int account_number;
    double balance;
    list<string> AccountHistory={};
      
public:
    Account(int number);
    ~Account();
    Customer* getCustomer();
    int getAccountNumber();
    double getBalance();
    void setBalance(double amount);
    //void ShowAccountFullDetails();
    //void ShowAccountDetails();

};
