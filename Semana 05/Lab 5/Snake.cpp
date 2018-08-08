#include "Snake.h"
#include <string>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

Snake::Snake(WINDOW* currwin, string nombre)
{
	this->currwin = currwin;
	this->nombre = nombre;

	// vecSnake.push_back("y-x");
	vecSnake.push_back("2-2");
	vecSnake.push_back("2-3");
	vecSnake.push_back("2-4");
	vecSnake.push_back("2-5");
	vecSnake.push_back("2-6");

	comidos = 0;
	movs = 0;
	size = 5;
	xLast = 1;
	yLast = 0;

	getmaxyx(currwin, yMax, xMax);
	// poner una fruta
	srand(time(NULL));
	spawnFruit();
}

void Snake::spawnFruit()
{
	bool salir = false;
	int xTemp, yTemp;
	while (!salir)
	{
		yFruit = rand() % 10 + 1;
		xFruit = rand() % 10 + 1;

		salir = true;
		for (int i = 0; i < size; i++)
		{
			xTemp = vecSnake[i][2] - '0';
			yTemp = vecSnake[i][0] - '0';
			if (yFruit == yTemp && xFruit == xTemp)
			{
				salir = false;
				break;
			}
		}
	}
}

void Snake::mv()
{
	int xTemp;
	int yTemp;
	bool comio = false;
	string initPos;
	movs++;
	mvwaddch(currwin, vecSnake[0][0] - '0', vecSnake[0][2] - '0', ' ');

	for (int i = 0; i < size; i++)
		if (vecSnake[i][0] - '0' == yFruit && vecSnake[i][2] - '0' == xFruit)
		{
			comio = true;
			comidos += 100 - movs;
			movs = 0;

			initPos = vecSnake[0];

			for (int j = 0; j < size - 1; j++)
			{
				vecSnake[j][0] = vecSnake[j+1][0];
				vecSnake[j][2] = vecSnake[j+1][2];
			}

			yTemp = vecSnake[size-1][0] - '0';
			xTemp = vecSnake[size-1][2] - '0';

			yTemp += yLast;
			xTemp += xLast;

			vecSnake[size-1][0] = yTemp + '0';
			vecSnake[size-1][2] = xTemp + '0';

			size++;
			vecSnake.insert(vecSnake.begin(), initPos);
			spawnFruit();
		}

	if (!comio)
	{
		for (int i = 0; i < size - 1; i++)
		{
			vecSnake[i][0] = vecSnake[i+1][0];
			vecSnake[i][2] = vecSnake[i+1][2];
		}

		yTemp = vecSnake[size-1][0] - '0';
		xTemp = vecSnake[size-1][2] - '0';

		yTemp += yLast;
		xTemp += xLast;

		vecSnake[size-1][0] = yTemp + '0';
		vecSnake[size-1][2] = xTemp + '0';
	}
}

bool Snake::mvup()
{
	if (vecSnake[size-1][0] - '0' > 1)
	{
		xLast = 0;
		yLast = -1;
		mv();
		return true;
	}
	else
	{
		return false;
	}
}

bool Snake::mvdown()
{
	if (vecSnake[size-1][0] - '0' < yMax-2)
	{
		xLast = 0;
		yLast = 1;
		mv();
		return true;
	}
	else
	{
		return false;
	}
}

bool Snake::mvleft()
{
	if (vecSnake[size-1][2] - '0' > 1)
	{
		xLast = -1;
		yLast = 0;
		mv();
		return true;
	}
	else
	{
		return false;
	}
}

bool Snake::mvright()
{
	if (vecSnake[size-1][2] - '0' < xMax-2)
	{
		xLast = 1;
		yLast = 0;
		mv();
		return true;
	}
	else
	{
		return false;
	}
}

bool Snake::mvforward()
{
	if (yLast == -1)
	{
		return mvup();
	}
	else if (yLast == 1)
	{
		return mvdown();
	}
	else if (xLast == 1)
	{
		return mvright();
	}
	else if (xLast == -1)
	{
		return mvleft();
	}
}

void Snake::display()
{
	mvwaddch(currwin, yFruit, xFruit, '#');
	for (int i = 0; i < size; i++)
		mvwaddch(currwin, vecSnake[i][0] - '0', vecSnake[i][2] - '0', '@');
}

int Snake::getXLast()
{
	return xLast;
}

int Snake::getYLast()
{
	return yLast;
}

bool Snake::collision()
{
	for(int i = 0; i < vecSnake.size(); i++)
		for(int j = 0; j < vecSnake.size(); j++)
			if(i != j && vecSnake[i]  == vecSnake[j])
				return true;
	return false;
}

int Snake::getPuntaje()
{
	return comidos;
}
