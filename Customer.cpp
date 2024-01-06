#include "Customer.h"
#include <fstream>
#include <iostream>

Customer::Customer(string name, string c_number) : User(name, 'C', c_number)
{
    saving_account = NULL;
    current_account = NULL;
    overdraft_charges = 0;
}

Customer::~Customer(){}

SavingAccount* Customer::getSavingAccount()
{
    return saving_account;
}

void Customer::setSavingAccount(SavingAccount* account)
{
    saving_account = account;
}

CurrentAccount* Customer::getCurrentAccount()
{
    return current_account;
}

void Customer::setCurrentAccount(CurrentAccount* account)
{
    current_account = account;
}

double Customer::getOverdraftCharges()
{
    return overdraft_charges;
}

vector<Transaction*>* Customer::getTransactions()
{
    return &transactions;
}

void Customer::setOverdraftCharges(double overdraft)
{
    overdraft_charges = overdraft;
}

void  Customer::writeTransaction(Transaction* transaction)
{
    //// Generate a timestamp for the transaction
    //time_t now = time(0);
    //tm* timePtr = localtime(&now);
    //int year = 1900 + timePtr->tm_year;
    //int month = 1 + timePtr->tm_mon;
    //int day = timePtr->tm_mday;

    // Open a file in append mode
    ofstream transactionFile;
    transactionFile.open("Transactions/" + username + "_transactions.txt", ios::app);

    if (transactionFile.is_open())
    {
        // Write transaction details to the file
        //transactionFile << "Date: " << day << "/" << month << "/" << year << "\n";
        transactionFile << "Date: " << transaction->date << "\n";
        transactionFile << "Type: " << transaction->type << "\n";
        transactionFile << "Amount: " << transaction->amount << "\n";
        transactionFile << "Sender's Account Number: " << transaction->senders_account_number << "\n";
        transactionFile << "Balance: " << transaction->balance << "\n\n";

        // Close the file
        transactionFile.close();
        cout << "Transaction written to file." << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

void  Customer::viewTransactions()
{
    ifstream transactionFile("Transactions/"+ username + "_transactions.txt");

    if (transactionFile.is_open())
    {
        string line;
        if (!getline(transactionFile, line))
        {
            cout << "No transactions found for this customer." << endl;
            return;
        }

        while (getline(transactionFile, line))
        {
            cout << line << endl;
        }

        transactionFile.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}
