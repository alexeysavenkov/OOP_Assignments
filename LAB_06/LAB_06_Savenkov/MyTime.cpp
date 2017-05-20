#include "MyTime.h"

void MyTime::normalizeTime() {
	if(this->_seconds < 0) {
		this->_minutes--;
		this->_seconds += 60;
	}
	if(this->_minutes < 0) {
		this->_hours--;
		this->_minutes += 60;
	}
	if(this->_seconds >= 60) {
		this->_minutes += this->_seconds / 60;
		this->_seconds %= 60;
	}
	if(this->_minutes >= 60) {
		this->_hours += this->_minutes / 60;
		this->_minutes %= 60;
	}
}

MyTime::MyTime (int s, int m, int h) {
	this->_seconds = s;
	this->_minutes = m;
	this->_hours = h;
	this->normalizeTime();
}

MyTime::MyTime (const MyTime& t) {
	this->_seconds = t._seconds;
	this->_minutes = t._minutes;
	this->_hours = t._hours;
	this->normalizeTime();
}

MyTime& MyTime::operator=(const MyTime& t) {
	return *this = MyTime(t);
}

MyTime::operator int() const {
	return 3600*this->_hours + 60*this->_minutes + this->_seconds;
}

MyTime::operator double() const {
	return (int) this;
}

const MyTime& MyTime::operator++() {
	this->_seconds++;
	this->normalizeTime();
	return *this;
}
const MyTime MyTime::operator++(int) {
	return ++(*this);
}
const MyTime& MyTime::operator--() {
	if(this->isZero())
		throw "Cannot decrement zero time";
	this->_seconds--;
	this->normalizeTime();
	return *this;
}
const MyTime MyTime::operator--(int) {
	return --(*this);
}

bool MyTime::isZero() const {
	return !(this->_hours || this->_minutes || this->_seconds);
}

MyTime MyTime::operator+(const MyTime& t) const {
	return MyTime(this->_seconds + t._seconds, this->_minutes + t._minutes, this->_hours + t._hours);
}

ostream& operator<<(ostream& out, const MyTime &t) {
	if(t.hours())
		out << t.hours() << " hours ";
	if(t.minutes())
		out << t.minutes() << " minutes ";
	out << t.seconds() << " seconds ";
	return out;
}