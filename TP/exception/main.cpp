#include <iostream>
#include "IndexException.h"
using namespace std;

void test() {
	throw IndexException();
}
int main(){
	
	try {
		test();
	}catch(Exception &e) {
		e.printException();
	}

	return 0;
}
