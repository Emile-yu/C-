#include<iostream>
#include<unistd.h>
#include"MazePerson.h"
#include"MazeMap.h"
using namespace std;
MazePerson::MazePerson() {
	preX = 10000;
	preY = 10000;
	positionX = 1;
	positionY = 1;
	personSpeed = 10000;
	personPic = '*';
	outOrNot = false;
	forward = NORTH;
}

MazePerson::MazePerson(int currentX, int currentY) {
	preX = 10000;
	preY = 10000;
	positionX = currentX;
	positionY = currentY;
	personSpeed = 10000;
	personPic = '*';
	outOrNot = false;
	forward = NORTH;
}
MazePerson::MazePerson(int currentX, int currentY, objectiveDirections myForward) {
	preX = 10000;
	preY = 10000;
	positionX = 1;
	positionY = 1;
	personSpeed = 10000;
	personPic = '*';
	outOrNot = false;
	forward = myForward;
}
void MazePerson::setPersonPos(int coordX, int coordY) {
	positionX = coordX;
	positionY = coordY;
}
void MazePerson::setPersonPic(char pic) {
	personPic = pic;
}
void MazePerson::setPersonSpeed(int speed) {
	personSpeed = speed;
}
void MazePerson::setPersonForward(objectiveDirections myForward) {
	forward = myForward;
}

void MazePerson::savePrePosition() {
	preX = positionX;
	preY = positionY;
}
void MazePerson::moveSouth() {
	savePrePosition();
	positionX = positionX;
	positionY = positionY - 1;
}
void MazePerson::moveNorth() {
	savePrePosition();
	positionX = positionX;
	positionY = positionY + 1;
}
void MazePerson::moveEast() {
	savePrePosition();
	positionX = positionX + 1;
	positionY = positionY;
}
void MazePerson::moveWest() {
	savePrePosition();
	positionX = positionX - 1;
	positionY = positionY;
}
void MazePerson::turnLeft() {
	switch(forward) {
		case SOUTH:forward = WEST;break;
		case NORTH:forward = EAST;break;
		case EAST:forward = SOUTH;break;
		case WEST:forward = NORTH;break;
	}
}
void MazePerson::turnRight() {
	switch(forward) {
		case SOUTH:forward = EAST;break;
		case NORTH:forward = WEST;break;
		case EAST:forward = NORTH;break;
		case WEST:forward = SOUTH;break;
	}
}

void MazePerson::gotoxy(int posX, int posY) {

}

void MazePerson::drawPerson() {
	gotoxy(preX,preY);
	cout<<" ";
	gotoxy(positionX,positionY);
	cout<<personPic;
	sleep(personSpeed);
}

void MazePerson::goAhead() {
	switch(forward) {
		case SOUTH:moveSouth();break;
		case NORTH:moveNorth();break;
		case EAST:moveEast();break;
		case WEST:moveWest();break;
	}
	drawPerson();
	
	if(MazeMap::checkMazeDoor(positionX,positionY)) {
		gotoxy(0,22);
		cout<"im out";
		outOrNot = true;
	}
}

void MazePerson::start() {
	int i=0;
	while(!outOrNot) {
		gotoxy(0,12);
		cout<<i;
		i++;
		moveForward();
	}
}
bool MazePerson::moveForward() {
	if(preX == 10000 || preY == 10000) {
		gotoxy(positionX,positionY);
		cout<<personPic;
		sleep(personSpeed);
	}
	int currentWallX,currentWallY;
	int forwardX,forwardY;
	
	switch(forward) {
		case SOUTH:forwardX = forwardX;forwardY = forwardY + 1;
				   currentWallX = currentWallX - 1;
				   currentWallY = currentWallY;break;
		case NORTH:forwardX = forwardX;forwardY = forwardY - 1;
				   currentWallX = currentWallX + 1;
				   currentWallY = currentWallY;break;
		case EAST:forwardX = forwardX + 1;forwardY = forwardY;
				   currentWallX = currentWallX;
				   currentWallY = currentWallY + 1;break;
		case WEST:forwardX = forwardX - 1;forwardY = forwardY;
				   currentWallX = currentWallX;
				   currentWallY = currentWallY -1;break; 
	}
	if(MazeMap::checkWallOrNot(currentWallX, currentWallY)) {
		if(MazeMap::checkWallOrNot(forwardX, forwardY)) {
			turnLeft();
			return false;
		}else {
			goAhead();
			return true;
		}	
	}else{
		turnRight();goAhead();
		return true;
	}
	
}




















