#include<iostream>
#include"MazeMap.h"
using namespace std;

char MazeMap::mazeRoad = ' ';
int MazeMap::mazeWidth = 0;
int MazeMap::mazeHeight = 0;
int MazeMap::mazeMapArray[screenWidth][screenHeight];

MazeMap::MazeMap():mazeWall('#') {
	mazeWidth = 60;
	mazeHeight = 20;
}

MazeMap::MazeMap(int *mazeMap, int row, int column) {
	mazeWidth = row;
	mazeHeight = column;
	for(int i=0;i<row;i++) {
		for(int j=0;j<column;j++) {
			mazeMapArray[i][j] = *mazeMap;
			mazeMap++;
		}
	}
}

void MazeMap::setmazeMap(int *mazeMap, int row, int column) {
	mazeWidth = row;
	mazeHeight = column;
	for(int i=0;i<row;i++) {
		for(int j=0;j<column;j++) {
			mazeMapArray[i][j] = *mazeMap;
			mazeMap++;
		}
	}
}

void MazeMap::setmazeWall(char wall) {
	mazeWall = wall;
}

void MazeMap::setmazeRoad(char road) {
	mazeRoad = road;
}

void MazeMap::drawMap() const {
	for(int i=0;i<mazeWidth;i++) {
		for(int j=0;j<mazeHeight;j++) {
			if(mazeMapArray[i][j] == 1) cout<<mazeWall;
			else cout<<mazeRoad;
		}
		cout<<endl;
	}
}
static bool MazeMap::checkWallOrNot(int mazeX, int mazeY) {
	if (mazeMapArray[mazeX][mazeY] == WALL) return true;
	else return false;
}
static bool MazeMap::checkMazeDoor(int mazeX, int mazeY) {
	if(mazeX == 0 || mazeX == (mazeWidth-1)) {//vectical
		if(mazeMapArray[mazeX][mazeY] == ROAD) return true;
	}
	if(mazeY ==0 || mazeY == (mazeHeight -1)) {
		if(mazeMapArray[mazeX][mazeY] == ROAD) return true;
	}
	return false;
}



















