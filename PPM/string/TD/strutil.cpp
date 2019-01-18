#include <iostream>
#include "strutil.h"

namespace pr {
	size_t length(const char* str) {
		size_t ret = 0;
		for(;*str;++str) {
			++ret;
		}
		return ret;	
	}

	char* newcopy(const char* str) {
		size_t n = length(str);
		char* dest = new char[n+1];

		/*char* ret = dest;
		while((*dest++ = *str++) != '\0');

		return ret;*/
		memcpy(dest,str,n+1);
		return dest;
	}

	int compare (const char *cp, const char * cq) {
		for ( ; *cp == *cq && *cp; ++cp,++cq) {
		}
		return *cp - *cq;
	}
}