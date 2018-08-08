#include "Cuadrado.h"
#include <sstream>

using namespace std;

Cuadrado::Cuadrado(double largo)
{
	this->largo = largo;
}

double Cuadrado::getArea()
{
	return largo * largo;
}

string Cuadrado::toString()
{
	return "Cuadrado";
	// stringstream out;
	// out << "Esto es un cuadrado de largo " << largo;
	// return out.str();
}
