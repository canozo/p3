#include "Persona.h"
#include <string>

using namespace std;

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno : public Persona
{
	private:
		int cuenta;
		int clases;
	public:
		Alumno();
		int getCuenta();
		void setCuenta(int);
		int getClases();
		void setClases(int);
		virtual void modificar();
		virtual void informacion();
};

#endif
