#include "Escenario.h"
#include "Jugador.h"
#include <ncurses.h>
#include <string>
#include <vector>

using namespace std;

#ifndef INVISIBLE_H
#define INVISIBLE_H

class Invisible : public Escenario
{
	private:
		int tipoBomba;

	public:
		Invisible(WINDOW*, string, Jugador*, int);
		void display();
};

#endif
