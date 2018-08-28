#include <ncurses.h>
#include <string>

using namespace std;

int main()
{
	initscr();
	noecho();
	cbreak();

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	// create a window for menu
	WINDOW* menuwin = newwin(6, xMax-12, yMax-8, 5);
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);

	// enable arrow keys and others
	keypad(menuwin, true);

	string choices[3] = {"walk", "jog", "run"};
	int choice;
	int highlight = 0;

	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == highlight)
				wattron(menuwin, A_REVERSE);
			mvwprintw(menuwin, i+1, 1, choices[i].c_str());
			wattroff(menuwin, A_REVERSE);
		}
		choice = wgetch(menuwin);

		switch (choice)
		{
			case KEY_UP:
				if (highlight > 0)
					highlight--;
				break;

			case KEY_DOWN:
				if (highlight < 2)
					highlight++;
				break;

			default:
				break;
		}

		// pressed enter
		if (choice == 10)
			break;
	}

	printw("Your choice was: %s", choices[highlight].c_str());

	getch();
	endwin();
	return 0;
}
