#include<iostream>
#include"MyMazeMap.h"

MyMazeMap::MyMazeMap() {
	mazeMap = new MazeMap();
}

MyMazeMap::MyMazeMap(int *MymazeMap, int row, int column) {
	mazeMap = new MazeMap(MymazeMap,row,column);
}

MyMazeMap::~MyMazeMap() {
	delete mazeMap;
}
void MyMazeMap::setmazeMap(int *MymazeMap, int row, int column) {
	mazeMap->setmazeMap(Myg++mazeMap,row,column);
}
void MyMazeMap::setmazeWall(char wall) {
	mazeMap->setmazeWall(wall);
}
void MyMazeMap::setmazeRoad(char road) {
	mazeMap->setmazeRoad(road);
}
void MyMazeMap::drawMap() const {
	mazeMap->drawMap();
}

