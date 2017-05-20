#include <string>

using namespace std;

#ifndef MYDATE_H
#define MYDATE_H

//*******************************************
//    Lab task 5
//    Developed by Savenkov Oleksii
//    at Software Engineering
//    Version ....................
//*******************************************

class MyDate
{
public:
struct BadDate;
// to avoid problem 7.2.2002 7 feb or jul 2?
enum Month {jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
MyDate ( int d=0, Month m=Month(0), int y=0);
MyDate ( int d, int m, int y);
MyDate (const MyDate&);
~MyDate();
int day() const;
Month month() const;
int year() const;
const string getMonthName() const;
void setDay(int);
void setMonth(int);
void setYear(int);
static void setDefault(int,Month,int);
static void setDefault();
static void showDefault();
const MyDate& operator++();
const MyDate  operator++(int);
const MyDate& operator--();
const MyDate  operator--(int);
private:
int _day, _month, _year;
bool leapYear(int y);
int maxDayByMY(Month m, int y);
void fillDate(int d, Month m, int y);
static string monthNames [12];
static bool defaultSet;
static MyDate defaultDate;
};
ostream& operator<<(ostream& os, const MyDate & d);
struct MyDate::BadDate
{
int _day, _month, _year;
BadDate(int d, int m, int y):_day(d), _month(m), _year(y){};
};
ostream& operator<<(ostream& os, const MyDate::BadDate & bd);

#endif