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
    string contact_number;
    int account_number;
    double balance;
      
public:
    Account(int number);
    Account(string h, string c, int number, double b);
    ~Account();
    Customer* getCustomer();
    void setCustomer(Customer* holder);
    int getAccountNumber();
    double getBalance();
    void setBalance(double amount);
};
