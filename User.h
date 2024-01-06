#pragma once
#include <string>

using namespace std;

class User
{
protected:
	string username;
	string password;
	string contact_number;

public:
	User(string name, string c_number);
	string getUsername();
	string getContactNumber();
};