#include <string>

using namespace std;

#ifndef FIGURA_H
#define FIGURA_H

class Figura
{
	private:
	public:
		Figura();
		// metodos virtuales puros
		virtual double getArea() = 0;
		virtual double getPerimetro() = 0;
		virtual string toString() = 0;
};

#endif
