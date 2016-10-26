#include <iostream>
#include <ctime>
#include <iomanip>
#include "Date.h"

using namespace std;


Date::Date()
{
	//pointer to type struct tm which hold calender time components
	struct tm*ptr;
	time_t t = time(0); //determind current time

	//convert current calender time pointed to by t into 
	//broken down time and assign it to ptr
	ptr = localtime(&t);
	
	day = ptr->tm_mday; //broken down doay of the month 
	month = 1 + ptr->tm_mon; //broken down month since January
	year = ptr->tm_year + 2000;


}
Date::Date(int ddd, int yyyy)
{
	year = yyyy;
	setMMDDFromDDD(ddd); //set mnoth and day based on ddd
}

Date::Date(int mm, int dd, int yy)
{
	setYYYFromYY(yy); //set 4 digit year based on yy
	setMonth(mm); //validate and set the month 
	setDay(dd); //validate and set the date
}
Date::Date(string monthName, int dd, int yyyy)
{
	setMMFromMonth(monthName); //set month based on month name
	setDay(dd); //validate and set the date
	year =yyyy;
}

void Date::setDay(int d)
{
	day = checkDay(d);
}

void Date::setMonth(int m)
{
	if (m > 0 && m <= 12)
		month = m;
	else
	{
		month = 1; 
		cout << "Invalid month(" << m << ")set to 1\n";
	}
}

void Date::print()const
{
	cout << month << '/' << day << '/' << year << endl;
}

void Date::printDDDYYYY() const
{
	cout << convertDDToDDD() << ' ' << year << endl;
}

void Date::printMMDDYY() const
{
	cout << setw(2) << setfill('0') << month << '/'
		<< setw(2) << setfill('0') << day << '/'
		<< setw(2) << setfill('0') << convertYYYYToYY() << endl;
}

void Date::printMonthDDYYYY()const
{
	cout << convertMMToMonth(month) << ' ' << day << ", " << year << endl;
}
