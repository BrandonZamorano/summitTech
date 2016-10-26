/*
Name:			Brandon Zamorano
Date:			10.24.2016
Description:	Date class definition; Member fuctions define in Date.cpp
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Date.h"
using namespace std;

//default constructor that sets the date using <ctime> fuction
Date::Date()
{
	//pointer to type struct tm which hold calender time components
	struct tm ptr;
	ptr = { 0 };
	time_t t = time(0);//determine current time

	//convert current calender time pointed to by t into
	//broken down time and assign it to ptr
	//ptr = localtime(&t);

	day = ptr.tm_mday; //broken down day of the month
	month = 1 + ptr.tm_mon; //broken down month Since January
	year = ptr.tm_year + 2000;//
}

//
Date::Date(int ddd, int yyyy)
{
	year = yyyy;
	setMMDDFromDDD(ddd); //set month and day based on ddd
}

//
Date::Date(int mm, int dd, int yy)
{
	setYYYYFromYY(yy);//set 4 digit year based on yy
	setMonth(mm);//validate and set the month
	setDay(dd); //vallidate and set the day
}

//
Date::Date(string monthName, int dd, int yyyy) //constructor for using Month dd, yyy format
{
	setMMFromMonth(monthName); //set month based on month name
	setDay(dd); // validate and set the day
	year = yyyy;

}

//void for setting day
void Date::setDay(int d)
{
	day = checkDay(d);
}

//void for setting month & if else for if month is invalid
void Date::setMonth(int m)
{
	if (m > 0 && m <= 12) // validate month 
		month = m;
	else
	{
		month = 1;//invalid month set to 1
		cout << "Invalid Month (" << m << ") set to 1\n";
	}
}

// prints month day and year
void Date::print() const
{
	cout << month << '/' << day << '/' << year << endl;
}

// prints days and years (something thing year conversion)
void Date::printDDDYYYY() const
{
	cout << convertDDToDDD() << ' ' << year << endl;
}

//prints months days years
void Date::printMMDDYY() const
{
	cout << setw(2) << setfill('0') << month << '/'
		<< setw(2) << setfill('0') << day << '/'
		<< setw(2) << setfill('0') << convertYYYYtoYY() << endl;
}

//prints 1 month day 2 and 4 digit year
void Date::printMonthDDYYYY() const
{
	cout << convertMMtoMonth(month) << ' ' << day << ", " <<  year << endl;
}

//destructor 
Date::~Date()
{
	cout << "Date object destructor for date ";
	print();
	cout << endl;
}

int Date::checkDay(int testDay) const
{
	//determine whether testDay is valid for the specific month
	if (testDay > 0 && testDay <= daysInMonth(month))
		return testDay;
	//Febuary 29, check for leap year
	if (month == 2 && testDay == 29 && isLeapYear())
		return testDay;

	cout << "Invalid Day << (" << testDay << ") is to 1, \n";
	return 1;
}

int Date::daysInMonth(int m) const
{
	if (isLeapYear() && m == 2)
		return 29;

	static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return daysPerMonth[m];
}

bool Date::isLeapYear() const
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	else
		return false;
}

int Date::convertDDToDDD() const
{
	int ddd = 0;

	//for each month that has passed, add days to ddd
	for (int i = 0; i < month; i++)
		ddd += daysInMonth(i);

	//adds days from current month
	ddd += day;

	return ddd;
}

// sets and adds months and sets to days.
void Date::setMMDDFromDDD(int ddd)
{
	int dayTotal = 0;
	int m;

	for (m = 1; m <= 12 && (dayTotal + daysInMonth(m)) < ddd; m++)
		dayTotal += daysInMonth(m);

		setMonth(m);
	setDay(ddd - dayTotal);
}

//converts | tells months
string Date::convertMMtoMonth(int mm) const
{
	static const string months[] =
	{
		"", "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
	};

	return months[mm];
}

//bools for if its less than january but moer than december saying its invalid month
void Date::setMMFromMonth(string m)
{
	bool matchFound = false;

	//loop for each month, checking for a match
	for (int x = 1; x <= 12 && !matchFound; x++)
	{
		string tempMonth = convertMMtoMonth(x);

		if (tempMonth == m)
		{
			setMonth(x);
			matchFound = true;
		}
	}


	if (!matchFound)
	{
		cout << "Invalid Month Name (" << month << "). month set to 1. \n";
		setMonth(1);//leave objective in consistant state if bad value

	}
}

// converts 4 digit year to 2 digit year
int Date::convertYYYYtoYY() const
{
	//if year is in 1900's subtract 1900
	//else assume year is in the 2016 and subtract 2016
	return (year >= 2016 ? year - 2016 : year - 1900);
}

// sets date or converts if greater or less than 2016 and or 1900's
void Date::setYYYYFromYY(int yy)
{
	//if yy is less than 16, assume its in the 2000's
	//if yy is greater than or equal too 16, assume it is in the 1900's
	year = (yy <= 16 ? yy + 2016 : yy + 1900);
}

/*
void printMonthDDYYYY() const; //print date in Month, dd, yyyy format
*/