#ifndef ARCO_H
#define ARCO_H

#include "Item.h"
#include "Heroe.h"
#include "Monstruo.h"
#include <string>

using namespace std;

class Arco : public Item
{
	public:
		Arco(string, string);
		void utilizar(Heroe*, Monstruo*);
};

#endif