#include "Persona.h"
#include <iostream>

Persona::Persona(string nombre)
{
	cout << "Creando a " << nombre << endl;
	this->nombre = nombre;
}

Persona::~Persona()
{
	cout << "Destruyendo a " << nombre << endl;
}

void Persona::mostrarNombre()
{
	cout << "Mi nombre es " << nombre << endl;
}
