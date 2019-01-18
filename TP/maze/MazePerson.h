#ifndef MAZEPERSON_H_
#define MAZEPERSON_H_
#include"public.h"
class MazePerson{
public:
	MazePerson();
	MazePerson(int currentX, int currentY);
	MazePerson(int currentX, int currentY, objectiveDirections myForward);
	void setPersonPos(int coordX, int coordY);
	void setPersonPic(char pic);
	void setPersonSpeed(int speed);
	void setPersonForward(objectiveDirections myForward);
	void start();
private:
	int preX;
	int preY;
	int positionX;
	int positionY;
	int personSpeed;
	char personPic;
	bool outOrNot;
	objectiveDirections forward;
	
	void savePrePosition();
	void moveSouth();
	void moveNorth();
	void moveEast();
	void moveWest();
	void turnLeft();
	void turnRight();
	void goAhead();
	bool moveForward();
	
	void gotoxy(int posX, int posY);
	void drawPerson();
		
};
#endif
