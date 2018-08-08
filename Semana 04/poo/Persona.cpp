#include "Persona.h"
#include <string>
#include <iostream>

using namespace std;

Persona::Persona()
{
	codigo = 504;
	nombre = "Juan Pueblo";
}

Persona::Persona(int codigo, string nombre)
{
	this->codigo = codigo;
	this->nombre = nombre;
}

int Persona::getCodigo()
{
	return codigo;
}

void Persona::setCodigo(int codigo)
{
	this->codigo = codigo;
}

string Persona::getNombre()
{
	return nombre;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}

Persona::~Persona()
{
	cout << "destructor" << endl;
}
