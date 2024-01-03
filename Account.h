#include <string>;
#include <list>;
#include "Customer.h";
using namespace std;

class Account{
    private:
     Customer* AccountHolder;
     string AccountNumber;
     float AccountBalance;
     list<string> AccountHistory={};
     Bool IsSavingAccount;
      
    public:
      void ShowAccountFullDetails();
      void deposit(float dep);
      void withdrow();
      void ShowAccountDetails();

};