#include "Carro.h"

#ifndef PARQUEO_H
#define PARQUEO_H

class Parqueo
{
	private:
		int pisos;
		int largo;
		int ancho;
		int alturaMax;
		Carro**** cuboParqueo;

	public:
		// constructores
		Parqueo();
		Parqueo(int, int, int, int);

		// mutadores
		int getPisos();
		void setPisos(int);

		int getLargo();
		void setLargo(int);

		int getAncho();
		void setAncho(int);

		int getAlturaMax();
		void setAlturaMax(int);

		// metodos
		void parquear(int, Carro*);
		void salir(int, int, int);
		void mostrarParqueos(int);
		void mostrarPiso(int);

		~Parqueo();
};

#endif
