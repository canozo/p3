#include "Bomba.h"

#ifndef NORMAL_H
#define NORMAL_H

class Normal : public Bomba
{
	private:
		int alcance;

	public:
		Normal(int, int, int, int, int);
		int getAlcance();
};

#endif