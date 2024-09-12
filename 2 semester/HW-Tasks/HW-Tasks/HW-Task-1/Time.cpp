#include "Time.h"
#include <iostream>
#include <string>

Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
}

Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void Time::ShowTime()
{
    if (hour < 10) std::cout << "0";
    std::cout << hour<<":";
    if (minute < 10) std::cout << "0";
    std::cout << minute << ":";
    if (second < 10) std::cout << "0";
    std::cout << second ;
}


Time::Time(std::string time)
{
   int arr[5];
        std::string str;
        int len = time.length();
        int c_d=0;

        for ( int i = 0,  j = 0; i < len; i++)
        {

            if (time[i] == ':') {
                str.push_back(time[i - 2]);
                str.push_back(time[i - 1]);
                arr[j] = std::stoi(str);
                j++;
                c_d++;
                str.clear();
            }
            if (c_d == 2) {
                str.push_back(time[i + 1]);
                str.push_back(time[i + 2]);
                arr[j] = std::stoi(str);
                break;
            }
        }
        hour = arr[0];
        minute = arr[1];
        second = arr[2];
}



Time Time::secToTime(int sec)
{
    int h = sec / maxMin / maxSec;
    sec -= h * maxMin * maxSec;
    int m = sec / maxSec;
    sec -= m * maxSec;
    int s = sec ;
    return Time(h, m, s);
}

Time Time::operator+(int sec)
{
    this->second += sec;
    if ((this->second) >= maxSec) {
        this->minute += this->second / maxSec;
        this->second %= maxSec;
        if (this->minute >= maxMin) {
            this->hour += this->minute / maxMin;
            this->minute %= maxMin;
            if (this->hour >= maxHr) {
                this->hour %= maxHr;
            }
        }
    }
    return Time(hour, minute, second);
}

Time Time::operator =(Time right)
{
    hour = right.hour;
    minute = right.minute;
    second = right.second;
    return *this;
}


bool operator==(Time left, Time right)
{
    if (left.hour == right.hour) {
        if(left.minute == right.minute) {
            if (left.second == right.second) {
                return true;
            }
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Time& time)
{
    if (time.hour < 10) std::cout << "0";
    std::cout << time.hour << ":";
    if (time.minute < 10) std::cout << "0";
    std::cout << time.minute << ":";
    if (time.second < 10) std::cout << "0";
    std::cout << time.second;
    return out;
}

std::istream& operator>>(std::istream& in, Time& time)
{
    in >> time.hour;
    in >> time.minute;
    in >> time.second;
    return in;
}
