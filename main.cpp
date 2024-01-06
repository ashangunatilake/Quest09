#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "Account.h"
#include "Administrator.h"
#include "Bank.h"
#include "CurrentAccount.h"
#include "Customer.h"
#include "Employee.h"
#include "SavingAccount.h"
#include "User.h"



using namespace std;

string hidePassword()
{
	string PW;
	char ch;
	while ((ch = _getch()) != 13) //loop until Enter key is pressed
	{
		if (ch != '\b')
		{
			PW.push_back(ch);
			cout << '*';
		}
		else if (!PW.empty())
		{
			PW.pop_back();
			cout << "\b \b";
		}
	}
	cout << endl;
	return PW;
}

void header()
{
	cout << "\t\tLMN Banking Group\n" << endl;
}

bool login(string username, string password, char type)
 {
	 ifstream file("users.txt");
	 string name;
	 string pw;
	 char t;
	 if (!file.is_open()) {
		 cerr << "Error opening the file!" << endl;
		 return false;
	 }
	 string line;
	while (getline(file, line))
	{
		istringstream iss(line);
		iss >> name >> pw >> t;
		if (username == name && password == pw && type == t)
		{
			return true;
		}
	}
	file.close();
	return false;
 }

void loadFile(Bank& bank, string userfile, string accoutfile)
{
	ifstream file(userfile);
	string name;
	string pw;
	char t;
	string number;
	if (!file.is_open()) {
		cerr << "Error opening the file!" << endl;
		return;
	}
	string line;
	while (getline(file, line))
	{
		istringstream iss(line);
		iss >> name >> pw >> t ;
		if (t == 'E')
		{
			Employee* employee = new Employee(name);
			bank.employees.push_back(employee);
		}
		if (t == 'C')
		{
			iss >> number;
			Customer* customer = new Customer(name, number);
			bank.customers.push_back(customer);
		}
	}
	file.close();

	ifstream file2(accoutfile);
	string holder;
	int an;
	double b;
	double ol;
	if (!file2.is_open()) {
		cerr << "Error opening the file!" << endl;
		return;
	}
	while (getline(file2, line))
	{
		istringstream iss(line);
		iss >> holder >> an >> b >> ol >> t;
		if (t == 'S')
		{
			SavingAccount* saving_account = new SavingAccount(holder, an, b);
			saving_account->setCustomer(bank.getCustomer(holder));
			bank.getCustomer(holder)->setSavingAccount(saving_account);
		}
		if (t == 'C')
		{
			CurrentAccount* current_account = new CurrentAccount(holder, an, b, ol);
			current_account->setCustomer(bank.getCustomer(holder));
			bank.getCustomer(holder)->setCurrentAccount(current_account);
		}
	}
	file.close();
}




int main()
{
	header();
	Bank bank(1, 0.25, 1000);
	loadFile(bank, "users.txt", "accounts.txt");
	int num;
	int num2;
	bool loggedIn = false;
	cout << "1. Login - Admin\n2. Login - Employee\n3. Login- Customer\n" << endl;
	cout << "Enter choice - ";
	cin >> num;
	system("CLS");
	string userName;
	string password;
	do {
		password = "";
		cout << "Username : ";
		cin >> userName;
		cout << "Password : ";
		password = hidePassword();
		if (num == 1)
		{
			loggedIn = login(userName, password, 'A');
			if (!loggedIn)
			{
				cout << "Incorrect username or password" << endl;
			}
		}
		else if (num == 2)
		{
			loggedIn = login(userName, password, 'E');
			if (!loggedIn)
			{
				cout << "Incorrect username or password" << endl;
			}
		}
		else if (num == 3)
		{
			loggedIn = login(userName, password, 'C');
			if (!loggedIn)
			{
				cout << "Incorrect username or password" << endl;
			}
		}
		else
		{
			cout << "Invalid input" << endl;
			return 1;
		} 
	} while (!loggedIn);
	system("CLS");
	if (num == 1)
	{
		Administrator admin;
		do
		{
			system("CLS");
			cout << "Functions : \n1. Add Employee\n2. Increase date\n3. Set interest rate\n4. Set overdraft charge\n5. Log out\n" << endl;
			cout << "Enter choice - ";
			cin >> num2;
			if (num2 == 1)
			{
				string number = "employee00" + to_string(bank.employees.size() + 1);
				admin.addEmployee(bank, number);
				ofstream file("users.txt", ios::app);
				file << bank.employees[bank.employees.size() - 1]->getUsername() << " " << bank.employees[bank.employees.size() - 1]->getPassword() << " " << "E" << endl;
				file.close();
				cout << "Employee added" << endl;
				cout << "Press Enter";
				cin.get();
				cin.get();
			}
			else if (num2 == 2)
			{
				admin.increaseDate(bank);
				cout << "Current date - " << bank.current_date << endl;
				cout << "Press Enter";
				cin.get();
				cin.get();
			}
			else if (num2 == 3)
			{
				double rate;
				cout << "Enter annual savings rate (in decimal format) - ";
				cin >> rate;
				admin.setAnnualSavingInterest(bank, rate);
				cout << "Savings rate set to " << rate << endl;
				cout << "Press Enter";
				cin.get();
				cin.get();
			}
			else if (num2 == 4)
			{
				double charge;
				cout << "Enter overdraft charge - ";
				cin >> charge;
				admin.setOverdraftCharge(bank, charge);
				cout << "Overdraft charge set to " << charge << endl;
				cout << "Press Enter";
				cin.get();
				cin.get();
			}
			else if (num2 == 5)
			{
				loggedIn = false;
				cout << "Successfully logged out" << endl;
				cout << "Press Enter";
				cin.get();
				cin.get();
			}
		} while (loggedIn);

	}
	if (num == 2)
	{
		Employee employee(userName);
		do
		{
			system("CLS");
			cout << "Functions : \n1. Add Customer\n2. Create Savings Account\n3. Set Current Account\n4. Close account\n5. Deposit money\n6. Withdraw money\n7. View transactions\n" << endl;
			cout << "Enter choice - ";
			cin >> num2;
			if (num2 == 1)
			{
				string contact;
				cout << "Enter contact number - ";
				cin >> contact;
				string number = "customer00" + to_string(bank.customers.size() + 1);
				employee.addCustomer(bank, number, contact);
				ofstream file("users.txt", ios::app);
				file << bank.customers[bank.customers.size() - 1]->getUsername() << " " << bank.employees[bank.customers.size() - 1]->getPassword() << " " << "C" << " " << contact << endl;
				file.close();
				cout << "Customer added" << endl;
				cout << "Press Enter";
				cin.get();
				cin.get();
			}
			else if (num2 == 2)
			{
				string name;
				cout << "Enter customer User Name - ";
				cin >> name;
				if (bank.getCustomer(name) == NULL)
				{
					cout << "Customer not found" << endl;
					cout << "Press Enter";
					cin.get();
					cin.get();
					continue;
				}
				employee.createSavingAccount(bank, name);
				bank.saving_accounts[bank.saving_accounts.size() - 1]->setCustomer(bank.getCustomer(name));
				cout << bank.saving_accounts[bank.saving_accounts.size() - 1]->getAccountNumber() << endl;
				ofstream file("accounts.txt", ios::app);
				file << bank.saving_accounts[bank.saving_accounts.size() - 1]->getCustomer()->getUsername()<< " " << bank.saving_accounts[bank.saving_accounts.size() - 1]->getAccountNumber() << " " << bank.saving_accounts[bank.saving_accounts.size() - 1]->getBalance() << " " << "S" << endl;
				file.close();
				cout << "Account successfully created" << endl;
				cout << "Press Enter";
				cin.get();
				cin.get();
			}
			else if (num2 == 3)
			{
				string name;
				cout << "Enter customer User Name - ";
				cin >> name;
				if (bank.getCustomer(name) == NULL)
				{
					cout << "Customer not found" << endl;
					cout << "Press Enter";
					cin.get();
					cin.get();
					continue;
				}
				double value;
				cout << "Enter overdraft value - ";
				cin >> value;
				employee.createCurrentAccount(bank, name, value);
				bank.current_accounts[bank.current_accounts.size() - 1]->setCustomer(bank.getCustomer(name));
				cout << bank.current_accounts[bank.current_accounts.size() - 1]->getAccountNumber() << endl;
				ofstream file("accounts.txt", ios::app);
				file << bank.current_accounts[bank.current_accounts.size() - 1]->getCustomer()->getUsername() << " " << bank.current_accounts[bank.current_accounts.size() - 1]->getAccountNumber() << " " << bank.current_accounts[bank.current_accounts.size() - 1]->getBalance() << " " << "C" << endl;
				file.close();
				cout << "Account successfully created" << endl;
				cout << "Press Enter";
				cin.get();
				cin.get();
			}
			else if (num2 == 4)
			{
				int num;
				cout << "Enter account number - ";
				cin >> num;
				employee.closeCustomerAccount(bank, num);
			}
		} while (loggedIn);

	}
	
	return 0;
}