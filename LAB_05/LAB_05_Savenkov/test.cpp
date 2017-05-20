#include "Date.h"
#include <iostream>
#include <process.h>

//*******************************************
//    Lab task 5
//    Developed by Savenkov Oleksii
//    at Software Engineering
//    Version ....................
//******************************************* 

int main() {

	Date dt = Date(1, 1, 2000);

	cout << "DATE 1: " << dt << endl;

	dt--;
	cout << "DEC DATE 1: " << dt << endl;

	try {
		dt.setMonth(2);
	} catch (Date::BadDate badDate) {
		cout << "Error when trying to set 31 Feb: " << badDate << endl;
	}

	++dt;
	cout << "DATE 1: " << dt << endl;

	Date::setDefault(5, (Date::Month)5, 1995);
	Date::showDefault();

	Date defaultDate;
	cout << "Default date test: " << defaultDate << endl;

	system("pause");

	return 0;
}