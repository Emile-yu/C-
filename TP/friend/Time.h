#ifndef TIME_H_
#define TIME_H_
#include "Match.h"
class Match;
class Match1;
class Time
{
	/*1*/friend void printTime(Time &t);
	/*2*/friend void Match::printTimeInClass(Time &t);
	/*3*/friend Match1;
public:
	Time(int hour, int min, int sec);
	~Time(){};
private:
	int m_iHour;
	int m_iMinute;
	int m_iSecond;	
};
#endif