#include "User.h"
#include <string>

using namespace std;

User::User(string name)
{
	username = name;
	password = "Password@1234";
}

string User::getUsername()
{
	return username;
}
