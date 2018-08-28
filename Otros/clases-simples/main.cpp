#include "Dragon.h"
#include <iostream>
#include <string>

using namespace std;

void invocar();

int main()
{
	invocar();
	return 0;
}

void invocar()
{
	Dragon* droggo = new Dragon(500, 125, "Droggo");
	cout << "Vida: " << droggo->getVida() << endl;
	cout << "Defensa: " << droggo->getDefensa() << endl;
	cout << "Nombre: " << droggo->getNombre() << endl;

	droggo->setVida(375);
	cout << "Vida: " << droggo->getVida() << endl;
}
