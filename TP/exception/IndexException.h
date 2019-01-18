#ifndef INDEXEXCEPTION_H_
#define INDEXEXCEPTION_H_
#include "Exception.h"
class IndexException:public Exception
{
public:
	IndexException(){}
	~IndexException(){}
	void printException();
};
#endif