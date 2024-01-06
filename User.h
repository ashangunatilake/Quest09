#pragma once
#include <string>

using namespace std;

class User
{
protected:
	string username;
	string password;
	string contact_number;
	char type;

public:
	User();
	User(string name, char t, string c_number);
	string getUsername();
	string getContactNumber();
	string getPassword();
};