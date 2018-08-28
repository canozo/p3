#include <ncurses.h>
#include <string>

using namespace std;

int main()
{
	initscr();
	cbreak();
	noecho();

	int y, x, yBeg, xBeg, yMax, xMax;

	// get useful info from the terminal
	getyx(stdscr, y, x);
	getbegyx(stdscr, yBeg, xBeg);
	getmaxyx(stdscr, yMax, xMax);

	// draw a window at the center
	WINDOW* win = newwin(6, 6, yMax/2 - 3, xMax/2 - 3);
	box(win, 0, 0);
	refresh();
	wrefresh(win);
	printw("%d %d %d %d %d %d", y, x, yBeg, yMax, xMax);

	getch();
	endwin();
	return 0;
}
