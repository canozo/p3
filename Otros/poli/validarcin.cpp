#include "validarcin.h"
#include <iostream>
#include <string>

using namespace std;

int validarCinInt(string mensaje)
{
	int result = 0;
	bool salir = false;
	do
	{
		cout << mensaje;
		if (!(cin >> result))
		{
			cout << "Por favor no ingrese caracteres!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			salir = true;
		}
	}
	while (!salir);
	return result;
}

string validarCinString(string mensaje)
{
	string result;
	bool salir = false;
	do
	{
		cout << mensaje;
		if (!(cin >> result))
		{
			cout << "Por favor no ingrese caracteres invalidos!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			salir = true;
		}
	}
	while (!salir);
	return result;
}
