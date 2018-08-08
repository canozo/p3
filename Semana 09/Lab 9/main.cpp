#include "Adulto.h"
#include "Arco.h"
#include "Bomba.h"
#include "Boomerang.h"
#include "Comun.h"
#include "Heroe.h"
#include "Item.h"
#include "Jefe.h"
#include "Joven.h"
#include "Monstruo.h"
#include "Semijefe.h"
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

void cargarHeroe(Heroe*&);
void guardarHeroe(Heroe*&);
void agregarItem(vector<Item*>&);
int buscarItem(vector<Item*>);
void agregarMonstruo(vector<Monstruo*>&);
void eliminarMonstruo(vector<Monstruo*>&);
int buscarMonstruo(vector<Monstruo*>);
bool batallar(Heroe*&, Monstruo*&);

using namespace std;

int main()
{
	string tempNombre;
	cout << "Ingrese el nombre del heroe: ";
	cin >> tempNombre;
	Heroe* heroe = new Joven(tempNombre);
	vector<Monstruo*> baseMonstruos;
	vector<Item*> baseItems;
	bool modoBatalla = false;
	int opcion, pos;
	do
	{

		cout << "\nMENU PRINCIPAL\n"
			<< "1) Guardar jugador\n"
			<< "2) Cargar jugador\n"
			<< "3) Agregar item\n"
			<< "4) Agregar monstruo\n"
			<< "5) Eliminar monstruo\n"
			<< "6) Comprar corazon\n"
			<< "7) Sacar la Master Sword\n"
			<< "8) Guardar la Master Sword\n"
			<< "9) Entrar en batalla\n"
			<< "10) Cambiar item\n"
			<< "11) Informacion del jugador\n"
			<< "0) Salir\n"
			<< "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
			case 1:
				// guardar
				guardarHeroe(heroe);
				break;

			case 2:
				// cargar
				cargarHeroe(heroe);
				break;

			case 3:
				// agregar item
				agregarItem(baseItems);
				break;

			case 4:
				// agregar monstro
				agregarMonstruo(baseMonstruos);
				break;

			case 5:
				// eliminar monstro
				if (baseMonstruos.size() > 0)
				{
					eliminarMonstruo(baseMonstruos);
				}
				else
				{
					cout << "No hay monstruos disponibles!" << endl;
				}
				break;

			case 6:
				// comprar corazon
				heroe->comprar();
				break;

			case 7:
				// sacar la master sword
				if (dynamic_cast<Joven*>(heroe) != NULL && heroe->puedeCrecer())
				{
					Heroe* tempHeroe = new Adulto(heroe->getNombre());
					tempHeroe->setVida(heroe->getVida());
					tempHeroe->setVidaMax(heroe->getVidaMax());
					tempHeroe->setJefesDerrotados(heroe->getJefesDerrotados());
					tempHeroe->setDinero(heroe->getDinero());
					delete heroe;
					heroe = tempHeroe;
				}
				else
				{
					cout << "No puede sacar la master sword!" << endl;
				}
				break;

			case 8:
				// quitar la master sword
				if (dynamic_cast<Adulto*>(heroe) != NULL)
				{
					Heroe* tempHeroe = new Joven(heroe->getNombre());
					tempHeroe->setVida(heroe->getVida());
					tempHeroe->setVidaMax(heroe->getVidaMax());
					tempHeroe->setJefesDerrotados(heroe->getJefesDerrotados());
					tempHeroe->setDinero(heroe->getDinero());
					delete heroe;
					heroe = tempHeroe;
				}
				else
				{
					cout << "No puede guardar la Master Sword!" << endl;
				}
				break;

			case 9:
				// entrar en batalla
				if (baseMonstruos.size() > 0)
				{
					pos = buscarMonstruo(baseMonstruos);
					if (!batallar(heroe, baseMonstruos[pos]))
					{
						heroe->derrotado();
					}
					else
					{
						baseMonstruos[pos]->derrotado(heroe);
						delete baseMonstruos[pos];
						baseMonstruos.erase(baseMonstruos.begin() + pos);
					}
				}
				else
				{
					cout << "No hay monstruos disponibles!" << endl;
				}
				break;

			case 10:
				// cambiar item
				if (baseItems.size() > 0)
				{
					pos = buscarItem(baseItems);
					heroe->setItem(baseItems[pos]);
				}
				else
				{
					cout << "No hay items disponibles!" << endl;
				}
				break;

			case 11:
				// informacion del jugador
				cout << "INFORMACION" << endl
					<< "JUGADOR: " << heroe->getNombre() << endl
					<< "VIDA MAX: " << heroe->getVidaMax() << endl
					<< "DINERO: " << heroe->getDinero() << endl
					<< "JEFES DERROTADOS " << heroe->getJefesDerrotados() << endl;
				break;

			case 0:
				cout << "Saliendo..." << endl;
				break;

			default:
				cout << "Opcion no valida!" << endl;
				break;
		}
	}
	while(opcion != 0);
	return 0;
}

void guardarHeroe(Heroe*& heroe)
{
	ofstream archivo("Heroe.bin", ios::binary);
	heroe->guardar(archivo);
	archivo.close();
}

void cargarHeroe(Heroe*& heroe)
{
	ifstream archivo("Heroe.bin", ios::binary);
	heroe->cargar(archivo);
	archivo.close();
}

void agregarItem(vector<Item*>& items)
{
	string tempNombre, tempColor;
	int tipoItem;

	cout << "Ingrese el nombre de item: ";
	cin >> tempNombre;

	cout << "Ingrese el color del item: ";
	cin >> tempColor;

	do
	{
		cout << "Ingrese el tipo de item:\n"
			<< "1) Boomerang\n"
			<< "2) Arco y flecha\n"
			<< "3) Bomba\n"
			<< "Seleccione un item: ";
		cin >> tipoItem;
	}
	while (tipoItem != 1 && tipoItem != 2 && tipoItem != 3);


	if (tipoItem == 1)
		items.push_back(new Boomerang(tempNombre, tempColor));
	else if (tipoItem == 2)
		items.push_back(new Arco(tempNombre, tempColor));
	else
		items.push_back(new Bomba(tempNombre, tempColor));
}

int buscarItem(vector<Item*> items)
{
	int pos;
	cout << "Items disponibles: " << endl;
	for (int i = 0; i < items.size(); i++)
		if (dynamic_cast<Bomba*>(items[i]) != NULL)
			cout << i << ") Bomba " << items[i]->getNombre() << endl;

		else if (dynamic_cast<Boomerang*>(items[i]) != NULL)
			cout << i << ") Boomerang " << items[i]->getNombre() << endl;

		else if (dynamic_cast<Arco*>(items[i]) != NULL)
			cout << i << ") Arco y flecha " << items[i]->getNombre() << endl;

	cout << "Seleccione una posicion: ";
	do
		cin >> pos;
	while (pos < 0 || pos >= items.size());
	return pos;
}

void agregarMonstruo(vector<Monstruo*>& monstruos)
{
	string tempNombre, tempDebilidadStr;
	int tempVida, tempDebilidad, tipoMonstruo;

	do
	{
		cout << "Ingrese el tipo de monstruo:\n"
			<< "1) Comun\n"
			<< "2) Semijefe\n"
			<< "3) Jefe\n";
		cin >> tipoMonstruo;
	}
	while (tipoMonstruo != 1 && tipoMonstruo != 2 && tipoMonstruo != 3);

	cout << "Inrese el nombre del monstruo: ";
	cin >> tempNombre;

	do
	{
		cout << "Ingrese la debilidad del monstruo:\n"
			<< "1) Boomerang\n"
			<< "2) Bomba\n"
			<< "3) Arco y felchas\n";
		cin >> tempDebilidad;
	}
	while (tempDebilidad != 1 && tempDebilidad != 2 && tempDebilidad != 3);

	if (tempDebilidad == 1)
		tempDebilidadStr = "boomerang";
	else if (tempDebilidad == 2)
		tempDebilidadStr = "bomba";
	else
		tempDebilidadStr = "arco";

	if (tipoMonstruo == 1)
	{
		cout << "Ingrese la vida del monstruo entre 4-12: ";
		do
			cin >> tempVida;
		while (tempVida < 4 || tempVida > 12);
		monstruos.push_back(new Comun(tempNombre, tempDebilidadStr, tempVida));
	}
	else if (tipoMonstruo == 2)
	{
		cout << "Ingrese la vida del monstruo entre 12-26: ";
		do
			cin >> tempVida;
		while (tempVida < 12 || tempVida > 26);
		monstruos.push_back(new Semijefe(tempNombre, tempDebilidadStr, tempVida));
	}
	else
	{
		cout << "Ingrese la vida del monstruo entre 26-40: ";
		do
			cin >> tempVida;
		while (tempVida < 26 || tempVida > 40);
		monstruos.push_back(new Jefe(tempNombre, tempDebilidadStr, tempVida));
	}
}

void eliminarMonstruo(vector<Monstruo*>& monstruos)
{
	int pos;
	cout << "Monstruos disponibles: " << endl;
	for (int i = 0; i < monstruos.size(); i++)
		if (dynamic_cast<Comun*>(monstruos[i]) != NULL)
			cout << i << ") Monstruo Comun " << monstruos[i]->getNombre() << endl;

		else if (dynamic_cast<Semijefe*>(monstruos[i]) != NULL)
			cout << i << ") Semijefe " << monstruos[i]->getNombre() << endl;

		else if (dynamic_cast<Jefe*>(monstruos[i]) != NULL)
			cout << i << ") Jefe " << monstruos[i]->getNombre() << endl;

	cout << "Seleccione una posicion: ";
	do
		cin >> pos;
	while (pos < 0 || pos >= monstruos.size());

	delete monstruos[pos]; 
	monstruos.erase(monstruos.begin() + pos);
}

int buscarMonstruo(vector<Monstruo*> monstruos)
{
	int pos;
	cout << "Monstruos disponibles: " << endl;
	for (int i = 0; i < monstruos.size(); i++)
		if (dynamic_cast<Comun*>(monstruos[i]) != NULL)
			cout << i << ") Monstruo Comun " << monstruos[i]->getNombre() << endl;

		else if (dynamic_cast<Semijefe*>(monstruos[i]) != NULL)
			cout << i << ") Semijefe " << monstruos[i]->getNombre() << endl;

		else if (dynamic_cast<Jefe*>(monstruos[i]) != NULL)
			cout << i << ") Jefe " << monstruos[i]->getNombre() << endl;

	cout << "Seleccione una posicion: ";
	do
		cin >> pos;
	while (pos < 0 || pos >= monstruos.size());
	return pos;
}

bool batallar(Heroe*& heroe, Monstruo*& monstruo)
{
	int opcion;
	do
	{
		cout << "VIDA MONSTRUO: " << monstruo->getVida() << endl;
		cout << "VIDA HEROE: " << heroe->getVida() << endl;

		cout << "\nMENU BATALLA\n"
			<< "1) Ataque normal\n"
			<< "2) Ataque especial\n"
			<< "3) Ataque item\n"
			<< "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
			case 1:
				heroe->atacar(monstruo);
				monstruo->atacar(heroe);
				break;

			case 2:
				if (dynamic_cast<Adulto*>(heroe) != NULL)
				{
					heroe->atacarEspecial(monstruo);
					monstruo->atacar(heroe);
				}
				else
				{
					cout << "Ocupa ser adulto para utilizar el ataque especial!" << endl;
				}
				break;

			case 3:
				if (heroe->getItem() != NULL)
				{
					heroe->getItem()->utilizar(heroe, monstruo);
					monstruo->atacar(heroe);
				}
				else
				{
					cout << "No tiene item!" << endl;
				}
				break;

			default:
				cout << "Opcion no valida!" << endl;
				break;
		}
	}
	while (heroe->getVida() > 0 && monstruo->getVida() > 0);

	if (heroe->getVida() > 0)
	{
		cout << "Batalla victoriosa!" << endl;
		heroe->curar();
		return true;
	}
	else
	{
		cout << "Ha sido derrotado!" << endl;
		heroe->curar();
		return false;
	}
}
