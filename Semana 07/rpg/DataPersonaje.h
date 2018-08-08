#include "Personaje.h"
#include <string>
#include <vector>

using namespace std;

#ifndef DATAPERSONAJE_H
#define DATAPERSONAJE_H

class DataPersonaje
{
	private:
		Personaje* parse(string);

	public:
		DataPersonaje();
		vector<Personaje*> getPersonajes(string);
};

#endif
