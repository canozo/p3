#include "Item.h"
#include <ncurses.h>
#include <string>

using namespace std;

#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador : public Item
{
	private:
		WINDOW* currwin;
		int xMax, yMax, yLast, xLast, xBomb, yBomb, bombasDisponibles, ID;
		string name;
		bool alive, bot, bomb;

	public:
		Jugador(WINDOW*, int, int, string, bool, bool, int);
		string getName();
		bool isBot();
		bool getBomb();
		bool isAlive();
		void setBomb();
		void giveBomb();
		void kill();
		int getID();
		int getXBomb();
		int getYBomb();
		int getDisponibles();
		int getYLast();
		int getXLast();
		void setYPos(int);
		void setXPos(int);
		void mvup();
		void mvdown();
		void mvleft();
		void mvright();
};

#endif
