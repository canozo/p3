#include "Player.h"
#include <ncurses.h>

using namespace std;

Player::Player(WINDOW* currwin)
{
	this->currwin = currwin;
	yPos = 2;
	xPos = 4;
	xLast = 1;
	yLast = 0;
	size = 3;

	snake = new int*[100];
	for (int i = 0; i < 100; i++)
		snake[i] = new int[2];

	// snake[n][0] = y
	// snake[n][1] = x
	snake[0][0] = 2;
	snake[0][1] = 2;
	snake[1][0] = 2;
	snake[1][1] = 3;
	snake[2][0] = 2;
	snake[2][1] = 4;

	getmaxyx(currwin, yMax, xMax);
}

Player::~Player()
{
	for (int i = 0; i < 100; i++)
	{
		delete[] snake[i];
		snake[i] = NULL;
	}
	delete[] snake;
	snake = NULL;
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

void Player::mvforward()
{
	if (xLast == 0 && yPos > 1 && yPos < yMax-2)
		mv();
	else if (yLast == 0 && xPos > 1 && xPos < xMax-2)
		mv();
}

void Player::mv()
{
	mvwaddch(currwin, snake[0][0], snake[0][1], ' ');

	for (int i = 0; i < size - 1; i++)
	{
		snake[i][0] = snake[i+1][0];
		snake[i][1] = snake[i+1][1];
	}
	snake[size-1][0] += yLast;
	snake[size-1][1] += xLast;
}

void Player::display()
{
	for (int i = 0; i < size; i++)
		mvwaddch(currwin, snake[i][0], snake[i][1], '@');
}
