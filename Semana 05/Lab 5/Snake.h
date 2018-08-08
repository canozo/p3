#include <iostream>
#include <vector>
#include <string>
#include <ncurses.h>

using namespace std;

#ifndef SNAKE_H
#define SNAKE_H

class Snake
{
	private:
		string nombre;
		int size, comidos, movs, xMax, yMax, xLast, yLast, xFruit, yFruit;
		WINDOW* currwin;
		vector<string> vecSnake;
	public:
		Snake(WINDOW*, string);
		void spawnFruit();
		void mv();
		bool mvup();
		bool mvdown();
		bool mvleft();
		bool mvright();
		bool mvforward();
		bool collision();
		void display();
		int getPuntaje();
		int getXLast();
		int getYLast();
};

#endif
