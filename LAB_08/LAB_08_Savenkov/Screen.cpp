
#include "Screen.h"
#include <string.h>

const int Screen::maxWidth = 20;
const int Screen::maxHeight = 20;
const char Screen::_filler = ' ';

Screen::Screen(int w, int h, char* pc) {
	this->_width = w;
	this->_height = h;
	this->_wContent = new char[w*h];

	char filler = pc ? *pc : this->_filler;
	memset(this->_wContent, filler, w*h);
	
	this->home();
}

Screen::~Screen() {
	delete[] this->_wContent;
}

const Screen& Screen::home() const {
	this->_cursor = 0;
	return *this;
}

Screen& Screen::home() {
	this->_cursor = 0;
	return *this;
}

const Screen& Screen::move() const {
	this->_cursor++;
	this->_cursor %= this->_width * this->_height;
	return *this;
}
Screen& Screen::move() {
	this->_cursor++;
	this->_cursor %= this->_width * this->_height;
	return *this;
}
	//Посунути курсор на один символ вліво
const Screen& Screen::back() const {
	this->_cursor--;
	this->_cursor += this->_width * this->_height;
	this->_cursor %= this->_width * this->_height;
	return *this;
}
Screen& Screen::back() {
	this->_cursor--;
	this->_cursor += this->_width * this->_height;
	this->_cursor %= this->_width * this->_height;
	return *this;
}

//Показативмістекрану
const Screen& Screen::show() const {
	for(int y = 0, i = 0; y < this->_height; y++) {
		for(int x = 0; x < this->_width; x++, i++) {
			cout << this->_wContent[i];
		}
		cout << endl;
	}
	return *this;
}
Screen& Screen::show() {
	cout << *this;
	return *this;
}
	//Перенести курсор на задану позицію
const Screen& Screen::move(int x, int y) const {
	this->_cursor = y*this->_width + x;
	return *this;
}
Screen& Screen::move(int x, int y) {
	this->_cursor = y*this->_width + x;
	return *this;
}
	//Очиститиекран
Screen& Screen::clear() {
	memset(this->_wContent, this->_filler, this->_width*this->_height);
	return *this;
}

//Показати символ, на якому знаходиться курсор
const Screen& Screen::showCurrent() const {
	cout << this->_wContent[this->_cursor] << endl;
	return *this;
}
//Селектор
char Screen::get() const {
	return this->_wContent[this->_cursor];
}
//Модифікатор
Screen& Screen::set(char c) {
	this->_wContent[this->_cursor] = c;
	return *this;
}

int Screen::getHeight() const { return this->_height; }
int Screen::getWidth() const { return this->_width; }

ostream& operator<<(ostream& out, const Screen& screen) {
	screen.home();
	for(int y = 0, i = 0; y < screen.getHeight(); y++) {
		for(int x = 0; x < screen.getWidth(); x++, i++) {
			out << screen.get();
			screen.move();
		}
		out << endl;
	}
	out << endl;
	return out;
}
typedef const Screen& (Screen::* const ConstAction) () const;
typedef Screen& (Screen::* const NonConstAction) ();
void doActionConst(const Screen& s, ConstAction act, int n) {
	for(int i = 0; i < n; i++)
		(s.*act)();
}
void doActionNonConst(Screen& s, NonConstAction act, int n) {
	for(int i = 0; i < n; i++)
		(s.*act)();
}