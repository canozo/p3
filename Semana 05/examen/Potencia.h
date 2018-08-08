#ifndef POTENCIA_H
#define POTENCIA_H

class Potencia
{
	private:
		int a;
		int b;
		// metodo pow recursivo
		int powRecursiva(int, int);

	public:
		// constructor
		Potencia(int, int);
		// mutadores
		int getA();
		void setA(int);
		int getB();
		void setB(int);
		// metodo pow
		int pow();
};

#endif
