#include "Item.h"
#include <iostream>
#include <string>


Item::Item(){

}

Item::Item(string pNombre, int pHP, int pDefensa, int pPoderEspecial, int pFactor){
	nombre = pNombre;
	hp = pHP;
	defensa =pDefensa;
	poderEspecial = pPoderEspecial;
	factor = pFactor;
}

void Item::setNombre(string pNombre){
	nombre = pNombre;
}

string Item::getNombre(){
	return nombre;
}

void Item::setHP(int pHP){
	hp = pHP;
}

int Item::getHP(){
	return hp;
}

void Item::setDefensa(int pDefensa){
	defensa = pDefensa;
}

int Item::getDefensa(){
	return defensa;
}

void Item::setPoderEspecial(int pPoderEspecial){
	poderEspecial = pPoderEspecial;
}
int Item::getPoderEspecial(){
	return poderEspecial;
}

void Item::setFactor(int pFactor){
	factor = pFactor;
}
int Item::getFactor(){
	return factor;
}
