#include "Normal.h"

Normal::Normal(int yBomb, int xBomb, int turno, int owner, int alcance) : Bomba(yBomb, xBomb, turno, owner)
{
	this->alcance = alcance;
}

int Normal::getAlcance()
{
	return alcance;
}