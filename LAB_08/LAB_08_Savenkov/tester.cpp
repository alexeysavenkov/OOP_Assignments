#include "Screen.h"
#include <process.h>

int main() {
	char filler = 'X';
	Screen screen(10, 5, &filler);

	screen.show();

	ConstAction moveAction = &Screen::move;

	doActionConst(screen, moveAction, 15);

	screen.set('B');

	NonConstAction showAction = &Screen::show;

	doActionNonConst(screen, showAction, 1);

	screen.clear();
	screen.move(3, 2);
	screen.set('A');
	screen.show();

	system("pause");

	return 0;
}