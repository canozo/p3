#ifndef ATAQUE_H
#define ATAQUE_H

class Ataque
{
	private:
		int potencia;
		int recursos;

	public:
		Ataque(int, int);
		void setPotencia(int);
		int getPotencia();
		void setRecursos(int);
		int getRecursos();
};

#endif
