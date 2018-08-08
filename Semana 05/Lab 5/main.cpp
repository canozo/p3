#include "Snake.h"
#include <string>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

using namespace std;

bool mover(Snake*, int);

int main()
{
	string nombre;
	cout << "Ingrese el nombre del jugador: ";
	cin >> nombre;

	initscr();
	noecho();
	keypad(stdscr, true);
	timeout(500);

	int yMax, xMax, userInput;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW* playfield = newwin(12, 12, yMax/2-5, xMax/2-5);
	box(playfield, 0, 0);
	refresh();
	wrefresh(playfield);

	Snake* snake = new Snake(playfield, nombre);
	do
	{
		if (!mover(snake, userInput) || snake->collision())
		{
			// perdio
			break;
		}
		snake->display();
		move(yMax-1, 0);
		printw(nombre.c_str());
		attroff(A_BOLD);
		printw(", score: %d", snake->getPuntaje());
		attron(A_BOLD);
		wrefresh(playfield);
	}
	while((userInput = getch()) != 'q');

	do
	{
		move(yMax/2, xMax/2-22);
		printw("game over, su puntaje fue %d (q para salir)", snake->getPuntaje());
	}
	while(getch() != 'q');

	delete snake;
	endwin();
	return 0;
}

bool mover(Snake* snake, int userInput)
{
	switch (userInput)
	{
		case 'w':
			if (snake->getYLast() == 1)
				return snake->mvdown();
			return snake->mvup();
			break;

		case 's':
			if (snake->getYLast() == -1)
				return snake->mvup();
			return snake->mvdown();
			break;

		case 'a':
			if (snake->getXLast() == 1)
				return snake->mvright();
			return snake->mvleft();
			break;

		case 'd':
			if (snake->getXLast() == -1)
				return snake->mvleft();
			return snake->mvright();
			break;

		default:
		case ERR:
			return snake->mvforward();
			break;
	}
}
