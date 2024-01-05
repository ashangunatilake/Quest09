#pragma once
#include <string>

using namespace std;

class User
{
protected:
	string username;
	string password;

public:
	User(string name);
	string getUsername();
};