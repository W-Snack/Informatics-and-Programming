#pragma once
#include <iostream>
class Weight
{
private:
	int gramm;
public:
	Weight();
	Weight(int g);
	void ShowWeight();
	Weight operator*(int num);
	Weight operator+(Weight right);
	Weight operator- (Weight right);
	Weight operator=(Weight right);
};

