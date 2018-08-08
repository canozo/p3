#include "Bomba.h"

#ifndef ESPINA_H
#define ESPINA_H

class Espina : public Bomba
{
	private:
		int cantidadBombasPorUsuario;
	public:
		Espina(int, int, int, int, int);
};

#endif