#include "Item.h"

Item::Item(int yPos, int xPos, char character)
{
	this->yPos = yPos;
	this->xPos = xPos;
	this->character = character;
}

int Item::getXPos()
{
	return xPos;
}

int Item::getYPos()
{
	return yPos;
}

char Item::getCharacter()
{
	return character;
}