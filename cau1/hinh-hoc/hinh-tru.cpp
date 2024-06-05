#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
#include <math.h>
class HinhHoc
{
public:
    virtual float ChuVi() = 0;
    virtual float DienTich() = 0;
};
class HinhChuNhat : public HinhHoc
{
private:
    float a, b;

public:
    HinhChuNhat(int _a, int _b) : a(_a), b(_b)
    {
        }
    virtual float ChuVi() const
    {
        return (a + b) * 2;
    }
    virtual float DienTich() const
    {
        return a * b;
    }
};
class HinhTron : public HinhHoc
{
private:
    float r;

public:
    HinhTron(int _r) : r(_r)
    {
        if (r < 0)
            r = 1;
    }
    virtual float ChuVi() const
    {
        return 2 * 3.14159 * r;
    }
    virtual float DienTich() const
    {
        return 3.14159 * r * r;
    }
    float DuongKinh() const
    {
        return 2 * r;
    }
};
F