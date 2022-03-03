#include "Weight.h"

Weight::Weight()
{
	gramm = 0;
}

Weight::Weight(int g) {
	gramm = g;
}

void Weight::ShowWeight()
{
	std::cout << gramm<<std::endl;
}

Weight Weight::operator*(int num)
{
	gramm = gramm * num;
	return *this;
}

Weight Weight::operator+(Weight right)
{
	gramm = gramm + right.gramm;
	return *this;
}

Weight Weight::operator-(Weight right)
{
	gramm = gramm - right.gramm;
	return *this;
}

Weight Weight::operator=(Weight right)
{
	gramm = right.gramm;
	return *this;
}
