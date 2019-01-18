#ifndef STRING_H_
#define STRING_H_
#include <iostream>
using namespace std;

namespace pr {
	class String
	{
		
		friend String operator+(const String &s1, const String &s2);
		friend bool operator==(const String &s1, const String &s2);
		friend ostream& operator<<(ostream& o, const String &s);
	public:
		String(const char* cstr="");
		~String();
		String(const String &ori);
		String& operator=(const String & other);
		char operator[] (size_t index) const;
		size_t length() const;
		bool operator<(const String &o) const;
	private:
	const char* str;		
	};
}
#endif