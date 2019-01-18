#include<iostream>
#include"MyMazeMap.h"

int main()
{
	int map[8][9] = {
					{WALL,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,WALL},
					{WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
					{WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
					{WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
					{WALL,WALL,ROAD,ROAD,ROAD,ROAD,WALL,ROAD,WALL},
					{WALL,WALL,ROAD,WALL,WALL,ROAD,ROAD,ROAD,WALL},
					{WALL,ROAD,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
					{WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL,WALL}
					};
	MyMazeMap maze;          
	
	//maze.defaultMode();
	maze.setmazeMap(&map[0][0],8,9);
	maze.setmazeWall('*');
	maze.drawMap();

	return 0;
}
