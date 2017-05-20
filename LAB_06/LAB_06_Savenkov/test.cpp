#include "Timer.h"
#include "MyTime.h"
#include "MyDate.h"
#include <Windows.h>

void main() {
	Timer timer(MyDate(5, 3, 2017), MyTime(3, 0, 0));

	while(true) {
		Sleep(1000);
		timer.updateEverySecond();
		//if(timer.isFinished())
			//break;
	}
}