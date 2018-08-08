#ifndef DOUBLE_H
#define DOUBLE_H

class Double
{
	private:
		double num;

	public:
		Double(double);
		double getNum();
		friend Double* operator + (const Double&, const Double&);
		friend Double* operator - (const Double&, const Double&);
};

#endif