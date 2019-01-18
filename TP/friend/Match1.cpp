#include <iostream>
#include "Time.h"
#include "Match1.h"
using namespace std;

Match1::Match1(int hour, int min, int sec):time(hour,min,sec){}

void Match1::testTime() {

	cout<<time.m_iHour<<":"<<time.m_iMinute<<":"<<time.m_iSecond<<endl;

}