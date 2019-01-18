#ifndef TANK_H_
#define TANK_H_

class Tank
{
public:
	Tank(char code);
	~Tank();
	void fire();
	static int getCount();
private:
	static int s_iCount;
	char m_cCode;	
};
#endif