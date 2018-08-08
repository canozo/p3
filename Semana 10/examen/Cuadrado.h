#include "Figura.h"
// #include <string>

using namespace std;

#ifndef CUADRADO_H
#define CUADRADO_H

class Cuadrado : public Figura
{
	private:
		double largo;
	public:
		Cuadrado(double);
		virtual double getArea();
		virtual string toString();
};

#endif
