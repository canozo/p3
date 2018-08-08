#include "DataPersonaje.h"

using namespace std;

int main()
{
	DataPersonaje* data = new DataPersonaje();
	data->getPersonajes("Personajes.txt");
	delete data;
	return 0;
}
