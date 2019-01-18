#include <iostream>
#include <string>
#include "String.h"
#include "strutil.h"
using namespace std;

namespace pr {
String::String(const char* cstr) {
	//str = newcopy(cstr);
	str = strdup(cstr);
}

String::String(const String& ori):String(ori.str){}

String::~String() {
	delete str;
}

String& String::operator=(const String& other) {
	if(this != &other) {
		cout<<"="<<endl;
		delete str;
		str = newcopy(other.str);
	}
	return *this;
}

size_t String::length () const {
	return pr::length(str);
}
String operator+ (const String &s1, const String & s2) {
	size_t sz1 = s1.length();
	size_t sz2 = s2.length();
	// + 1 pour le ’\0’
	char res [sz1+ sz2 +1];

	// version memcpy
	memcpy(res,s1.str,sz1);
	// + 1 pour le ’\0’
	memcpy(res+sz1,s2.str,sz2+1);
	
	return String (res);
}
bool operator==(const String & a,const String &b) {
	return ! compare(a.str,b.str);
}
bool String::operator<(const String & o) const {
	return compare(str,o.str) < 0;
}
char String::operator[] (size_t index) const {
	return str[index];
}
ostream & operator << (std::ostream & os, const String & s) {
 return os << s.str ;
}
}