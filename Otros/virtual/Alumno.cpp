#include "Alumno.h"
#include <sstream>

Alumno::Alumno(int id, int edad, int cuenta)
{
	this->id = id;
	this->edad = edad;
	this->cuenta = cuenta;
}

std::string Alumno::getInfo()
{
	std::stringstream out;
	out << "ID: " << id << ", EDAD: " << edad << ", CUENTA: " << cuenta;
	return out.str();
}

std::string Alumno::getType(){ return "Alumno"; }
