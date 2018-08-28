#include "Alumno.h"
#include "validarcin.h"
#include <iostream>
#include <string>

using namespace std;

Alumno::Alumno()
{
	nombre = validarCinString("Ingrese el nombre de la persona: ");
	edad = validarCinInt("Ingrese la edad de la persona: ");
	cuenta = validarCinInt("Ingrese el numero de cuenta: ");
	clases = validarCinInt("Ingrese el numero de clases: ");
}

void Alumno::modificar()
{
	// TODO mostrar valor viejo
	nombre = validarCinString("Ingrese el nombre de la persona: ");
	edad = validarCinInt("Ingrese la edad de la persona: ");
	cuenta = validarCinInt("Ingrese el numero de cuenta: ");
	clases = validarCinInt("Ingrese el numero de clases: ");
}

void Alumno::informacion()
{
	cout << "Informacion del alumno " << nombre << endl;
	cout << "\tEdad: " << edad << endl;
	cout << "\tNumero de cuenta: " << cuenta << endl;
	cout << "\tNumero de clases: " << clases << endl;
}

int Alumno::getCuenta()
{
	return cuenta;
}

void Alumno::setCuenta(int cuenta)
{
	this->cuenta = cuenta;
}

int Alumno::getClases()
{
	return clases;
}

void Alumno::setClases(int clases)
{
	this->clases = clases;
}
