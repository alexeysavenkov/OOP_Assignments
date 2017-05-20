#include <time.h>
#include "Timer.h"
#include <iostream>

void Timer::updateEverySecond() {
	if(this->isFinished())
		return;

	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	if(!this->isEnabled()) {
		if(
			aTime->tm_mday == this->_date.day() &&
			aTime->tm_mon + 1 == (int)this->_date.month() &&
			aTime->tm_year + 1900 == this->_date.year()
		) {
			this->_isEnabled = true;
			cout << "Timer enabled" << endl;
		}
	} else {
		if(this->_time.isZero()) {
			cout << "Timer finished" << endl;
			this->_isFinished = true;
		} else {
			cout << "Time left: " << this->_time-- << endl;
		}
	}
}

bool Timer::isEnabled() const {
	return this->_isEnabled;
}

bool Timer::isFinished() const {
	return this->_isFinished;
}