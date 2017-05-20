//Запрограмувати меню для роботи з текстовим екраном.
//
//Текстовий екран максимальним розміром
//maxHeigh х maxWidth
//
#include <iostream>

using namespace std;

class Screen
{
public:
	//Екран заповнюється рядком pc,
	//якщо він заданий, інакше він наповнюється
	//наповнювачем _filler
	Screen(int, int, char* pc =0);
	~Screen();
	//Сталітаїмоднойменніметоди
	//Перевести курсор на початок екрану
	const Screen& home() const;
	Screen& home();
	//Посунути курсор на один символ вправо
	const Screen& move() const;
	Screen& move();
	//Посунути курсор на один символ вліво
	const Screen& back() const;
	Screen& back();
	//Показативмістекрану
	const Screen& show() const;
	Screen& show();
	//Перенести курсор на задану позицію
	const Screen& move(int, int) const;
	Screen& move(int, int);
	//Очиститиекран
	Screen& clear();
	//Показати символ, на якому знаходиться курсор
	const Screen& showCurrent() const;
	//Селектор
	char get() const;
	//Модифікатор
	Screen& set(char);

	int getHeight() const;
	int getWidth() const;
private:
	//Максимальнависотаекрану
	static const int maxHeight;
	//Максимальнаширинаекрану
	static const int maxWidth;
	//Наповнювач
	static const char _filler;
	//Фактична висота екрану
	int _height;
	//Фактична ширина екрану
	int _width;
	//Наповнення екрану
	char *_wContent;
	//Курсор
	mutable int _cursor;
	//Копіюванняекранівнепередбачене
	Screen(const Screen&);
	Screen& operator= (const Screen&);
};
ostream& operator<<(ostream&, const Screen&);
typedef const Screen& (Screen::* const ConstAction) () const;
typedef Screen& (Screen::* const NonConstAction) ();
void doActionConst(const Screen& s, ConstAction act, int n);
void doActionNonConst(Screen& s, NonConstAction act, int n);