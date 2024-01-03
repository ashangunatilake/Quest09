#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include "Customer.h"
#include "Bank.cpp"

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

&Customer login(*Bank bank)
{
	string userName;
	string password;
	cout << "Username : ";
	cin >> userName;
	cout << "Password : ";
	password = hidePassword();
	for (int i = 0; i < bank->accounts.size(); i++)
	{
		if (bank->accounts[i]->)
	}
}

int main()
{
	bool exit = false;
	



	while (!exit)
	{

	}
	return 0;
}