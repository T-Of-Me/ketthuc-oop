#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
#include <math.h>

class Date
{
private:
    int day, month, year;

public:
    Date() : day(1), month(1), year(1)
    {
    }
    Date(int d, int m, int y) : day(d), month(m), year(y)
    {
        // kiem tra tinh hop le cua ngay thang, neu vi pham
        // gan ve gia tri mac dinh
        static int nm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year < 0)
            year = 1;
        if (IsLeapYear(year))
            nm[1] = 29;
        if (month > 12 || month <= 0)
            month = 1;
        if (day <= 0 || day > nm[month - 1])
            day = 1;
    }

    static bool IsLeapYear(int year) { return !(year % 4); }
    static int DateOfMonth(const Date &dateval)
    {
        int month = dateval.month;
        if (month >= 1 && month <= 12)
        {
            if (month != 2)
            {
                bool isEven = !(month % 2);
                // neu vao thang 1, 3, 5, 7
                if (month < 8 && !isEven)
                    return 31;
                // neu vao thang 4, 6
                else if (month < 8)
                    return 30;
                // neu vao thang 8, 10, 12
                else if (month >= 8 && isEven)
                    return 31;
                // neu vao thang 9, 11
                else
                    return 30;
            }
            else
                return (IsLeapYear(dateval.year)) ? 29 : 28;
        }
        else
            // thang bat hop le
            return 0;
    }
};