#include <string>

using namespace std;

#ifndef FIGURA_H
#define FIGURA_H

class Figura
{
	private:
	public:
		// virtual
		virtual double getArea();
		
		// virtual puro
		virtual string toString() = 0;
};

#endif
