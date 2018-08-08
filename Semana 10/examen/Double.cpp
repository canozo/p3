#include "Double.h"

Double::Double(double num)
{
	this->num = num;
}

double Double::getNum()
{
	return num;
}

Double* operator + (const Double& der, const Double& izq)
{
	return new Double(der.num + izq.num);
}

Double* operator - (const Double& der, const Double& izq)
{
	return new Double(der.num - izq.num);
}