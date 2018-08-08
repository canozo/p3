#include "Item.h"

#ifndef BOMBA_H
#define BOMBA_H

class Bomba : public Item
{
	protected:
		int turno, owner;

	public:
		Bomba(int, int, int, int);
		virtual void cosa();
		void disminuirTurno();
		void setTurno(int);
		int getOwner();
		int getTurno();
};

#endif