#include "Personaje.h"

using namespace std;

#ifndef BRUTE_H
#define BRUTE_H

class Brute : public Personaje
{
	public:
		Brute(string, int, int, int, int);
		void poderEspecial();
};

#endif
