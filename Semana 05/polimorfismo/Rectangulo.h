#include "Figura.h"

using namespace std;

#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo : public Figura
{
	private:
		double largo;
		double ancho;
	public:
		Rectangulo(double, double);
		Rectangulo();
		virtual double getArea();
		virtual double getPerimetro();
		virtual string toString();
};

#endif
