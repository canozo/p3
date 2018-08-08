#include "Circulo.h"
#include <sstream>

#define PI 3.14159265

using namespace std;

Circulo::Circulo(double radio)
{
	this->radio = radio;
}

double Circulo::getArea()
{
	return PI * radio * radio;
}

string Circulo::toString()
{
	return "Circulo";
	// stringstream out;
	// out << "Esto es un circulo de radio " << radio;
	// return out.str();
}
