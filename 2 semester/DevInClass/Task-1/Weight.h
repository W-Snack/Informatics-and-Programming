#pragma once
#include <iostream>


class Kilograms
{
private:
	double value;
public:
	Kilograms();
	Kilograms(double kg);
	friend class Weight;
};

class Pounds
{
private:
	double value;
public:
	Pounds();
	Pounds(double p);
	friend class Weight;
};

class Weight
{
private:
	double gramm;
public:
	Weight();
	Weight(double g);
	Weight(Kilograms kg);
	Weight(Pounds p);
	Kilograms to_kilograms(Weight g);
	Pounds to_pounds(Weight g);
	void ShowWeight();
	Weight operator*(double num);
	Weight operator+(Weight right);
	Weight operator+(Kilograms right);
	Weight operator-(Kilograms right);
	Weight operator+(Pounds right);
	Weight operator-(Pounds right);
	Weight operator- (Weight right);
	Weight operator=(Weight right);
	friend bool operator==(Weight left,Weight right);
	friend bool operator<=(Weight left, Weight right);
	friend bool operator>=(Weight left, Weight right);
	friend bool operator>(Weight left, Weight right);
	friend bool operator<(Weight left, Weight right);
	friend bool operator!=(Weight left, Weight right);
};
