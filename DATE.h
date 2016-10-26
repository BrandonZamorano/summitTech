/*
Name:			Brandon Zamorano
Date:			10.24.2016
Description:	Date class definition; Member fuctions define in Date.cpp
*/
#ifndef  DATE_H
#define  DATE_H

#include <string>
using namespace std;

class Date
{
	public:
		Date(); // default constructor uses <ctime> fuctions to set date
		Date(int, int); // constructor using ddd yyyy format
		Date(int, int, int); //constructor using dd/mm/yy format
		Date(string, int, int); //constructor for using Month dd, yyy format
		void setDay(int); //set the day
		void setMonth(int); //set the month
		void print() const; //print date in the month/day/year format
		void printDDDYYYY() const; //print date in ddd yyyy format
		void printMMDDYY() const;//print date in mm/dd/yy format
		void printMonthDDYYYY() const; //print date in Month, dd, yyyy format
		~Date();//destruction

	private:
		int month; //1-12 (January-December)
		int day; //1-31 based on month
		int year; //doesnt matter

		//utility fuctions'
		int checkDay(int) const;//check if day is proper for the month and year
		int daysInMonth(int) const; //returns number of days in given month
		bool isLeapYear() const; //indicates whether date is in a leap year
		int convertDDToDDD() const; //get 3-digit day based on month and a day
		void setMMDDFromDDD(int); //set 3-digit days based on month and day
		string convertMMtoMonth(int) const; //
		void setMMFromMonth(string); //convert month name to mm
		int convertYYYYtoYY() const; //get 2 digit year based on 4 diget year
		void setYYYYFromYY(int); //set year based on 2 digit year


};

#endif
