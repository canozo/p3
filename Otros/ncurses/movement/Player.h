#include <ncurses.h>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	private:
		int xPos, yPos, xMax, yMax, yLast, xLast;
		char character;
		WINDOW* currwin;

	public:
		Player(WINDOW*, int, int, char);
		void mv();
		void mvup();
		void mvdown();
		void mvleft();
		void mvright();
		void display();
};

#endif
