#include "Patas.h"
#include "Pelaje.h"
#include "Ojos.h"
#include "Orejas.h"
#include "Cola.h"
#include <string>

using namespace std;

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
	private:
		string especie;
		string nombre;
		int tamanio;
		int tipo;
		Patas* patas;
		Pelaje* pelaje;
		Ojos* ojos;
		Orejas* orejas;
		Cola* cola;

	public:
		Animal(string, string, int, int, Patas*, Pelaje*, Ojos*, Orejas*, Cola*);
		~Animal();
		string getNombre();
		int getTipo();
		string informacion();
};

#endif
