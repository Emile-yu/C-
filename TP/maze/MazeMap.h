#ifndef MAZEMAP_H
#define MAZEMAP_H
#include"public.h"
#define screenWidth 80
#define screenHeight 25


class MazeMap{
private:
	char mazeWall;
	static char mazeRoad;
	static int mazeWidth;
	static int mazeHeight;
	static int mazeMapArray[screenWidth][screenHeight];
public:
	MazeMap();
	MazeMap(int *mazeMap, int row, int column);
	void setmazeMap(int *mazeMap, int row, int column);
	void setmazeWall(char wall);
	void setmazeRoad(char road);
	void drawMap() const;
	static bool checkWallOrNot(int mazeX, int mazeY);
	static bool checkMazeDoor(int mazeX, int mazeY);

};
#endif
