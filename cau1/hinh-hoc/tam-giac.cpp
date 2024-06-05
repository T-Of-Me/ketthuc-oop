#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
#include <math.h>

class TamGiac
{
public:
    enum dangTamGiac
    {
        Thuong,
        Can,
        Deu,
        Vuong
    };

private:
    float a, b, c;

public:
    TamGiac() : a(3), b(4), c(5) {}
    TamGiac(int _a, int _b, int _c) : a(_a), b(_b), c(_c)
    {
    }
    float ChuVi() const
    {
        return (a + b + c);
    }
    float DienTich() const
    {
        float s = 0.5 * (a + b + c);
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    static dangTamGiac Dang(const TamGiac &tg)
    {
        float a = tg.a, b = tg.b, c = tg.c;
        if (a == b && b == c)
            return Deu;
        if (a == b || b == c || a == c)
            return Can;
        if (c < b)
            std::swap(c, b);
        if (c < a)
            std::swap(c, a);
        if (a * a + b * b == c * c)
            return Vuong;
        else
            return Thuong;
    }
};