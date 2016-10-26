/*
Brandon Zamorano
Today
Date class definiton; member functions defined in date.cpp
*/

#ifndef DATE_H
#define DATE_H 

#include <string>
using namespace std;

class Date
{
	public:
		Date();//default constructor uses <ctime>
		Date(int, int); //constructor
		Date(int, int, int); //constructor using dd/mm/yy
		Date(string, int, int); //constructor for using month dd, yyyy, format
		void setDay(int); //sets the day
		void setMonth(int);//set the month
		void print() const; //print date in the month/day/year format
		void printDDDYYYY()const; //print date in ddd yyyy dormat
		void printMMDDYY() const; //pring date in month mm.dd,yyyy format
		void printMonthDDYYYY() const; //pprint date in month dd,yyyy format
		~Date();

	private:
		int month;// 1-12 (January- December)
		int day; //1-31 based on month
		int year; //year

		//utility functions
		int checkDay(int) const; //check if day is propter for the month and year
		int daysInMonth(int)const; //returns number of days in given month
		bool isLeapYear() const; //indicates whether date is in leap year 
		int convertDDToDDD(int); //get 3 digit date based on month and day
		void setMMDDFromDDD(int); //set 3 didgit days based on month and day
		string convertMMToMonth(int) const; //get 2 digit year based on 4 digit year
		void setMMFromMonth(string); //conver month name to MM
		int convertYYYYToYY() const; //gets 2 digit year based on 4 digit year
		void setYYYFromYY(int); //set year based on 2 digit year

		
};

#endif




