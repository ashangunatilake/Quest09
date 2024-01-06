#pragma once
#include <string>
#include <list>

class Customer;

using namespace std;

class Account
{
private:
    Customer* customer;
    string holder;
    int account_number;
    double balance;
    list<string> AccountHistory={};
      
public:
    Account(int number);
    Account(string h, int number, double b);
    ~Account();
    Customer* getCustomer();
    void setCustomer(Customer* holder);
    int getAccountNumber();
    double getBalance();
    void setBalance(double amount);
    //void ShowAccountFullDetails();
    //void ShowAccountDetails();

};
