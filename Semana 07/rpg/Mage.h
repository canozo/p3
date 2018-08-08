#include <string>
#include "Personaje.h"

using namespace std;

#ifndef MAGE_H
#define MAGE_H

class Mage : public Personaje
{
	public:
		Mage(string, int, int, int, int);
		void poderEspecial();
};

#endif
