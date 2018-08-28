#include <string>

#ifndef PERSONA_H
#define PERSONA_H

class Persona
{
	protected:
		int id;
		int edad;

	public:
		int getEdad();
		int getId();
		virtual std::string getType();
		virtual std::string getInfo() = 0;
};

#endif
