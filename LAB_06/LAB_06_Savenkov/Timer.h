#include "MyDate.h"
#include "MyTime.h"

class Timer {
private:
	MyDate _date;
	MyTime _time;
	bool _isEnabled;
	bool _isFinished;
public:
	Timer(MyDate date, MyTime time) : _date(date), _time(time), _isEnabled(false), _isFinished(false) {
		this->updateEverySecond();
	}
	void updateEverySecond();
	bool isEnabled() const;;
	bool isFinished() const;
};