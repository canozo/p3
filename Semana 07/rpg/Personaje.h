#include "Normal.h"
#include "Especial.h"
#include <string>

using namespace std;

#ifndef PERSONAJE_H
#define PERSONAJE_H

class Personaje
{
	private:
		string nombre;
		int HP, defensa;
		Normal* normal;
		Especial* especial;

	public:
		Personaje(string, int, int, int, int);
		~Personaje();

		string getNombre();
		void setNombre(string);
		int getHP();
		void setHP(int);
		Normal* getNormal();
		void setNormal(Normal*);
		Especial* getEspecial();
		void setEspecial(Especial*);
		int getDefensa();
		void setDefensa(int);
		int getPoderEspecial();
		void setPoderEspecial(int);
		virtual void poderEspecial() = 0;
};

#endif
