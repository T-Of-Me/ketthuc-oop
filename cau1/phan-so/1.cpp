#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
#include <math.h>
class PS
{
private:
    int ts, ms;

public:
    PS();
    PS(int, int);
    friend PS operator+(PS, PS);
    PS operator+(int &);
    PS operator-(PS &);
    friend istream &operator>>(istream &in, PS &ps);
    friend ostream &operator<<(ostream &out, const PS &ps);
    void rutgon();

private:
    int ucln(int a, int b)
    {
        return b ? ucln(b, a % b) : a;
    }
};
istream &operator>>(istream &in, PS &ps)
{
    cout << "Nhap tu so:";
    in >> ps.ts;
    cout << "Nhap mau so:";
    in >> ps.ms;
    return in;
};
ostream &operator<<(ostream &out, const PS &ps)
{
    out << ps.ts << "/" << ps.ms;
    return out;
};
PS::PS()
{
    ts = 0;
    ms = 1;
};
PS::PS(int TS, int MS)
{
    ts = TS;
    ms = MS;
};
PS operator+(PS ps, PS ps1)
{
    PS Tong;
    Tong.ts = ps1.ts * ps.ms + ps1.ms * ps.ts;
    Tong.ms = ps1.ms * ps.ms;
    return Tong;
}
PS PS::operator-(PS &ps)
{
    PS Hieu;
    Hieu.ts = ts * ps.ms - ms * ps.ts;
    Hieu.ms = ms * ps.ms;
    return Hieu;
};
void PS::rutgon()
{
    int u = ucln(ts, ms);
    ts /= u;
    ms /= u;
}
PS PS::operator+(int &songuyen)
{
    PS sohuuti(songuyen * ms, ms);
    return *this + sohuuti;
}

int main()
{
    PS a;
    PS b;
    PS c;
    cin >> a;
    cin >> b;
    c = a + b;
    cout << c;
}