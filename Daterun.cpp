//driver for class date

#include <iostream>

using namespace std;

#include "Date.h"

int main()
{
	Date date1(273, 1999); //initialize
	Date date2(1, 27, 99);
	Date date3("December", 20, 2000);
	Date date4;
	int x = 0;

	//print objects in default format
	date1.print();
	date2.print();
	date3.print();
	date4.print();
	cout << '\n';
	cout << '\a';

	//print objects in 'ddd yyyy' format
	date1.printDDDYYYY();
	date2.printDDDYYYY();
	date3.printDDDYYYY();
	date4.printDDDYYYY();

	//print objects in month, day, year format
	date1.printMonthDDYYYY();
	date2.printMonthDDYYYY();
	date3.printMonthDDYYYY();
	date4.printMonthDDYYYY();
	cout << endl;
	
	cin >> x;
	return 0;
}