#pragma once

#include <string>
#include <iostream>


const char maxSec = 60;
const char maxMin = 60;
const char maxHr = 24;

class Time
{
private:
		int hour;
		int minute;
		int second;
public:
	Time();
	Time(int h, int m, int s);
	Time(std::string time);
	Time secToTime(int sec);
	void ShowTime();
	Time operator +(int sec);
	Time operator =(Time time);
	friend bool operator ==(Time left, Time right);
	friend std::ostream& operator<< (std::ostream& out, const Time& time);
	friend std::istream& operator>> (std::istream& in, Time& time);
	~Time() {};
};

