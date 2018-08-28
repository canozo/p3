#include <ncurses.h>

using namespace std;

int main()
{
	// init screen
	initscr();

	int x = 10;
	int y = 10;
	// moves the cursor
	move(y, x);

	// print to a window
	printw("hello world");

	// refresh the screen to match with memory
	refresh();

	int c = getch();
	// move and print in one line
	// mvprintw(0, 0, "%d", c);

	// normal print
	printw("%d", c);

	getch();
	// clear entire screen
	clear();
	getch();

	// deallocate memory
	endwin();
	return 0;
}
