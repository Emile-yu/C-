#include<iostream>
#include"MyMazePerson.h"

MyMazePerson::MyMazePerson() {
	mazePerson = new MazePerson();
}

MyMazePerson::MyMazePerson(int currentX, int currentY) {
	mazePerson = new MazePerson(currentX,currentY);
}
MyMazePerson::MyMazePerson(int currentX, int currentY, objectiveDirections myForward){
	mazePerson = new MazePerson(currentX,currentY,myForward);
}
MyMazePerson::~MyMazePerson() {
	delete mazePerson;
}
void MyMazePerson::setPersonPos(int coordX, int coordY) {
	mazePerson->setPersonPos(coordX,coordY);
}
void MyMazePerson::setPersonPic(char pic) {
	mazePerson->setPersonPic(pic);
}
void MyMazePerson::setPersonSpeed(int speed) {
	mazePerson->setPersonSpeed(speed);
}
void MyMazePerson::setPersonForward(objectiveDirections myForward){
	mazePerson->setPersonForward(myForward);
}
void MyMazePerson::start() {
	mazePerson->start();
}
