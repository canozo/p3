#include <string>

using namespace std;

#ifndef CARRO_H
#define CARRO_H

class Carro
{
	private:
		string color;
		string marca;
		int altura;

	public:
		// constructores
		Carro();
		Carro(string, string, int);

		// mutadores
		string getColor();
		void setColor(string);

		string getMarca();
		void setMarca(string);

		int getAltura();
		void setAltura(int);
};

#endif
