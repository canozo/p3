#include "Player.h"
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void move(Player*, int);

int main()
{
	initscr();
	noecho();
	timeout(250);

	int yMax, xMax, userInput;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW* playfield = newwin(20, 50, yMax/2-10, xMax/2-25);
	box(playfield, 0, 0);
	refresh();
	wrefresh(playfield);
	keypad(stdscr, true);

	Player* player = new Player(playfield);
	do
	{
		move(player, userInput);
		player->display();
		wrefresh(playfield);
	}
	while ((userInput = getch()) != 'x');

	delete player;
	endwin();
	return 0;
}

void move(Player* player, int choice)
{
	switch (choice)
	{
		case KEY_UP:
			player->mvup();
			break;

		case KEY_DOWN:
			player->mvdown();
			break;

		case KEY_LEFT:
			player->mvleft();
			break;

		case KEY_RIGHT:
			player->mvright();
			break;

		case ERR:
			player->mvforward();
			break;

		default:
			break;
	}
}
