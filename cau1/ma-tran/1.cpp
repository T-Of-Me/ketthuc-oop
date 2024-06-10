#include <iostream>
using namespace std;

class matran
{
private:
    int hang, cot;
    int phantu[100][100];

public:
    matran() {}
    matran(int h, int c) : hang(h), cot(c) {}

    matran operator+(const matran &a);
    matran operator-(const matran &a);

    friend ostream &operator<<(ostream &out, const matran &mt);
    friend istream &operator>>(istream &in, matran &mt);
};

matran matran::operator+(const matran &a)
{
    if (hang != a.hang || cot != a.cot)
    {
        cout << "Khong the cong 2 ma tran khac kich thuoc" << endl;
        return matran(0, 0);
    }

    matran mtkq(hang, cot);
    for (int i = 0; i < hang; i++)
        for (int j = 0; j < cot; j++)
            mtkq.phantu[i][j] = phantu[i][j] + a.phantu[i][j];

    return mtkq;
}

matran matran::operator-(const matran &a)
{
    if (hang != a.hang || cot != a.cot)
    {
        cout << "Khong the tru 2 ma tran khac kich thuoc" << endl;
        return matran(0, 0);
    }

    matran mtkq(hang, cot);
    for (int i = 0; i < hang; i++)
        for (int j = 0; j < cot; j++)
            mtkq.phantu[i][j] = phantu[i][j] - a.phantu[i][j];

    return mtkq;
}

ostream &operator<<(ostream &out, const matran &mt)
{
    for (int i = 0; i < mt.hang; i++)
    {
        for (int j = 0; j < mt.cot; j++)
            out << mt.phantu[i][j] << " ";
        out << endl;
    }
    return out;
}

istream &operator>>(istream &in, matran &mt)
{
    cout << "Nhap so hang ma tran: ";
    in >> mt.hang;
    cout << "Nhap so cot ma tran: ";
    in >> mt.cot;

    for (int i = 0; i < mt.hang; i++)
        for (int j = 0; j < mt.cot; j++)
        {
            cout << "Nhap phan tu hang " << i << " cot " << j << ": ";
            do
            {
                in >> mt.phantu[i][j];
                if (mt.phantu[i][j] < 0)
                {
                    cout << "kí tu khong hop le nhap lai " << endl;
                    cout << "Nhap phan tu hang " << i << " cot " << j << ": ";
                }
            } while (mt.phantu[i][j] < 0);
        }

    return in;
}

int main()
{
    matran x, y;
    cout << "Nhap ma tran x:" << endl;
    cin >> x;
    cout << "Nhap ma tran y:" << endl;
    cin >> y;

    matran kq = x + y;
    cout << "Tong cua hai ma tran:" << endl;
    cout << kq;

    return 0;
}





