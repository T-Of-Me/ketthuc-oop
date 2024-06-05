#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
#include <math.h>

class matran
{
private:
    int hang, cot;
    int phantu[100][100];

public:
    matran operator+(matran a);
    matran operator-(matran a);
    matran operator*(matran a);
    friend ostream &operator<<(ostream &os, matran &mt);
    friend istream &operator>>(istream &is, matran &mt);
};

matran matran::operator+(matran a)
{
    int i, j;
    matran mtkq;
    if (hang != a.hang || cot != a.cot)
    {
        cout << "Khong the cong 2 ma tran khac kich thuoc";
        exit(1);
    }
    else
    {
        for (i = 0; i < hang; i++)
            for (j = 0; j < cot; j++)
                mtkq.phantu[i][j] = phantu[i][j] + a.phantu[i][j];
        return mtkq;
    };
};
matran matran::operator-(matran a)
{
    int i, j;
    matran mtkq;
    if (hang != a.hang || cot != a.cot)
    {
        cout << "Khong the cong 2 ma tran khac kich thuoc";
        exit(1);
    }
    else
    {
        for (i = 0; i < hang; i++)
            for (j = 0; j < cot; j++)
                mtkq.phantu[i][j] = phantu[i][j] - a.phantu[i][j];

        return mtkq;
    };
};

matran matran::operator*(matran a)
{
    int i, j, k;
    matran mtkq;
 
    if (cot != a.hang)
    {
        cout << "Khong the thuc hien nhan 2 ma tran nay";
        exit(1);
    }
    else
    {
        for (i = 0; i < hang; i++)
            for (j = 0; j < a.cot; j++)
            {
                for (k = 0; k < cot; k++)
                    mtkq.phantu[i][j] = mtkq.phantu[i][j] + phantu[i][k] * a.phantu[k][j];
            };
        return mtkq;
    };
};

ostream &operator<<(ostream &out, matran &mt)
{
    int i, j;
    for (i = 0; i < mt.hang; i++)
    {
        for (j = 0; j < mt.cot; j++)
            out << mt.phantu[i][j];
        out << endl;
    };
    return out;
};
istream &operator>>(istream &in, matran &mt)
{
    int i, j;
    cout << "Nhap so hang ma tran: " << endl;
    in >> mt.hang;
    cout << "Nhap so cot ma tran: " << endl;
    in >> mt.cot;
    for (i = 0; i < mt.hang; i++)
        for (j = 0; j < mt.cot; j++)
        {
            cout << "Nhap phan tu hang " << i << " cot " << j << endl;
            in >> mt.phantu[i][j];
        };
    return in;
}