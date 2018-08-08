#include "Tren.h"
#include "Jugador.h"
#include "Pared.h"
#include "Vagon.h"
#include "Normal.h"
#include "Espina.h"
#include "BombaV.h"
#include <vector>
#include <ncurses.h>

Tren::Tren(WINDOW* currwin, string name, Jugador* player, int tipoBomba) : Escenario(currwin, name, player, tipoBomba)
{
	// crear vagon y pista
	matrizItems[2][4] = new Vagon(2, 4);
	pistaVagon = new bool*[11];
	for (int i = 0; i < 11; i++)
	{
		pistaVagon[i] = new bool[13];
		for (int j = 0; j < 13; j++)
		{
			pistaVagon[i][j] = false;
		}
	}
	vidas = 1;
	pistaVagon[2][4] = true;
	pistaVagon[2][5] = true;
	pistaVagon[2][6] = true;
	pistaVagon[2][7] = true;
	pistaVagon[2][8] = true;
	pistaVagon[3][8] = true;
	pistaVagon[4][8] = true;
	pistaVagon[5][8] = true;
	pistaVagon[6][8] = true;
	pistaVagon[7][8] = true;
	pistaVagon[8][8] = true;
	pistaVagon[8][7] = true;
	pistaVagon[8][6] = true;
	pistaVagon[8][5] = true;
	pistaVagon[8][4] = true;
	pistaVagon[7][4] = true;
}

Tren::~Tren()
{
	for (int i = 0; i < 11; i++)
	{
		delete[] pistaVagon[i];
		pistaVagon[i] = NULL;
	}
	delete[] pistaVagon;
	pistaVagon = NULL;
}

void Tren::speedwagon()
{
	Vagon* tempVagon;
	Jugador* tempJugador;
	Bomba* tempBomba;
	bool vagonMode = false;

	if (matrizItems[2][3] != NULL && dynamic_cast<Jugador*>(matrizItems[6][4]) == NULL
		&& (tempJugador = dynamic_cast<Jugador*>(matrizItems[2][3])) != NULL
		&& (tempVagon = dynamic_cast<Vagon*>(matrizItems[2][4])) != NULL)
	{
		// mover jugador
		tempJugador->setYPos(6);
		tempJugador->setXPos(4);
		matrizItems[6][4] = matrizItems[2][3];
		matrizItems[2][3] = NULL;

		// mover vagon
		tempVagon->setYPos(2);
		tempVagon->setXPos(4);
		matrizItems[7][4] = matrizItems[2][4];
		matrizItems[2][4] = NULL;

		vagonMode = true;
	}
	else if (matrizItems[6][4] != NULL && dynamic_cast<Jugador*>(matrizItems[2][3]) == NULL
		&& (tempJugador = dynamic_cast<Jugador*>(matrizItems[6][4])) != NULL
		&& (tempVagon = dynamic_cast<Vagon*>(matrizItems[7][4])) != NULL)
	{
		// mover jugador
		tempJugador->setYPos(2);
		tempJugador->setXPos(3);
		matrizItems[2][3] = matrizItems[6][4];
		matrizItems[6][4] = NULL;

		// mover vagon
		tempVagon->setYPos(7);
		tempVagon->setXPos(4);
		matrizItems[2][4] = matrizItems[7][4];
		matrizItems[7][4] = NULL;

		vagonMode = true;
	}

	if (vagonMode)
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				if (matrizItems[i][j] == NULL)
					continue;
				else if (pistaVagon[i][j])
				{
					if ((tempJugador = dynamic_cast<Jugador*>(matrizItems[i][j])) != NULL)
					{
						tempJugador->kill();
						delete tempJugador;
						matrizItems[i][j] = NULL;
					}
					else if ((tempBomba = dynamic_cast<Bomba*>(matrizItems[i][j])) != NULL)
					{
						tempBomba->setTurno(0);
					}
				}
			}
		}
	}
}

void Tren::display()
{
	Jugador* tempJugador;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (pistaVagon[i][j])
				mvwaddch(currwin, i+1, j+1, '#');
			else
				mvwaddch(currwin, i+1, j+1, ' ');

			if (matrizItems[i][j] == NULL)
			{
				continue;
			}
			else if (dynamic_cast<Pared*>(matrizItems[i][j]) != NULL)
			{
				mvwaddch(currwin, i+1, j+1, '%');
			}
			else if (dynamic_cast<Vagon*>(matrizItems[i][j]) != NULL)
			{
				mvwaddch(currwin, i+1, j+1, 'W');
			}
			else if ((tempJugador = dynamic_cast<Jugador*>(matrizItems[i][j])) != NULL)
			{
				if (tempJugador->isBot())
					mvwaddch(currwin, i+1, j+1, 'o');
				else
					mvwaddch(currwin, i+1, j+1, '@');
			}
			else if (dynamic_cast<Normal*>(matrizItems[i][j]) != NULL)
			{
				mvwaddch(currwin, i+1, j+1, '*');
			}
			else if (dynamic_cast<Espina*>(matrizItems[i][j]) != NULL)
			{
				mvwaddch(currwin, i+1, j+1, 'x');
			}
			else if (dynamic_cast<BombaV*>(matrizItems[i][j]) != NULL)
			{
				mvwaddch(currwin, i+1, j+1, 'v');
			}
		}
	}
}
