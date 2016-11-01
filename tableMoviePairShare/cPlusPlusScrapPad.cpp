#include <iostream>
#include "movieAccount.h"
#include <fstream>
#include <iomanip>
#include <string>

/*
List of movies - list
Being Able to search for movies
Add Movies
Get rid of movies
Pick Genre
length of movie
Movie Rating

Subscription Plan

Basic Plan - $10 - SD - 5 movies
StandardPlan - $15 - HD - 15 movies
Premium Plan - $20 - Ultra HD - Unlimited movies
*/

using namespace std;

void printMovieList(vector<string> movieList)
{
	for (string item : movieList)
	{
		cout << item << endl;
	}
}

int main()
{ 
	movieAccount Brandon;
	Brandon.setSubType("Premium");
	Brandon.print();
	Brandon.checkMovie("Movie1");
	Brandon.checkMovie("Movie2");
	Brandon.checkMovie("Movie3");
	printMovieList(Brandon.getMovieList());

	return 0;
}