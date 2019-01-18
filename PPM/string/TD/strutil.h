#ifndef STRUTIL_H_
#define STRUTIL_H_
#include <cstring>
namespace pr {
	size_t length(const char* str);
	char* newcopy(const char* str);
	int compare (const char *a, const char * b);
}
#endif