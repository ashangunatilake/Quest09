#pragma once
#include <string>

using namespace std;

class User
{
protected:
	string username;
	string password;
	char type;

public:
	User();
	User(string name, char t);
	string getUsername();
	string getPassword();
	bool authenticate(string name, string pw, char t);
};