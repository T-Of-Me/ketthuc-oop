#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
#include <math.h>
class sophuc
{
private:
    int pt, pa;

public:
    friend sophuc operator+(sophuc &, sophuc &);

    sophuc operator-(sophuc &);
    sophuc operator*(sophuc &);
    sophuc operator/(sophuc &);

    friend bool operator==(sophuc &, sophuc &);

    friend ostream &operator<<(ostream &, sophuc &);
    friend istream &operator>>(istream &, sophuc &);

    int module()
    {
        return sqrt(pt * pt + pa * pa);
    }
};
bool operator==(sophuc &a, sophuc &b)
{
    return (a.pa + a.pt == b.pt + b.pa);
}
istream &operator>>(istream &in, sophuc &sp)
{
    in >> sp.pt >> sp.pa;
    return in;
};
ostream &operator<<(ostream &out, sophuc &sp)
{
    out << "Phan thuc la : " << sp.pt;
    out << "Phan ao la : " << sp.pa;
    return out;
};

// Định nghĩa toán tử cộng
sophuc operator+(sophuc &a, sophuc &b)
{
    sophuc kq;
    kq.pt = b.pt + a.pt;
    kq.pa = b.pa + a.pa;
    return kq;
};

// Định nghĩa toán tử trừ
sophuc sophuc::operator-(sophuc &a)
{
    sophuc kq;
    kq.pt = pt - a.pt;
    kq.pa = pa - a.pa;
    return kq;
};

sophuc sophuc::operator*(sophuc &a)
{
    sophuc kq;
    kq.pt = pt * a.pt - pa * a.pa;
    kq.pa = pt * a.pa + pa * a.pt;
    return kq;
};

// Định nghĩa toán tử chia
sophuc sophuc::operator/(sophuc &a)
{
    sophuc kq;
    kq.pt = pt * a.pt + pa * a.pa / (a.pt * a.pt + a.pa * a.pa);
    kq.pa = pa * a.pt - pt * a.pa / (a.pt * a.pt + a.pa * a.pa);
    return kq;
};

class DaySoPhuc
{
private:
    sophuc sp[100];

public:
    int timkiem(sophuc a);
    void sapxep();
    void nhapdsp();
    void indsp();
    sophuc tongdsp();
};
sophuc DaySoPhuc::tongdsp()
{
    int i;
    sophuc tong;
    tong = sp[0];
    for (i = 1; i < 100; i++)
        tong = tong + sp[i];
    return tong;
};

void DaySoPhuc::sapxep()
{

    sophuc t;
    for (int i = 0; i < 99; i++)
    {
        for (int j = i + 1; j < 100; j++)
        {
            if (sp[j].module() < sp[i].module())
            {
                t = sp[j];
                sp[j] = sp[i];
                sp[i] = t;
            };
        }
    }
}

void DaySoPhuc::nhapdsp()
{
    for (int i = 0; i < 100; i++)
    {
        cin >> sp[i];
    }
}

void DaySoPhuc::indsp()
{
    for (int i = 0; i < 100; i++)
    {
        cout << sp[i];
    }
};
int DaySoPhuc::timkiem(sophuc a)
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (sp[i] == a)
            return i;
    };
    return 0;
}