#include "Thread.h"
#include "Server.h"
#include "Client.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int opcion;
	do
	{
		cout << "\nMENU\n"
			<< "Seleccione una opcion: ";

		cin >> opcion;
		switch (opcion)
		{
			default:
				break;
		}
	}
	while(opcion != 0);
	return 0;
}
