#include <iostream>

using namespace std;

#ifndef MYTIME_H
#define MYTIME_H
//---------------------------------------
//1. Реалізувати клас Time
//
//2. Реалізувати таймер, який вмикається
//вибраного дня (клас Date) в заданий час
//і подає сигнал через заданий інтервал
//часу після вмикання
//---------------------------------------
class MyTime
{
private:
	int _hours;
	int _minutes;
	int _seconds;
	//Функція службова, а тому закрита
	void normalizeTime();
public:
	static const double hourToDec;
	MyTime (int s=0, int m=0, int h=0);
	MyTime (const MyTime&);
	~MyTime(){};
	MyTime& operator=(const MyTime&);
	operator int() const;
	operator double() const;
	int hours() const {return _hours;}
	int minutes() const {return _minutes;}
	int seconds() const {return _seconds;}
	int& hours() {return _hours;}
	int& minutes() {return _minutes;}
	int& seconds() {return _seconds;}
	//Зміна часового проміжку на одну секунду
	const MyTime& operator++();
	const MyTime operator++(int);
	const MyTime& operator--();
	const MyTime operator--(int);

	bool isZero() const;

	//Додаваннячасових проміжків
	MyTime operator+(const MyTime& t) const;
};

ostream& operator<<(ostream&, const MyTime &);

#endif