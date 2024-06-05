#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
#include <math.h>

class huuti
{
    int ts, ms;

public:
    bool operator==(huuti a);
    bool operator!=(huuti a);
    bool operator>(huuti a);
    bool operator<(huuti a);

    huuti operator+(huuti a);
    huuti operator-(huuti a);
    huuti operator*(huuti a);
    huuti operator/(huuti a);

    friend ostream &operator<<(ostream &os, huuti &ht);
    friend istream &operator>>(istream &is, huuti &ht);
};
// Định nghĩa toán tử so sánh bằng
bool huuti::operator==(huuti a)
{
    return (ts * a.ms == ms * a.ts);
};
// Định nghĩa toán tử so sánh khác
bool huuti::operator!=(huuti a)
{
    return (ts * a.ms != ms * a.ts);
};

// Định nghĩa toán tử lớn hơn
bool huuti::operator>(huuti a)
{
    return (ts * a.ms > ms * a.ts);
};

// Định nghĩa toán tử nhỏ hơn
bool huuti::operator<(huuti a)
{
    return (ts * a.ms < ms * a.ts);
};
ostream &operator<<(ostream &out, huuti &ht)
{
    out << ht.ts << "/" << ht.ms << endl;
    return out;
};

// Định nghĩa toán tử trích dòng
istream &operator>>(istream &in, huuti &ht)
{
    cout << "Nhap tu so: ";
    in >> ht.ts;
    cout << "Nhap mau so: ";
    in >> ht.ms;
    return in;
};

huuti huuti::operator+(huuti a)
{
    huuti kq;
    kq.ts = ts * a.ms + ms * a.ts;
    kq.ms = a.ts * a.ms;
    return kq;
};

// Định nghĩa toán tử trừ
huuti huuti::operator-(huuti a)
{
    huuti kq;
    kq.ts = ts * a.ms - ms * a.ts;
    kq.ms = a.ts * a.ms;
    return kq;
};

// Định nghĩa toán tử nhân
huuti huuti::operator*(huuti a)
{
    huuti kq;
    kq.ts = ts * a.ts;
    kq.ms = ms * a.ms;
    return kq;
};

// Định nghĩa toán tử chia
huuti huuti::operator/(huuti a)
{
    huuti kq;
    if (a.ts == 0)
        exit(1);
    else
    {
        kq.ts = ts * a.ms;
        kq.ms = ms * a.ts;
    };
    return kq;
};

class daysohuuti 
{
    huuti ht[300];

public:
    void sapxep();
    int timkiem(huuti a);
    void nhapdht();
    void xuatdht();
};



// Dinh nghia cac ham thanh vien cua lop daysohuuti
void daysohuuti::sapxep()
{
    int i, j;
    huuti t;
    for (i = 0; i < 299; i++)
        for (j = 0; j < 300; j++)
            if (ht[j] < ht[i])
            {
                t = ht[j];
                ht[j] = ht[i];
                ht[i] = t;
            };
};

// Tìm kiếm số hữu tỉ, nếu tìm thấy trả lại vị trí số hữu tỉ trong dãy, không tìm thấy trả về giá trị 0
int daysohuuti::timkiem(huuti a)
{
    int i;
    for (i = 0; i < 300; i++)
    {
        if (ht[i] == a)
            return i;
    };
    return 0;
};
void daysohuuti::nhapdht()
{
    int i;
    for (i = 0; i < 300; i++)
    {
        cout << "Nhap so huu ti thu" << i;
        cin >> ht[i];
    };
};
void daysohuuti::xuatdht()
{
    int i;
    for (i = 0; i < 300; i++)
        cout << ht[i];
};