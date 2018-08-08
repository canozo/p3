#include "Jugador.h"
#include "Escenario.h"
#include "Invisible.h"
#include "Tren.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <stdlib.h>

int validarCin(string);
void mover(Jugador*, Escenario*, int);

using namespace std;

int main()
{
	srand(time(NULL));

	int stageType, tipoBomba;
	string playerName;
	string stageName;

	cout << "Ingrese el nombre de jugador: ";
	cin >> playerName;

	do
	{
		stageType = validarCin("Ingrese el tipo de escenario que desea:\n1) Invisible\n2) Tren\nSeleccione: ");
	}
	while (stageType != 1 && stageType != 2);

	cout << "Ingrese el nombre del escenario: ";
	cin >> stageName;

	if (stageType == 1)
		do
			tipoBomba = validarCin("Ingrese el tipo de bomba que desea:\n1) Normal\n2) Espina\n3) Bomba V\nSeleccione: ");
		while (tipoBomba != 1 && tipoBomba != 2 && tipoBomba != 3);
	else
		tipoBomba = rand() % 3 + 1;

	initscr();
	noecho();
	keypad(stdscr, true);
	cbreak();

	int yMax, xMax, userInput;
	bool activateAI = false;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW* playfield = newwin(13, 15, yMax/2-6, xMax/2-7);
	box(playfield, 0, 0);
	refresh();
	wrefresh(playfield);
	Escenario* stage;

	Jugador* player = new Jugador(playfield, 0, 0, playerName, true, false, 1);

	if (stageType == 1)
	{
		stage = new Invisible(playfield, stageName, player, tipoBomba);
		mvprintw(yMax-7, 0, "Tipo: invisible");
	}
	else if (stageType == 2)
	{
		stage = new Tren(playfield, stageName, player, tipoBomba);
		mvprintw(yMax-7, 0, "Tipo: tren");
	}

	mvprintw(yMax-14, 0, "mover: w a s d");
	mvprintw(yMax-13, 0, "poner bomba: x");
	mvprintw(yMax-12, 0, "bomba V: v");
	mvprintw(yMax-11, 0, "bomba normal: *");
	mvprintw(yMax-10, 0, "bomba espina: x");
	mvprintw(yMax-8, 0, "Escenario: %s", stageName.c_str());
	mvprintw(yMax-6, 0, "Jugador: %s", player->getName().c_str());

	do
	{
		mover(player, stage, userInput);

		if (stageType == 2)
			(dynamic_cast<Tren*>(stage))->speedwagon();

		stage->checkAll();

		if (!activateAI)
			activateAI = true;
		else
			stage->moveBots();

		stage->display();
		mvprintw(yMax-5, 0, "Vidas: %d ", stage->getVidas());
		mvprintw(yMax-4, 0, "Bombas: %d ", player->getDisponibles());
		mvprintw(yMax-3, 0, "x: %d ", player->getXPos());
		mvprintw(yMax-2, 0, "y: %d ", player->getYPos());
		if (stage->victory())
			mvprintw(yMax/2-8, xMax/2-4, "you won!!");
		wrefresh(playfield);
	}
	while ((userInput = getch()) != 'q' && !stage->gameover());

	mvprintw(yMax/2-7, xMax/2-5, "game over!!");
	getch();
	delete stage;
	endwin();
	return 0;
}

int validarCin(string mensaje)
{
	int resultado = 0;
	bool salir = false;
	do
	{
		cout << mensaje;
		if (!(cin >> resultado))
		{
			cout << "Por favor no ingrese caracteres!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			salir = true;
		}
	}
	while(!salir);
	return resultado;
}

void mover(Jugador* player, Escenario* stage, int choice)
{
	switch (choice)
	{
		case 'w':
			player->mvup();
			if (stage->vacio(player))
				stage->mv(player);
			break;

		case 's':
			player->mvdown();
			if (stage->vacio(player))
				stage->mv(player);
			break;

		case 'a':
			player->mvleft();
			if (stage->vacio(player))
				stage->mv(player);
			break;

		case 'd':
			player->mvright();
			if (stage->vacio(player))
				stage->mv(player);
			break;

		case 'x':
			player->setBomb();
			break;

		default:
			break;
	}
}
