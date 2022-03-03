#include "Weight.h"

Kilograms::Kilograms()
{
	value = 0;
}

Kilograms::Kilograms(double kg)
{
	this->value = kg;
}

Pounds::Pounds()
{
	value = 0;
}

Pounds::Pounds(double p)
{
	value = p;
}

Weight::Weight()
{
	gramm = 0;
}

Weight::Weight(double g) {
	gramm = g;
}

Weight::Weight(Kilograms kg)
{
	gramm = kg.value * 1000;
}

Weight::Weight(Pounds p) {
	gramm = p.value * 453.59;
}


void Weight::ShowWeight()
{
	std::cout << gramm <<std::endl;
}

Kilograms Weight::to_kilograms(Weight g)
{
	double kg = g.gramm * 0.001;
	Kilograms value(kg);
	return value;
}

Pounds Weight::to_pounds(Weight g)
{
	double pounds = g.gramm * 0.0022;
	Pounds value(pounds);
	return value;
}

Weight Weight::operator*(double num)
{
	gramm = gramm * num;
	return *this;
}

Weight Weight::operator+(Weight right)
{
	gramm = gramm + right.gramm;
	return *this;
}

Weight Weight::operator+(Kilograms right)
{
	gramm = gramm + right.value * 1000;
	return *this;
}

Weight Weight::operator-(Kilograms right)
{
	gramm = gramm - right.value * 1000;
	return *this;
}

Weight Weight::operator+(Pounds right)
{
	gramm = gramm + right.value * 453;
	return *this;
}

Weight Weight::operator-(Pounds right)
{
	gramm = gramm - right.value * 453;
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

bool operator==(Weight left, Weight right)
{
	if (left.gramm == right.gramm) return true;
	return false;
}

bool operator<=(Weight left, Weight right)
{
	if (left.gramm <= right.gramm) return true;
	return false;
}

bool operator>=(Weight left, Weight right)
{
	if (left.gramm >= right.gramm) return true;
	return false;
}

bool operator>(Weight left, Weight right)
{
	if (left.gramm > right.gramm) return true;
	return false;
}

bool operator<(Weight left, Weight right)
{
	if (left.gramm < right.gramm) return true;
	return false;
}

bool operator!=(Weight left, Weight right)
{
	if (left.gramm != right.gramm) return true;
	return false;
}

