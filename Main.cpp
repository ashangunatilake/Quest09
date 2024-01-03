#include <iostream>
#include <string>
#include <conio.h>
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

int main()
{
	string userName;
	string password;
	cout << "\t\tLMN Banking Group\n" << endl;
	cout << "Username : ";
	cin >> userName;
	cout << "Password :";
	password = hidePassword();
	cin >> password;
	cout << password;
	return 0;
}