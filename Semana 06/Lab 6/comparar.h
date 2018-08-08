#include "Animal.h"

bool compararAnimales(Animal* a, Animal* b)
{
	return a->getNombre() < b->getNombre();
}
