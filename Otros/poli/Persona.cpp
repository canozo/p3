#include "Persona.h"
#include <iostream>
#include <string>

using namespace std;

int Persona::getEdad()
{
	return edad;
}

void Persona::setEdad(int edad)
{
	this->edad = edad;
}

string Persona::getNombre()
{
	return nombre;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}
