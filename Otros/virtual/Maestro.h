#include "Persona.h"
#include <string>

#ifndef MAESTRO_H
#define MAESTRO_H

class Maestro : public Persona
{
	private:
		int numEmpleado;

	public:
		Maestro(int, int, int);
		std::string getType();
		virtual std::string getInfo();
};

#endif
