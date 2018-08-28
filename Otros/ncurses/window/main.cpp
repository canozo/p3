#include <ncurses.h>

using namespace std;

int main()
{
	initscr();
	// ctrl c to break (default)
	cbreak();
	// take all input
	// raw();
	// don't show input characters
	noecho();

	int height = 10;
	int width = 20;
	int start_y = 10;
	int start_x = 10;

	// windows
	WINDOW* win = newwin(height, width, start_y, start_x);

	// refresh all screen
	refresh();

	// show a basic border on our window, int values are characters
	box(win, 0, 0);

	// change border characters
	int left, right, top, bottom, tlc, trc, blc, brc;
	left = right = '\\';
	top = bottom = '\"';
	tlc = trc = blc = brc = '+';
	wborder(win, left, right, top, bottom, tlc, trc, blc, brc);

	// moves (inside the window) and prints
	mvwprintw(win, 1, 1, "This is my box");

	// refresh specific window
	wrefresh(win);

	int c = getch();
	endwin();
	return 0;
}
