#include "Time.h"
#include <string>
#include <iostream>

int main() {
	Time time;
	int sec = 6000;
	Time time2("07:01:20");
	std::cout << time2;
	std::cin >> time;
	time.ShowTime();
}