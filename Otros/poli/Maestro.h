#include "Persona.h"
#include <string>

using namespace std;

#ifndef MAESTRO_H
#define MAESTRO_H

class Maestro : public Persona
{
	private:
		int codigo;
		int sueldo;
	public:
		Maestro();
		int getCodigo();
		void setCodigo(int);
		int getSueldo();
		void setSueldo(int);
		virtual void modificar();
		virtual void informacion();
};

#endif
