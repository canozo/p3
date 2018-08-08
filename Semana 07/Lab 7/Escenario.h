#include "Item.h"
#include "Bomba.h"
#include "Jugador.h"
#include <string>
#include <vector>
#include <ncurses.h>

using namespace std;

#ifndef ESCENARIO_H
#define ESCENARIO_H

class Escenario
{
	protected:
		Jugador* player;
		Jugador* bot_one;
		Jugador* bot_two;
		Jugador* bot_three;
		Jugador* bot_four;
		WINDOW* currwin;
		int xMax, yMax, tipoBomba, vidas;
		string name;
		Item*** matrizItems;
		bool** fuego;
		vector<Bomba*> bombas;
		bool godmode;

	public:
		Escenario(WINDOW*, string, Jugador*, int);
		~Escenario();
		virtual string getName();
		int getVidas();
		void clearFuego();
		void explode(Bomba*);
		void bombCheck(Jugador*);
		void botAI(Jugador*);
		void moveBots();
		bool victory();
		bool gameover();
		bool vacio(Jugador*);
		void checkAll();
		void mv(Jugador*);
		virtual void display() = 0;
};

#endif
