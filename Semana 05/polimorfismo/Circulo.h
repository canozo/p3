#include "Figura.h"
#include <string>

using namespace std;

#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo : public Figura
{
	private:
		double radio;
	public:
		Circulo(double);
		Circulo();
		double getArea();
		double getPerimetro();
		string toString();
};

#endif
