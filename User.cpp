#include "User.h"
#include <string>

using namespace std;

User::User()
{
}

User::User(string name, char t)
{
	username = name;
	password = "Password@1234";
	type = t;
}

string User::getUsername()
{
	return username;
}

string User::getPassword()
{
	return password;
}

bool User::authenticate(string name, string pw, char t)
{
	return username == name && password == pw && type == t;
}
