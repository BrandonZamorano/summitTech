#include <iostream>
#include <iomanip>
#include <string>
#include "movieAccount.h"

using namespace std;

int movieAccount::num = 100; // account numbers will start at 100

void movieAccount::setData(string name, string sub, double bal, int numMovies, bool checkOut)
{
	num = num + 100;
	accountName = name;
	subscription = sub;
	balance = bal;
	noOfMovies = numMovies;
	canCheckOut = checkOut;
}

void movieAccount::print() const
{
	cout << fixed << showpoint << setprecision(2); // print out with 0's
	cout << "Account Name: " << accountName << endl;
	cout << "Subscription: " << subscription << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Balance: $" << balance << endl;
	cout << "Movies: " << myMovies.size() << endl;
	cout << "Can Check Out: " << ((canCheckOut == true) ? "True" : "False") << endl;

}

void movieAccount::checkMovie(string movieName)
{
	//will need to add a check wether the user's sub allows him to checkout another movie
	myMovies.push_back(movieName);
}

void movieAccount::returnMovie(string movieName)
{
	for (int i = 0; i <= static_cast<signed int>(myMovies.size()); i++)
	{
		if (myMovies[i] == movieName)
		{
			myMovies.erase(myMovies.begin() + i);
		}
	}

}

string movieAccount::getAccountName() const
{
	return accountName;
}

string movieAccount::getSubType() const
{
	return subscription;
}

double movieAccount::getBalance() const
{
	return balance;
}

int movieAccount::getNoOfMovies() const
{
	return noOfMovies;
}

bool movieAccount::getCanCheckout() const
{
	//will need to do stuff here to check the subscription type
	return true;
}

int movieAccount::getAccountNumber() const
{
	return accountNumber;
}

vector<string> movieAccount::getMovieList() const
{
	if (static_cast<signed int>(myMovies.size() == 0))
	{
		cout << "List is empty." << endl;
	}
	return myMovies;
}

void movieAccount::setSubType(string sub)
{
	subscription = sub;
}

void movieAccount::addBalance(double amt)
{
	balance += amt;
}

movieAccount::movieAccount(string name, string sub, double bal, int numMovies, bool checkOut)
{
	setData(name, sub, bal, numMovies, checkOut);
}