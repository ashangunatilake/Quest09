#include "User.h"
#include <string>

using namespace std;
User::User() {}

User::User(string name, char t, string c_number)
{
	username = name;
	password = "Password@1234";
	contact_number = c_number;
	type = t;
}

string User::getUsername()
{
	return username;
}

string User::getContactNumber()
{
	return contact_number;
}

string User::getPassword()
{
	return password;
}