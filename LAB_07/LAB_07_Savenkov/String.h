#include <string>

using namespace std;

//Доповнити наведену нижче специфікаію до власного класу рядків String,
//забезпечивши можливість виконання змішаних операцій
//над власними рядками, С-рядками і STL-рядками
class String
{
private:
	size_t _len;
	char* _allocator;
public:
	class BadString {};
	class BadIndex {};
	String();
	explicit String(const char*);
	String(const char);
	explicit String(const string&);
	String(const String & s, int multiplayer = 1);
	~String();
	String& operator=(const String&);
	String& operator=(const string&);
	String& operator=(const char*);
	String& operator=(const char);
	const string STL_string() const;
	const char* c_str() const;
	size_t length() const;
	bool empty() const;
	void clear();
	char& operator[](size_t);
	const char operator[](size_t) const;
	bool operator ==(const String&) const;
	bool operator !=(const String&) const;
	bool operator < (const String&) const;
	bool operator <=(const String&) const;
	bool operator > (const String&) const;
	bool operator >=(const String&) const;
	String operator+(const String&) const;
	String& operator +=(const char*);
	String& operator +=(const String&);
	String& operator +=(const string&);
};
ostream& operator<<(ostream&, const String&);