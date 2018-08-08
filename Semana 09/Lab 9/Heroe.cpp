#include "Heroe.h"
#include <fstream>

void Heroe::guardar(ofstream& out)
{
	// string nombre
	int size = nombre.size();
	out.write(reinterpret_cast<char*>(&size), sizeof(int));
	out.write(nombre.data(), size);

	// int vida
	out.write(reinterpret_cast<char*>(&vida), sizeof(int));

	// int vida max
	out.write(reinterpret_cast<char*>(&vidaMax), sizeof(int));

	// int jefes derrotados
	out.write(reinterpret_cast<char*>(&jefesDerrotados), sizeof(int));

	// int dinero
	out.write(reinterpret_cast<char*>(&dinero), sizeof(int));

}

void Heroe::derrotado()
{
	dinero /= 2;
	curar();
}


void Heroe::atacar(Monstruo* monstruo)
{
	int vidaMon = monstruo->getVida();
	vidaMon -= (ataque - monstruo->getDefensa());
	monstruo->setVida(vidaMon);
}

void Heroe::atacarEspecial(Monstruo* monstruo)
{
	if (especialDisponible && especial > 0)
	{
		int vidaMon = monstruo->getVida();
		vidaMon -= (especial - monstruo->getDefensa());
		monstruo->setVida(vidaMon);
		especialDisponible = false;
	}
}

void Heroe::cargar(ifstream& in)
{
	int size;

	// string nombre
	in.read(reinterpret_cast<char*>(&size), sizeof(int));
	char nombreBuffer[size];
	in.read(nombreBuffer, size);
	nombre = nombreBuffer;

	// int vida
	in.read(reinterpret_cast<char*>(&vida), sizeof(int));

	// int vida max
	in.read(reinterpret_cast<char*>(&vidaMax), sizeof(int));

	// int jefes derrotados
	in.read(reinterpret_cast<char*>(&jefesDerrotados), sizeof(int));

	// int dinero
	in.read(reinterpret_cast<char*>(&dinero), sizeof(int));
}

void Heroe::curar()
{
	vida = vidaMax;
}

string Heroe::getNombre()
{
	return nombre;
}

bool Heroe::puedeCrecer()
{
	return jefesDerrotados >= 3;
}

void Heroe::comprar()
{
	if (dinero >= 200)
	{
		vidaMax += 4;
		dinero -= 200;
	}
}

int Heroe::getDefensa()
{
	return defensa;
}

int Heroe::getVida()
{
	return vida;
}

void Heroe::setVida(int vida)
{
	this->vida = vida;
}

int Heroe::getDinero()
{
	return dinero;
}

void Heroe::setDinero(int dinero)
{
	this->dinero = dinero;
}

int Heroe::getJefesDerrotados()
{
	return jefesDerrotados;
}

void Heroe::setJefesDerrotados(int jefesDerrotados)
{
	this->jefesDerrotados = jefesDerrotados;
}

int Heroe::getVidaMax()
{
	return vidaMax;
}

void Heroe::setVidaMax(int vidaMax)
{
	this->vidaMax = vidaMax;
}

Item* Heroe::getItem()
{
	return item;
}

void Heroe::setItem(Item* item)
{
	this->item = item;
}
