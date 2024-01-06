#include "User.h"
#include <string>

using namespace std;

User::User(string name, string c_number)
{
	username = name;
	password = "Password@1234";
	contact_number = c_number;
}

string User::getUsername()
{
	return username;
}

string User::getContactNumber()
{
	return contact_number;
}
