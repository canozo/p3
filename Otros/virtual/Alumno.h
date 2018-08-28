#include "Persona.h"
#include <string>

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno : public Persona
{
	private:
		int cuenta;

	public:
		Alumno(int, int, int);
		std::string getType();
		virtual std::string getInfo();
};

#endif
