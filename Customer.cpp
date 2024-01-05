#include "Customer.h"
#include <iostream>

Customer::Customer(string name) : User(name)
{
    saving_account = NULL;
    current_account = NULL;
}

Customer::~Customer(){}

SavingAccount* Customer::getSavingAccount()
{
    return saving_account;
}
CurrentAccount* Customer::getCurrentAccount()
{
    return current_account;
}

//void Customer::ShowCustomerDetails()
//{
//    cout<<"Customer name :"<<Name<<endl;
//    cout<<"Customer user name :"<<UserName<<endl;;
//    cout<<"Customer contact detail :"<<PhoneNumber<<endl;
//    if(SavingAccount!=nullptr)
//    {
//        SavingAccount->ShowAccountDetails();
//    }
//    if(CurrentAccount!=nullptr)
//    {
//        CurrentAccount->ShowAccountDetails();
//    }
//    
//}