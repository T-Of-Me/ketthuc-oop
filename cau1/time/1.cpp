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
    bool operator==(Time t);
    bool operator<(Time t);
    bool operator>(Time t);
};
bool Time::operator==(Time t)
{
    return ((second == t.second) && (minute == t.minute) && (hour == t.hour));
};
bool Time::operator<(Time t)
{
    return ((hour * 3600 + minute * 60 + second) < (t.hour * 3600 + t.minute * 60 + t.second));
};
bool Time::operator>(Time t)
{
    return ((hour * 3600 + minute * 60 + second) > (t.hour * 3600 + t.minute * 60 + t.second));
};


