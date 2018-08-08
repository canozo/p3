#include "Invisible.h"
#include "Pared.h"
#include "Jugador.h"
#include "Bomba.h"
#include "Normal.h"
#include "Espina.h"
#include "BombaV.h"
#include <stdlib.h>


Invisible::Invisible(WINDOW* currwin, string name, Jugador* player, int tipoBomba) : Escenario(currwin, name, player, tipoBomba)
{
	this->vidas = rand() % 3 + 1;
}

void Invisible::display()
{
	Jugador* tempJugador;
	Bomba* tempBomba;
	int numBombas = 0;

	for (int i = 0; i < bombas.size(); i++)
		if (bombas[i]->getOwner() != 1)
			numBombas++;
	numBombas = numBombas / 2;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			mvwaddch(currwin, i+1, j+1, ' ');
			if (matrizItems[i][j] == NULL)
			{
				continue;
			}
			else if (dynamic_cast<Pared*>(matrizItems[i][j]) != NULL)
			{
				mvwaddch(currwin, i+1, j+1, '%');
			}
			else if ((tempJugador = dynamic_cast<Jugador*>(matrizItems[i][j])) != NULL)
			{
				if (tempJugador->isBot())
					mvwaddch(currwin, i+1, j+1, 'o');
				else
					mvwaddch(currwin, i+1, j+1, '@');
			}
			else if ((tempBomba = dynamic_cast<Normal*>(matrizItems[i][j])) != NULL)
			{
				if (tempBomba->getOwner() == 1)
				{
					mvwaddch(currwin, i+1, j+1, '*');
				}
				else if (numBombas > 0)
				{
					mvwaddch(currwin, i+1, j+1, '*');
					numBombas--;
				}
			}
			else if ((tempBomba = dynamic_cast<Espina*>(matrizItems[i][j])) != NULL)
			{
				if (tempBomba->getOwner() == 1)
				{
					mvwaddch(currwin, i+1, j+1, 'x');
				}
				else if (numBombas > 0)
				{
					mvwaddch(currwin, i+1, j+1, 'x');
					numBombas--;
				}
			}
			else if ((tempBomba = dynamic_cast<BombaV*>(matrizItems[i][j])) != NULL)
			{
				if (tempBomba->getOwner() == 1)
				{
					mvwaddch(currwin, i+1, j+1, 'v');
				}
				else if (numBombas > 0)
				{
					mvwaddch(currwin, i+1, j+1, 'v');
					numBombas--;
				}
			}
		}
	}
}
