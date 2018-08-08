#include "Circulo.h"
#include <sstream>

#define PI 3.14159265

using namespace std;

Circulo::Circulo()
{
	radio = 1;
}

Circulo::Circulo(double radio)
{
	this->radio = radio;
}

double Circulo::getArea()
{
	return PI * radio * radio;
}

double Circulo::getPerimetro()
{
	return 2 * PI * radio;
}

string Circulo::toString()
{
	string result;
	stringstream out;
	out << "Esto es un circulo de radio " << radio;
	getline(out, result);
	return result;
}
