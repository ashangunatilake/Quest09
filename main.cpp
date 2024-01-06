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
	ifstream file("users.txt");
	string name;
	string pw;
	char t;
	if (!file.is_open()) {
		cerr << "Error opening the file!" << endl;
		return;
	}
	string line;
	while (getline(file, line))
	{
		istringstream iss(line);
		iss >> name >> pw >> t;
		if (t == 'E')
		{
			Employee* employee = new Employee(name);
			bank.employees.push_back(employee);
		}
		if (t == 'C')
		{
			Customer* customer = new Customer(name);
			bank.customers.push_back(customer);
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
			//system("CLS");
			cout << "Functions : \n1. Add Employee\n2. Increase date\n3. Set interest rate\n4. Set overdraft charge\n5. Log out\n" << endl;
			cout << "Enter choice - ";
			cin >> num2;
			if (num2 == 1)
			{
				string number = "employee00" + to_string(bank.employees.size() + 1);
				admin.addEmployee(bank, number);
				ofstream file("users.txt", ios::app);
				file << bank.employees[bank.employees.size() - 1]->getUsername() << " " << bank.employees[bank.employees.size() - 1]->getPassword() << " " << "E" << endl;
				cout << bank.employees[2]->getUsername() << endl;
				file.close();
			}
			else if (num == 2)
			{
				admin.increaseDate(bank);
				cout << bank.current_date << endl;
			}
		} while (loggedIn);
	}
		
	
	return 0;
}