#include "Espina.h"

Espina::Espina(int yBomb, int xBomb, int turnos, int owner, int cantidadBombasPorUsuario) : Bomba(yBomb, xBomb, turnos, owner)
{
	this->cantidadBombasPorUsuario = cantidadBombasPorUsuario;
}