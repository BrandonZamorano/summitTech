#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printSubscriptionPlans();
void mainMenu(string& name, double& initialAmount);

int main()
{
	string name;
	double initialAmount;
	mainMenu(name, initialAmount);
}

void mainMenu(string& name, double& initialAmount)
{
	string firstName;
	string lastName;
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << endl;
	cout << "Enter your last name: ";
	cin >> lastName;
	cout << endl;
	name = firstName + " " + lastName;
	cout << "Welcome, " << name << ", to our crappy netflix knock-off!" << endl <<endl;
	cout << "We need to set up your account first." << endl << endl;
	cout << "To get started, you need to add to your balance and purchase a subscription plan."<< endl << endl;
	cout << "Here are the subscription plans we offer: " << endl << endl;
	printSubscriptionPlans(); // prints out the subscription plans
	cout << "Enter amount to add to balance: $";
	cin >> initialAmount;
}

void printSubscriptionPlans()
{
	string subscriptions[3][4] =
	{
		{ "Basic", "10", "SD", "5" },
		{ "Standard", "15", "HD", "15" },
		{ "Premium", "20", "UHD", "Unlimited" }

	};

	for (int row = 0; row < 3; row++)
	{
		cout << subscriptions[row][0] << " $" << subscriptions[row][1] << " " << subscriptions[row][2]
			<< " " << subscriptions[row][3] << endl;
		cout << setw(subscriptions[row][0].length() + 3 + subscriptions[row][2].length() + 3 + subscriptions[row][3].length()) << setfill('-') << "-" << endl;
		cout << endl;
	}
}