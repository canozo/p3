#include "Vagon.h"

Vagon::Vagon(int yPos, int xPos) : Item(yPos, xPos, 'U')
{
}

void Vagon::setYPos(int yPos)
{
	this->yPos = yPos;
}

void Vagon::setXPos(int xPos)
{
	this->xPos = xPos;
}