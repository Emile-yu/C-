#include <iostream>
#include "Time.h"
#include "Match.h"
#include "Match1.h"
using namespace std;

/*
	1.友元全局函数
	2.友元成员函数
	3.友元类
*/

void printTime(Time &t);

int main(){
	Time t(6,34,25);
	//printTime(t);
	/*Match m;
	m.printTimeInClass(t);
	*/

	Match1 m(6,34,25);
	m.testTime();
	return 0;
}

void printTime(Time &t) {

	cout<<t.m_iHour<<":"<<t.m_iMinute<<":"<<t.m_iSecond<<endl;
}