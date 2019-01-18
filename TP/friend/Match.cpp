#include <iostream>
#include "Time.h"
#include "Match.h"
using namespace std;
void Match::printTimeInClass(Time &t) {
	cout<<t.m_iHour<<":"<<t.m_iMinute<<":"<<t.m_iSecond<<endl;

}