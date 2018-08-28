#include "Maestro.h"
#include "validarcin.h"
#include <iostream>
#include <string>

using namespace std;

Maestro::Maestro()
{
	nombre = validarCinString("Ingrese el nombre de la persona: ");
	edad = validarCinInt("Ingrese la edad de la persona: ");
	codigo = validarCinInt("Ingrese el codigo de empleado: ");
	sueldo = validarCinInt("Ingrese el sueldo: ");
}

void Maestro::modificar()
{
	// TODO mostrar valor viejo
	nombre = validarCinString("Ingrese el nombre de la persona: ");
	edad = validarCinInt("Ingrese la edad de la persona: ");
	codigo = validarCinInt("Ingrese el codigo de empleado: ");
	sueldo = validarCinInt("Ingrese el sueldo: ");
}

void Maestro::informacion()
{
	cout << "Informacion del maestro " << nombre << endl;
	cout << "\tEdad: " << edad << endl;
	cout << "\tCodigo de empleado: " << codigo << endl;
	cout << "\tSueldo: " << sueldo << endl;
}

int Maestro::getCodigo()
{
	return codigo;
}

void Maestro::setCodigo(int codigo)
{
	this->codigo = codigo;
}

int Maestro::getSueldo()
{
	return sueldo;
}

void Maestro::setSueldo(int sueldo)
{
	this->sueldo = sueldo;
}
