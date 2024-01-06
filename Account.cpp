#include "Account.h";
#include "Customer.h"

Account::Account(int number)
{
    customer = NULL;
    account_number = number;
    balance = 0;
}

Account::Account(string h, string c, int number, double b)
{
    customer = NULL;
    holder = h;
    contact_number = c;
    account_number = number;
    balance = b;
}

Account::~Account()
{

}

//void Account::ShowAccountDetails()
//{
//    cout<<"Account number :"<<AccountNumber<<endl;
//    cout<<"Account balance :"<<AccountBalance<<endl;
//    for(string delail : AccountHistory)
//    {
//        cout<<detail<<endl;
//    }
//}
//
//void Account::ShowAccountFullDetails()
//{
//    cout<<"Customer name :"<<AccountHolder->Name<<endl;
//    cout<<"Customer user name :"<<AccountHolder->UserName<<endl;;
//    Cout<<"Customer contact detail :"<<AccountHolder->PhoneNumber<<endl;
//    
//    cout<<"Account number :"<<AccountNumber<<endl;
//    cout<<"Account balance :"<<AccountBalance<<endl;
//    for(string delail : AccountHistory)
//    {
//        cout<<detail<<endl;
//    }
//}
//
//void Account::deposit(float dep)
//{
//    AccountBalance=AccountBalance+dep;
//    string k="Deposit  "+to_string(dep)+"  ";
//    AccountHistory.push_front(k)
//}
//
//void Account::withdrow(float with)
//{
//    if(IsSavingAccount==true)
//    {
//        if(AccountBalance>=with)
//        {
//            AccountBalance=AccountBalance-with;
//            string k="Withdrow  "+to_string(dep)+"  ";
//            AccountHistory.push_front(k)
//        }
//        else
//        {
//            cout<<"Error!Withdow amount grater than account balance"<<endl;
//        }
//
//    }
//    else
//    {
//        AccountBalance=AccountBalance-with;
//            string k="Withdrow  "+to_string(dep)+"  ";
//            AccountHistory.push_front(k)
//    }
//}

Customer* Account::getCustomer()
{
    return customer;
}

void Account::setCustomer(Customer* holder)
{
    customer = holder;
}

int Account::getAccountNumber()
{
    return account_number;
}

double Account::getBalance()
{
    return balance;
}

void Account::setBalance(double amount)
{
    balance = amount;
}
