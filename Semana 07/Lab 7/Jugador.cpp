#include "Jugador.h"
#include <ncurses.h>
#include <string>

using namespace std;

Jugador::Jugador(WINDOW* currwin, int yPos, int xPos, string name, bool alive, bool bot, int ID) : Item(yPos, xPos, '@')
{
	this->currwin = currwin;
	this->name = name;
	this->alive = alive;
	this->bot = bot;
	this->ID = ID;
	xLast = 1;
	yLast = 0;
	bombasDisponibles = 3;
	getmaxyx(currwin, yMax, xMax);
}

string Jugador::getName()
{
	return name;
}

void Jugador::kill()
{
	alive = false;
}

void Jugador::setBomb()
{
	if (bombasDisponibles > 0)
	{
		bomb = true;
		yBomb = yPos;
		xBomb = xPos;
	}
}

bool Jugador::getBomb()
{
	if (bomb && (yPos != yBomb || xPos != xBomb))
	{
		bomb = false;
		bombasDisponibles--;
		return true;
	}
	return false;
}

bool Jugador::isBot()
{
	return bot;
}

bool Jugador::isAlive()
{
	return alive;
}

void Jugador::giveBomb()
{
	bombasDisponibles++;
}

int Jugador::getID()
{
	return ID;
}

int Jugador::getDisponibles()
{
	return bombasDisponibles;
}

int Jugador::getXBomb()
{
	return xBomb;
}

int Jugador::getYBomb()
{
	return yBomb;
}

int Jugador::getYLast()
{
	return yLast;
}

int Jugador::getXLast()
{
	return xLast;
}

void Jugador::setYPos(int yPos)
{
	this->yPos = yPos;
}

void Jugador::setXPos(int xPos)
{
	this->xPos = xPos;
}

void Jugador::mvup()
{
	if (yPos > 0)
	{
		xLast = 0;
		yLast = -1;
	}
	else
	{
		xLast = 0;
		yLast = 0;
	}
}

void Jugador::mvdown()
{
	if (yPos < yMax - 3)
	{
		xLast = 0;
		yLast = 1;
	}
	else
	{
		xLast = 0;
		yLast = 0;
	}
}

void Jugador::mvleft()
{
	if (xPos > 0)
	{
		xLast = -1;
		yLast = 0;
	}
	else
	{
		xLast = 0;
		yLast = 0;
	}
}

void Jugador::mvright()
{
	if (xPos < xMax - 3)
	{
		xLast = 1;
		yLast = 0;
	}
	else
	{
		xLast = 0;
		yLast = 0;
	}
}
