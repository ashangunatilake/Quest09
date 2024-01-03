#include <string>
#include "Bank.cpp"

using namespace std;

class Administrator: public User
{
public:
	Administrator(string username, string password): User(username, password) {}
	
	void addEmployee(string name)
	{
		Bank.employees.push_back(Employee(employee_name));
	}

	void increaseDate()
	{
		Bank.current_date++;
	}

	void setAnnualSavingInterest(double rate)
	{
		Bank.annual_saving_rate = rate;
	}

	void addDailyInterest(double rate)
	{
		for (const auto& a : Bank.saving_accounts)
		{
			a.amount = a.amount + a.amount * rate;
		}
	}

	void setOverdraftCharge(double charge)
	{
		Bank.overdraft_charge = charge;
	}
};