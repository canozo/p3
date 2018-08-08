#include <string>
#include "Personaje.h"

using namespace std;

#ifndef ASSASSIN_H
#define ASSASSIN_H

class Assassin : public Personaje
{
	public:
		Assassin(string, int, int, int, int);
		void poderEspecial();
};

#endif
