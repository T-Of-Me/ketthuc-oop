#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
#include <math.h>

class Time
{
    int hour;
    int minute;
    int second;

public:
    Time operator+(int s);
    int operator-(Time t);
};
Time Time::operator+(int s)
{
    second = second + s;
    while (second >= 60)
    {
        second = second - 60;
        minute = minute + 1;
    };
    while (minute >= 60)
    {
        minute = minute - 60;
        hour = hour + 1;
    };
    return *this;
};
int Time::operator-(Time t)
{
    int h;
    h = (hour * 3600 - minute * 60 + second) - (t.hour * 3600 - t.minute * 60 + t.second); 
    return h;
};
