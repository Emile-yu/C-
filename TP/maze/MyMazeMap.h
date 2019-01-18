#ifndef MYMAZEMAP_H_
#define MYMAZEMAP_H_
#include"MazeMap.h"
class MyMazeMap {
public:
	MyMazeMap();
	MyMazeMap(int *MymazeMap, int row, int column);
	~MyMazeMap();
	void setmazeMap(int *MymazeMap, int row, int column);
	void setmazeWall(char wall);
	void setmazeRoad(char road);
	void drawMap() const;
private:
	MazeMap *mazeMap;
};
#endif	
