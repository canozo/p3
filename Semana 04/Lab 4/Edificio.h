#ifndef EDIFICIO_H
#define EDIFICIO_H

class Edificio
{
	private:
		int capPersonas;
		int pisos;

	public:
		// constructores
		Edificio();
		Edificio(int, int);

		// mutadores
		int getCapPersonas();
		void setCapPersonas(int);

		int getPisos();
		void setPisos(int);
};

#endif
