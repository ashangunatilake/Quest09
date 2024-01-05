#include <string>
#include <iostream>
#include <list>
#include "Account.h"
using namespace std;



class Customer
{
 private:
     string UserName;
     string Name;
     string PhoneNumber;
     string Password= "Password@1234";
     Account* SavingAccount;
     Account* CurrentAccount;
    

 public:
    Customer(string userName,string name,string phoneNumber);
    ~Customer();
    void ShowCustomerDetails();
    string GetUserName();
};