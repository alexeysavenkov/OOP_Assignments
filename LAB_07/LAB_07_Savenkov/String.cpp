#include <string>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include "String.h"

using namespace std;


String::String() {
	this->_allocator = new char[0];
	this->_len = 0;
}
String::String(const char* a) {
	for(this->_len = 0; a[this->_len]; this->_len++)
		;
	this->_allocator = new char[this->_len];
	memcpy(this->_allocator, a, this->_len);
}
String::String(const char c) {
	this->_allocator = new char[1];
	this->_allocator[0] = c;
	this->_len = 1;
}
String::String(const string& s) {
	this->_allocator = new char[s.length()];
	this->_len = s.length();
	memcpy(this->_allocator, s.c_str(), s.length());
}
String::String(const String & s, int multiplyer) {
	if(multiplyer < 0) {
		throw BadString();
	}
	this->_len = s.length() * multiplyer;
	this->_allocator = new char[this->_len];
	for(int i = 0; i < multiplyer; i++) {
		memcpy(this->_allocator + s.length() * i, s.c_str(), s.length());
	}
}
String::~String() {
	delete[] this->_allocator;
}
String& String::operator =(const String& s) {
	delete[] this->_allocator;
	this->_allocator = new char[s.length()];
	this->_len = s.length();
	memcpy(this->_allocator, s._allocator, s._len);
	return *this;
}
String& String::operator =(const string& s) {
	delete[] this->_allocator;
	this->_allocator = new char[s.length()];
	this->_len = s.length();
	memcpy(this->_allocator, s.c_str(), s.length());
	return *this;
}
String& String::operator=(const char* a) {
	delete[] this->_allocator;
	for(this->_len = 0; a[this->_len]; this->_len++)
		;
	this->_allocator = new char[this->_len];
	memcpy(this->_allocator, a, this->_len);
	return *this;
}
String& String::operator=(const char c) {
	delete[] this->_allocator;
	this->_allocator = new char[1];
	this->_allocator[0] = c;
	this->_len = 1;
	return *this;
}
const string String::STL_string() const {
	// Using string's range copy constructor
	return string(this->_allocator, this->_allocator + this->_len);
}
const char* String::c_str() const {
	char* res = new char[this->_len + 1];
	memcpy(res, this->_allocator, this->_len);
	res[this->_len] = 0;
	return res;
}
size_t String::length() const {
	return this->_len;
}
bool String::empty() const {
	return !(this->_len);
}
void String::clear() {
	delete[] this->_allocator;
	this->_len = 0;
	this->_allocator = new char[0];
}
char& String::operator[](size_t i) {
	if(i < 0 || i >= this->_len)
		throw BadIndex();
	return this->_allocator[i];
}
const char String::operator[](size_t i) const {
	if(i < 0 || i >= this->_len)
		throw BadIndex();
	return this->_allocator[i];
}
bool String::operator ==(const String& s) const {
	if(this->_len != s._len)
		return false;
	return !memcmp(this->_allocator, s._allocator, this->_len);
}
bool String::operator !=(const String& s) const {
	return !(*this == s);
}
bool String::operator < (const String& s) const {
	for(size_t i = 0; i < this->_len && i < s._len; i++) {
		if(this->_allocator[i] != s._allocator[i])
			return this->_allocator[i] < s._allocator[i];
	}
	return this->_len < s._len;
}
bool String::operator <=(const String& s) const {
	for(size_t i = 0; i < this->_len && i < s._len; i++) {
		if(this->_allocator[i] != s._allocator[i])
			return this->_allocator[i] < s._allocator[i];
	}
	return this->_len <= s._len;
}
bool String::operator > (const String& s) const {
	return !(*this <= s);
}
bool String::operator >=(const String& s) const {
	return !(*this < s);
}
String String::operator+(const String& s) const {
	String res;
	delete[] res._allocator;
	res._len = this->_len + s._len;
	res._allocator = new char[res._len];
	memcpy(res._allocator, this->_allocator, this->_len);
	memcpy(res._allocator + this->_len, s._allocator, s._len);
	return res;
}
String& String::operator +=(const char* s) {
	char* oldstr = this->_allocator;
	int slen = strlen(s);
	this->_allocator = new char[this->_len + slen];
	memcpy(this->_allocator, oldstr, this->_len);
	memcpy(this->_allocator + this->_len, s, slen);
	delete[] oldstr;
	return *this;
}
String& String::operator +=(const String& s) {
	char* oldstr = this->_allocator;
	int slen = s._len;
	this->_allocator = new char[this->_len + slen];
	memcpy(this->_allocator, oldstr, this->_len);
	memcpy(this->_allocator + this->_len, s._allocator, slen);
	delete[] oldstr;
	return *this;
}
String& String::operator +=(const string& s) {
	char* oldstr = this->_allocator;
	int slen = s.length();
	this->_allocator = new char[this->_len + slen];
	memcpy(this->_allocator, oldstr, this->_len);
	memcpy(this->_allocator + this->_len, s.c_str(), slen);
	delete[] oldstr;
	return *this;
}
ostream& operator<<(ostream& out, const String& s) {
	for(size_t i = 0; i < s.length(); i++)
		out << s[i];
	return out;
}