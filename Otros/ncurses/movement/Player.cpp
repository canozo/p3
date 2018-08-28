#include "Player.h"
#include <ncurses.h>

using namespace std;

Player::Player(WINDOW* currwin, int yPos, int xPos, char character)
{
	this->currwin = currwin;
	this->yPos = yPos;
	this->xPos = xPos;
	this->character = character;
	xLast = 1;
	yLast = 0;
	getmaxyx(currwin, yMax, xMax);
}

void Player::mvup()
{
	if (yPos > 1)
	{
		xLast = 0;
		yLast = -1;
		mv();
	}
}

void Player::mvdown()
{
	if (yPos < yMax - 2)
	{
		xLast = 0;
		yLast = 1;
		mv();
	}
}

void Player::mvleft()
{
	if (xPos > 1)
	{
		xLast = -1;
		yLast = 0;
		mv();
	}
}

void Player::mvright()
{
	if (xPos < xMax - 2)
	{
		xLast = 1;
		yLast = 0;
		mv();
	}
}

void Player::mv()
{
	mvwaddch(currwin, yPos, xPos, ' ');
	yPos += yLast;
	xPos += xLast;
}

void Player::display()
{
	mvwaddch(currwin, yPos, xPos, character);
}
