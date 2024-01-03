#include "Account.h";



Account::Account(number)
{
    AccountNumber = number;
}

Account::~Account(){}

void Account::ShowAccountDetails()
{
    cout<<"Account number :"<<AccountNumber<<endl;
    cout<<"Account balance :"<<AccountBalance<<endl;
    for(string delail : AccountHistory)
    {
        cout<<detail<<endl;
    }
}

void Account::ShowAccountFullDetails()
{
    cout<<"Customer name :"<<AccountHolder->Name<<endl;
    cout<<"Customer user name :"<<AccountHolder->UserName<<endl;;
    Cout<<"Customer contact detail :"<<AccountHolder->PhoneNumber<<endl;
    
    cout<<"Account number :"<<AccountNumber<<endl;
    cout<<"Account balance :"<<AccountBalance<<endl;
    for(string delail : AccountHistory)
    {
        cout<<detail<<endl;
    }
}

void Account::deposit(float dep)
{
    AccountBalance=AccountBalance+dep;
    string k="Deposit  "+to_string(dep)+"  ";
    AccountHistory.push_front(k)
}

void Account::withdrow(float with)
{
    if(IsSavingAccount==true)
    {
        if(AccountBalance>=with)
        {
            AccountBalance=AccountBalance-with;
            string k="Withdrow  "+to_string(dep)+"  ";
            AccountHistory.push_front(k)
        }
        else
        {
            cout<<"Error!Withdow amount grater than account balance"<<endl;
        }

    }
    else
    {
        AccountBalance=AccountBalance-with;
            string k="Withdrow  "+to_string(dep)+"  ";
            AccountHistory.push_front(k)
    }
}