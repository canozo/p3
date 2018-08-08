#include "Escenario.h"
#include "Bomba.h"
#include "Normal.h"
#include "Espina.h"
#include "BombaV.h"
#include "Pared.h"
#include "Vagon.h"
#include "Jugador.h"
#include <string>
#include <vector>
#include <typeinfo>
#include <ncurses.h>
#include <stdlib.h>

using namespace std;

Escenario::Escenario(WINDOW* currwin, string name, Jugador* player, int tipoBomba)
{
	godmode = false;
	this->currwin = currwin;
	this->name = name;
	this->player = player;
	this->tipoBomba = tipoBomba;
	getmaxyx(currwin, yMax, xMax);

	bot_one = new Jugador(currwin, 0, 12, "Bot 1", true, true, 2);
	bot_two = new Jugador(currwin, 10, 0, "Bot 2", true, true, 3);
	bot_three = new Jugador(currwin, 10, 12, "Bot 3", true, true, 4);
	bot_four = new Jugador(currwin, 5, 6, "Bot 4", true, true, 5);

	fuego = new bool*[11];
	for (int i = 0; i < 11; i++)
	{
		fuego[i] = new bool[13];
		for (int j = 0; j < 13; j++)
		{
			fuego[i][j] = false;
		}
	}

	matrizItems = new Item**[11];
	for (int i = 0; i < 11; i++)
	{
		matrizItems[i] = new Item*[13];
		for (int j = 0; j < 13; j++)
		{
			matrizItems[i][j] = NULL;
		}
	}

	for (int i = 1; i < 10; i += 2)
	{
		for (int j = 1; j < 12; j += 2)
		{
			matrizItems[i][j] = new Pared(i, j);
		}
	}

	matrizItems[0][0] = player;
	matrizItems[0][12] = bot_one;
	matrizItems[10][0] = bot_two;
	matrizItems[10][12] = bot_three;
	matrizItems[5][6] = bot_four;
}

Escenario::~Escenario()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (matrizItems[i][j] != NULL)
			{
				delete matrizItems[i][j];
				matrizItems[i][j] = NULL;
			}
		}
		delete[] matrizItems[i];
		matrizItems[i] = NULL;
	}
	delete[] matrizItems;
	matrizItems = NULL;

	for (int i = 0; i < 11; i++)
	{
		delete[] fuego[i];
		fuego[i] = NULL;
	}
	delete[] fuego;
	fuego = NULL;

	bombas.clear();
}

int Escenario::getVidas()
{
	return vidas;
}

string Escenario::getName()
{
	return name;
}

void Escenario::clearFuego()
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 13; j++)
			fuego[i][j] = false;
}

void Escenario::checkAll()
{
	bombCheck(player);
	bombCheck(bot_one);
	bombCheck(bot_two);
	bombCheck(bot_three);
	bombCheck(bot_four);

	for (int i = 0; i < bombas.size(); i++)
		bombas[i]->disminuirTurno();
}

bool Escenario::victory()
{
	Jugador* tempJugador;
	int bot_count = 0;
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 13; j++)
			if (matrizItems[i][j] != NULL && (tempJugador = dynamic_cast<Jugador*>(matrizItems[i][j])) != NULL
				&& tempJugador->isBot())
				bot_count++;
	return bot_count == 0;
}

bool Escenario::gameover()
{
	bool over = true;
	Jugador* tempJugador;
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 13; j++)
			if (matrizItems[i][j] != NULL && (tempJugador = dynamic_cast<Jugador*>(matrizItems[i][j])) != NULL
				&& tempJugador->getID() == 1)
				over = false;
	return over;
}

void Escenario::explode(Bomba* bomba)
{
	Normal* tempBombaNormal;
	int yBomb = bomba->getYPos();
	int xBomb = bomba->getXPos();

	matrizItems[yBomb][xBomb] = NULL;
	clearFuego();
	fuego[yBomb][xBomb] = true;

	if ((tempBombaNormal = dynamic_cast<Normal*>(bomba)) != NULL)
	{
		int alcance = tempBombaNormal->getAlcance();
		int permutaciones[5] = {-1, 0, 1, 0, -1};
		int xSuma, ySuma, xPos, yPos, contador;
		for (int i = 0; i < 4; i++)
		{
			xSuma = permutaciones[i];
			ySuma = permutaciones[i + 1];
			xPos = xBomb + xSuma;
			yPos = yBomb + ySuma;
			contador = 0;

			while (xPos >= 0 && yPos >= 0 && xPos < 13 && yPos < 11 && contador < alcance)
			{
				if (matrizItems[yPos][xPos] != NULL && dynamic_cast<Pared*>(matrizItems[yPos][xPos]) != NULL)
					break;
				else if (matrizItems[yPos][xPos] != NULL && dynamic_cast<Vagon*>(matrizItems[yPos][xPos]) != NULL)
					break;
				else
					fuego[yPos][xPos] = true;

				xPos += xSuma;
				yPos += ySuma;
				contador++;
			}
		}
	}
	else if (dynamic_cast<Espina*>(bomba) != NULL)
	{
		int permutaciones[5] = {-1, 0, 1, 0, -1};
		int xSuma, ySuma, xPos, yPos;
		for (int i = 0; i < 4; i++)
		{
			xSuma = permutaciones[i];
			ySuma = permutaciones[i + 1];
			xPos = xBomb + xSuma;
			yPos = yBomb + ySuma;

			while (xPos >= 0 && yPos >= 0 && xPos < 13 && yPos < 11)
			{
				if (matrizItems[yPos][xPos] != NULL && dynamic_cast<Pared*>(matrizItems[yPos][xPos]) != NULL)
					break;
				else if (matrizItems[yPos][xPos] != NULL && dynamic_cast<Vagon*>(matrizItems[yPos][xPos]) != NULL)
					break;
				else
					fuego[yPos][xPos] = true;

				xPos += xSuma;
				yPos += ySuma;
			}
		}
	}
	else if (dynamic_cast<BombaV*>(bomba) != NULL)
	{
		int permutaciones[5] = {-1, -1, 1, 1, -1};
		int xSuma, ySuma, xPos, yPos;
		for (int i = 0; i < 4; i++)
		{
			xSuma = permutaciones[i];
			ySuma = permutaciones[i + 1];
			xPos = xBomb + xSuma;
			yPos = yBomb + ySuma;

			while (xPos >= 0 && yPos >= 0 && xPos < 13 && yPos < 11)
			{
				fuego[yPos][xPos] = true;
				xPos += xSuma;
				yPos += ySuma;
			}
		}
	}

	Jugador* tempJugador;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (fuego[i][j] && matrizItems[i][j] != NULL && (tempJugador = dynamic_cast<Jugador*>(matrizItems[i][j])) != NULL)
			{
				if (!tempJugador->isBot() && vidas - 1 > 0)
				{
					vidas--;
				}
				else if (!godmode)
				{
					tempJugador->kill();
					delete tempJugador;
					matrizItems[i][j] = NULL;
				}
			}
		}
	}

	switch (bomba->getOwner())
	{
		case 1:
			if (player != NULL)
				player->giveBomb();
			break;

		case 2:
			if (bot_one != NULL)
				bot_one->giveBomb();
			break;

		case 3:
			if (bot_two != NULL)
				bot_two->giveBomb();
			break;

		case 4:
			if (bot_three != NULL)
				bot_three->giveBomb();
			break;

		case 5:
			if (bot_four != NULL)
				bot_four->giveBomb();
			break;

		default:
			break;
	}
}

void Escenario::bombCheck(Jugador* player)
{
	int xBomb, yBomb;
	Bomba* tempBomba;

	for (int i = bombas.size() - 1; i >= 0; i--)
	{
		if (bombas[i]->getTurno() == 0)
		{
			explode(bombas[i]);
			delete bombas[i];
			bombas[i] = NULL;
			bombas.erase(bombas.begin() + i);
		}
	}

	if (player != NULL && player->getBomb())
	{
		xBomb = player->getXBomb();
		yBomb = player->getYBomb();

		switch(tipoBomba)
		{
			case 1:
				tempBomba = new Normal(yBomb, xBomb, 12, player->getID(), rand() % 4 + 1);
				matrizItems[yBomb][xBomb] = tempBomba;
				bombas.push_back(tempBomba);
				break;

			case 2:
				tempBomba = new Espina(yBomb, xBomb, 12, player->getID(), 3 - player->getDisponibles());
				matrizItems[yBomb][xBomb] = tempBomba;
				bombas.push_back(tempBomba);
				break;

			case 3:
				tempBomba = new BombaV(yBomb, xBomb, 12, player->getID());
				matrizItems[yBomb][xBomb] = tempBomba;
				bombas.push_back(tempBomba);
				break;

			default:
				break;
		}
	}
}

void Escenario::mv(Jugador* player)
{
	matrizItems[player->getYPos()][player->getXPos()] = NULL;
	player->setYPos(player->getYPos() + player->getYLast());
	player->setXPos(player->getXPos() + player->getXLast());
	matrizItems[player->getYPos()][player->getXPos()] = player;
}

void Escenario::moveBots()
{
	if (bot_one->isAlive())
		botAI(bot_one);

	if (bot_two->isAlive())
		botAI(bot_two);

	if (bot_three->isAlive())
		botAI(bot_three);

	if (bot_four->isAlive())
		botAI(bot_four);
}

void Escenario::botAI(Jugador* bot)
{
	int topSecretStateOfTheArtArtificialIntelligenceSoftwareDevice_V3 = rand() % 4 + 1;

	switch (topSecretStateOfTheArtArtificialIntelligenceSoftwareDevice_V3)
	{
		case 1:
			bot->mvup();
			if (vacio(bot))
				mv(bot);
			break;

		case 2:
			bot->mvdown();
			if (vacio(bot))
				mv(bot);
			break;

		case 3:
			bot->mvleft();
			if (vacio(bot))
				mv(bot);
			break;

		case 4:
			bot->mvright();
			if (vacio(bot))
				mv(bot);
			break;

		default:
			break;
	}

	if (topSecretStateOfTheArtArtificialIntelligenceSoftwareDevice_V3 % 2 == 0)
		bot->setBomb();
}

bool Escenario::vacio(Jugador* player)
{
	return matrizItems[player->getYPos()+player->getYLast()][player->getXPos()+player->getXLast()] == NULL;
}
