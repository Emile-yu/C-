#ifndef MATCH1_H_
#define MATCH1_H_

class Time;
class Match1
{
public:
	Match1(int hour, int min, int sec);
	~Match1(){}
	void testTime();
private:
	Time time;
	
};
#endif