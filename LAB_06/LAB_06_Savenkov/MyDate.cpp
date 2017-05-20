#include <iostream>
#include "MyDate.h"

//*******************************************
//    Lab task 5
//    Developed by Savenkov Oleksii
//    at Software Engineering
//    Version ....................
//******************************************* 

MyDate::MyDate ( int d, Month m, int y) {
	this->fillDate(d, m, y);
}
MyDate::MyDate ( int d, int m, int y) {
	this->fillDate(d, (Month)m, y);
}
MyDate::MyDate (const MyDate& dt) {
	this->_day = dt._day;
	this->_month = dt._month;
	this->_year = dt._year;
}
MyDate::~MyDate() {}
int MyDate::day() const {
	return this->_day;
}
MyDate::Month MyDate::month() const {
	return (Month)this->_month;
}
int MyDate::year() const {
	return this->_year;
}
const string MyDate::getMonthName() const {
	return monthNames[this->_month - 1];
}

void MyDate::setDay(int d) {
	this->fillDate(d, (Month)this->_month, this->_year);
}
void MyDate::setMonth(int m) {
	this->fillDate(this->_day, (Month)m, this->_year);
}
void MyDate::setYear(int y) {
	this->fillDate(this->_day, (Month)this->_month, y);
}

void MyDate::setDefault(int d,Month m,int y) {
	defaultDate = MyDate(d, m, y);
	defaultSet = true;
}
void MyDate::setDefault() {
	defaultSet = false;
}
void MyDate::showDefault() {
	if(defaultSet)
		cout << "Default date: " << defaultDate << endl;
	else
		cout << "Default date is not set" << endl;
}

const MyDate& MyDate::operator++() {
	this->_day++;
	if(this->maxDayByMY((Month)(this->_month), this->_year) < this->_day) {
		this->_day = 1;
		if(this->_month == 12) {
			this->_month = 1;
			this->_year++;
		} else {
			this->_month++;
		}
	}
	return *this;
}
const MyDate  MyDate::operator++(int) {
	return ++(*this);
}
const MyDate& MyDate::operator--() {
	this->_day--;
	if(this->_day == 0) {
		if(this->_month == 1) {
			this->_month = 12;
			this->_year--;
		} else {
			this->_month--;
		}
		this->_day = this->maxDayByMY((Month)this->_month, this->_year);
	}
	return *this;
}
const MyDate  MyDate::operator--(int) {
	return --(*this);
}

bool MyDate::leapYear(int y) {
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

void MyDate::fillDate(int d, Month m, int y) {
	if(defaultSet) {
		if(d == 0)
			d = defaultDate.day();
		if(m == 0)
			m = defaultDate.month();
		if(y == 0)
			y = defaultDate.year();
	}

	bool isGood = m > 0 && m < 12 && d > 0 && d < maxDayByMY(m, y);

	if(!isGood) {
		throw BadDate(d, m, y);
	}

	this->_day = d;
	this->_month = m;
	this->_year = y;
}

int MyDate::maxDayByMY(Month m, int y) {
	switch(m) {
	case jan:
	case mar:
	case may:
	case jul:
	case aug:
	case oct:
	case dec:
		return 31;
	case apr:
	case jun:
	case sep:
	case nov:
		return 30;
	case feb:
		return this->leapYear(y) ? 29 : 28;
	default:
		return -1;
	}
}

string MyDate::monthNames[12] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

bool MyDate::defaultSet = false;

MyDate MyDate::defaultDate = MyDate(1,1,0);

ostream& operator<<(ostream& os, const MyDate & d) {
	return os << d.day() << ' ' << d.getMonthName() << ' ' << d.year();
}

ostream& operator<<(ostream& os, const MyDate::BadDate & d) {
	return os << "BAD DATE: d" << d._day << " m" << d._month << " y" << d._year;
}