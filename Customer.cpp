#include "Customer.h";
#include <iostream>;

Customer::Customer(string userName,string name,string phoneNumber)
{
    UserName=userName;
    Name=name;
    PhoneNumber=phoneNumber;


}

Customer::~Customer(){}

void Customer::ShowCustomerDetails()
{
    cout<<"Customer name :"<<Name<<endl;
    cout<<"Customer user name :"<<UserName<<endl;;
    cout<<"Customer contact detail :"<<PhoneNumber<<endl;
    if(SavingAccount!=nullptr)
    {
        SavingAccount->ShowAccountDetails();
    }
    if(CurrentAccount!=nullptr)
    {
        CurrentAccount->ShowAccountDetails();
    }
    
}

string Customer::GetUserName()
{
    return UserName;
}