#include <ncurses.h>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	private:
		int size, xPos, yPos, xMax, yMax, xLast, yLast, xFruit, yFruit;
		int** snake;
		WINDOW* currwin;

	public:
		Player(WINDOW*);
		~Player();
		void spawnFruit();
		void mv();
		void mvup();
		void mvdown();
		void mvleft();
		void mvright();
		void mvforward();
		void display();
};

#endif
