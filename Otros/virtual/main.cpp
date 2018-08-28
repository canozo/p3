#include "Persona.h"
#include "Alumno.h"
#include "Maestro.h"
#include <iostream>

void mostrarType(Persona*);

int main()
{
	Persona* p1 = new Alumno(1, 2, 3);
	Persona* p2 = new Maestro(3, 4, 5);

	std::cout << p1->getInfo() << std::endl;
	std::cout << p2->getInfo() << std::endl;

	std::cout << std::endl;

	mostrarType(p1);
	mostrarType(p2);

	delete p1;
	delete p2;
	return 0;
}

void mostrarType(Persona* persona)
{
	std::cout << persona->getType() << std::endl;
}
