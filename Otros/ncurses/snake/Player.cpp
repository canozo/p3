#include "Player.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

Player::Player(WINDOW* currwin)
{
	this->currwin = currwin;
	srand(time(NULL));
	xLast = 1;
	yLast = 0;
	size = 3;

	snake = new int*[100];
	for (int i = 0; i < 100; i++)
		snake[i] = new int[2];

	// snake[n][0] = y
	// snake[n][1] = x
	snake[0][0] = 3;
	snake[0][1] = 3;
	snake[1][0] = 3;
	snake[1][1] = 4;
	snake[2][0] = 3;
	snake[2][1] = 5;

	getmaxyx(currwin, yMax, xMax);
	spawnFruit();
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

void Player::spawnFruit()
{
	bool salir = false;
	while (!salir)
	{
		yFruit = rand() % (yMax - 3) + 2;
		xFruit = rand() % (xMax - 3) + 2;
		salir = true;

		for (int i = 0; i < size; i++)
			if (yFruit == snake[i][0] && xFruit == snake[i][1])
			{
				salir = false;
				break;
			}
	}
}

void Player::mvup()
{
	if (snake[size-1][0] > 1)
	{
		xLast = 0;
		yLast = -1;
		mv();
	}
}

void Player::mvdown()
{
	if (snake[size-1][0] < yMax - 2)
	{
		xLast = 0;
		yLast = 1;
		mv();
	}
}

void Player::mvleft()
{
	if (snake[size-1][1] > 1)
	{
		xLast = -1;
		yLast = 0;
		mv();
	}
}

void Player::mvright()
{
	if (snake[size-1][1] < xMax - 2)
	{
		xLast = 1;
		yLast = 0;
		mv();
	}
}

void Player::mvforward()
{
	if (xLast == 0 && snake[size-1][0] > 1 && snake[size-1][0] < yMax-2)
		mv();
	else if (yLast == 0 && snake[size-1][1] > 1 && snake[size-1][1] < xMax-2)
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

	for (int i = 0; i < size; i++)
		if (snake[i][0] == yFruit && snake[i][1] == xFruit)
		{
			size++;
			snake[size-1][0] = snake[size-2][0] + yLast;
			snake[size-1][1] = snake[size-2][1] + xLast;
			spawnFruit();
		}
}

void Player::display()
{
	mvwaddch(currwin, yFruit, xFruit, '#');
	for (int i = 0; i < size; i++)
		mvwaddch(currwin, snake[i][0], snake[i][1], size + '0');
}
