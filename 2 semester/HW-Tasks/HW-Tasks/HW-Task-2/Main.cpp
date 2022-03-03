
#include <string>
#include <iostream>
#include "Hex.h"

int main() {
	Hex a("12");
	unsigned char b = 3;
	Hex sum = a + b;
	sum.ShowHex();
}