#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class movieAccount
{
public:
	void setData(string name, string sub, double bal, int numMovies, bool checkOut);
	void print() const; // will print out account details
	void checkMovie(string movieName); // will allow the user to add a movie to the user's movie list vector
	void returnMovie(string movieName);// will allow the user to return/remove a movie from their movie list vector
	string getAccountName() const;// will return the user's account name
	string getSubType() const;// will return the user's subscription type
	void setSubType(string sub);
	double getBalance() const;// will return the user's balance
	void addBalance(double amt);
	int getNoOfMovies() const;// will return the number of movies the user has or is allowed to check out based on sub type
	bool getCanCheckout() const;// will return true/false if the user is allowed to checkout more movies
	int getAccountNumber() const;//will return the user's account number
	vector<string> getMovieList() const;

	movieAccount(string name = " ", string sub = " ", double bal = 0.0, int numMovies = 0, bool checkOut = true);


private:
	static int num;
	string accountName = " ";
	string subscription = " ";
	int accountNumber = 0;
	int noOfMovies = 0;
	double balance = 0.0;
	bool canCheckOut = false;
	vector<string> myMovies;

	/*
	enum subscription { BASIC, STANDARD, PREMIUM };
	subscription accountSubscription = */

};