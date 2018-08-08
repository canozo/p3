#include "Figura.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>

using namespace std;

void informacion(Figura*);	// mostrar informacion de una figura
void vidaVector();			// observar la vida de un vector

int main()
{
	// parte uno
	Figura* circulo = new Circulo(10);
	Figura* rectangulo = new Rectangulo(10, 20);
	informacion(circulo);
	informacion(rectangulo);
	delete circulo;
	delete rectangulo;

	// parte dos
	vidaVector();
	return 0;
}

// mostrar informacion de una figura
void informacion(Figura* figura)
{
	cout << figura->toString() << endl;
	cout << "Su area es: " << figura->getArea() << endl;
	cout << "La var figura es tipo " << typeid(*figura).name() << endl;
}

// observar la vida de un vector
void vidaVector()
{
	vector<Figura*> baseFiguras;
	for (int i = 1; i <= 10; i++)
		baseFiguras.push_back(new Circulo(i));

	double areaTotal = 0;
	for (int i = 0; i < baseFiguras.size(); i++)
		areaTotal += baseFiguras[i]->getArea();
	cout << "El area total es " << areaTotal << endl;

	for (int i = 0; i < baseFiguras.size(); i++)
	{
		delete baseFiguras[i];
		baseFiguras[i] = NULL;
	}
	baseFiguras.clear();
}
