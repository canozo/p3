#include "Escenario.h"
#include "Jugador.h"
#include <string>
#include <vector>
#include <ncurses.h>

using namespace std;

#ifndef TREN_H
#define TREN_H

class Tren : public Escenario
{
	private:
		int vagonX;
		int vagonY;
		bool** pistaVagon;

	public:
		Tren(WINDOW*, string, Jugador*, int);
		~Tren();
		void speedwagon();
		void display();
};

#endif
