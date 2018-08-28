#include "Maestro.h"
#include <sstream>

Maestro::Maestro(int id, int edad, int numEmpleado)
{
	this->id = id;
	this->edad = edad;
	this->numEmpleado = numEmpleado;
}

std::string Maestro::getInfo()
{
	std::stringstream out;
	out << "ID: " << id << ", EDAD: " << edad << ", NUM DE EMPLEADO: " << numEmpleado;
	return out.str();
}

std::string Maestro::getType(){ return "Maestro"; }
