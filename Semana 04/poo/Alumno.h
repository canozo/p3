#include "Persona.h"
#include <string>

using namespace std;

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno: public Persona
{
	private:
		string carrera;

	public:
		Alumno();
		Alumno(int, string, string);

		void setCarrera(string);
		string getCarrera();
		// no lleva destructor
};

#endif
