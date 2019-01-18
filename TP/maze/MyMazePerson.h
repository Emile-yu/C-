#ifndef MYMAZEPERSON_H_
#define MYMAZEPERSON_H
#include"MazePerson.h"
#include"public.h"
class MyMazePerson {
public:
	MyMazePerson();
	MyMazePerson(int currentX, int currentY);
	MyMazePerson(int currentX, int currentY, objectiveDirections myForward);
	~MyMazePerson();
	void setPersonPos(int coordX, int coordY);
	void setPersonPic(char pic);
	void setPersonSpeed(int speed);
	void setPersonForward(objectiveDirections myForward);
	void start();
private:
	MazePerson *mazePerson;
};
#endif
