/*
#include <iostream>
#include "MazeMap.h"
#include "MazePerson.h"

using namespace std;

const int SUCCESS = 0;
int main()
{
	int map[8][9] = {
					{WALL,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,WALL},
					{WALL,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,WALL},
					{WALL,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,WALL},
					{WALL,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,WALL},
					{WALL,WALL,ROAD,ROAD,ROAD,ROAD,WALL,ROAD,WALL},
					{WALL,WALL,ROAD,WALL,WALL,ROAD,ROAD,ROAD,WALL},
					{WALL,ROAD,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
					{WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL,WALL}
					};
	MazeMap maze;
	
	//maze.defaultMode();
	maze.setMazeMap(&map[0][0],8,9);
	maze.drawMap();
	MazePerson mazer;
	mazer.setPersonPosition(1,7);
	mazer.setPersonSpeed(SLOW);
	mazer.setPersonChar('!');
	mazer.start();
	
	
	return SUCCESS;
}
*/


#include <iostream>
#include <stdlib.h>
#include <curses.h>
#include <string>
#include "MyMazeMap.H"
#include "MyMazer.H"

using namespace std;

const int SUCCESS = 0;
int main()
{
	char users_name[ 100 ];
	initscr();
	(void)echo();

	addstr( "What is your name> " );
	mvaddstr(10,10,"*");
  	refresh();
  	 
	getnstr( users_name, sizeof( users_name ) - 1 );
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			
			mvaddstr(i,j,"*");
			
		}

	}
	 clear();
	
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
	maze.setMazeMap(&map[0][0],8,9);
	maze.setMazeWall('*');
	maze.drawMap();
	MyMazer mazer;
	mazer.setPersonPosition(1,7);
	mazer.setPersonSpeed(FAST);
	mazer.setPersonChar('T');
	mazer.start();
	
	
	endwin();
	system("pause");
	return SUCCESS;
}