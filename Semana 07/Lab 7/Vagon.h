#include "Item.h"

#ifndef VAGON_H
#define VAGON_H

class Vagon : public Item
{
	public:
		Vagon(int, int);
		void setYPos(int);
		void setXPos(int);
};

#endif