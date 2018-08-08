#include "Alumno.h"
#include <string>

using namespace std;

Alumno::Alumno() : Persona()
{
	carrera = "IS";
};

Alumno::Alumno(int codigo, string nombre, string carrera) : Persona(codigo, nombre)
{
	this->carrera = carrera;
}

void Alumno::setCarrera(string carrera)
{
	this->carrera = carrera;
}

string Alumno::getCarrera()
{
	return carrera;
}
