#include <iostream>
#include "MyStack.h"
#include "Coordinate.h"
using namespace std;

/*
短除法
	N 		 N div 8  	   N mod 8
	1348       168           4
	168        21            0
	21         2             5
	2          0             2

1345(10) = 2504(8) = 544(16) = 10101000100(2)

*/
#define BINARY 2
#define OCTONARY 8
#define	HEXADECIMAL 16
int main() {
	/*MyStack<Coordinate> *s = new MyStack<Coordinate>(5);
	s->push(Coordinate(1,2));
	cout<<s->stackFull()<<endl;
	Coordinate c;
	s->pop(c);
	cout<<c<<endl;
	cout<<s->stackEmpty()<<endl;
	*/

	/*进制转换
	char num[] = "0123456789ABCDEF";
	MyStack<int> *m = new MyStack<int>(20);
	int N = 10;
	int mod = 0;
	while(N != 0) {
		mod = N%HEXADECIMAL;
		m->push(mod);
		N = N/HEXADECIMAL;
	}
	//m->stackTraverse();
	int elem = 0;
	while(!m->stackEmpty()) {
		m->pop(elem);
		cout<<num[elem];
	}
	*/
	MyStack<char> *m = new MyStack<char>(20);
	char c[] = "[(()]";
	bool flag = true;
	int i=0;
	char elem;
	while(c[i] !='\0') {
		if(c[i] == '[' || c[i] == '(') {
			m->push(c[i]);
			i++;
		}else {
			m->pop(elem);
			if((c[i] ==']' && elem == '[') || (c[i] ==')' && elem == '(')) {
				i++;
			}else{
				flag = false;
				break;
			}
		}

	}
	if(flag) cout<<"true"<<endl;
	else cout<<"false"<<endl;
	delete m;
	return 1;
}