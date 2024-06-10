#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>

//============================================================================
class HoGiaDinh
{
protected:
    string Ten;       // const
    int SoNha;        // const
    int MaCongToDien; // const

public:
    int ReturnMaCong() { return MaCongToDien; };
    string ReturnTen()
    {
        return Ten;
    }

    void print()
    {
        cout << "ten :" << Ten << endl;
        cout << "So nha :" << SoNha << endl;
        cout << "Ma cong to dien :" << MaCongToDien << endl;
    }
};
//==================================================================================================================

class BienLaiNhap : public HoGiaDinh
{
private:
    int ChiSoDienCu;
    int ChiSoDienMoi;

public:
    friend ostream &operator<<(ostream &out, BienLaiNhap x)
    {
        out << x.ChiSoDienCu << endl;
        out << x.ChiSoDienMoi << endl;
        out << x.Ten << endl;
        out << x.SoNha << endl;
        out << x.MaCongToDien << endl;

        return out;
    }
    friend istream &operator>>(istream &in, BienLaiNhap &x)
    {
        cout << "Chi so dien cu :";
        in >> x.ChiSoDienCu;
        cout << "Chi so dien moi :";
        in >> x.ChiSoDienMoi;
        cout << "nhap ten " << endl;
        in.ignore();
        getline(in, x.Ten);
        cout << "nhap so nha " << endl;
        in >> x.SoNha;
        cout << "nhap ma cong to dien " << endl;
        in >> x.MaCongToDien;
        return in;
    }

    int SoTienPhaiTra()
    {

        return ChiSoDienMoi * 1000;
    };
};

//==================================================================================================================
class BienLai : public HoGiaDinh
{
private:
    int ChiSoDienCu;
    int ChiSoDienMoi;

public:
    friend ostream &operator<<(ostream &out, BienLai x)
    {
        out << x.ChiSoDienCu << endl;
        out << x.ChiSoDienMoi << endl;
        out << x.Ten << endl;
        out << x.SoNha << endl;
        out << x.MaCongToDien << endl;

        return out;
    }
    friend istream &operator>>(istream &in, BienLai &x)
    {
        in >> x.ChiSoDienCu;
        in >> x.ChiSoDienMoi;
        in.ignore();
        getline(in, x.Ten);
        in >> x.SoNha;
        in >> x.MaCongToDien;
        return in;
    }

    int SoTienPhaiTra()
    {

        return ChiSoDienMoi * 1000;
    };
    void print()
    {
        HoGiaDinh::print();
        cout << "chi so dien cu " << ChiSoDienCu << endl;
        cout << "chi so dien moi :" << ChiSoDienMoi << endl;
    }
};
//====================================================================================================================
class DanhSachBienLai
{
private:
    BienLai b;

public:
    void ThemBienLai()
    {
        ofstream file("BienLai.txt", ios::app);
        ofstream file1("TongTien.txt", ios::app);
        BienLaiNhap a;
        cin >> a;
        file << a;
        file1 << a.SoTienPhaiTra() << endl;
        file.close();
        file1.close();
    };
    void HienThiDanhSachBienLai()
    {
        ifstream file("BienLai.txt", ios::in);
        BienLai a;
        while (file >> a)
        {
            a.print();
        }

    }; // theo ten hoac ma cong to dien
    void TimKiemBienLai()
    {
        cout << "nhap ten de tim kiem " << endl;
        string s;
        cin.ignore();
        getline(cin, s);
        ifstream file("BienLai.txt", ios::in);
        BienLai a;
        bool check = false;
        while (file >> a)
        {
            if (s == a.ReturnTen())
            {
                cout << "ma bien lai dang tim la " << endl;
                a.print();
                check = true;
            }
        }
        if (check == false)
        {
            cout << "khong tim thay bien lai  " << endl;
        }
        file.close();
    };
    void TongTienTatCaBienLai()
    {
        ifstream file1("TongTien.txt", ios::in);
        int x;
        int tong = 0;
        while (file1 >> x)
        {
            tong += x;
        }
        cout << "tong bien lai thu duoc " << tong << endl;
        file1.close();
    };
    void XoaBienLai()
    {
         cout << " "
    }
};

//====================================================================================================================

int check;
//=====================================================================================================================

void menu()
{
    DanhSachBienLai a;
    switch (check)
    {
    case 1:
        a.ThemBienLai();
        break;
    case 2:
        a.HienThiDanhSachBienLai();
        break;
    case 3:
        a.TimKiemBienLai();
        break;
    case 4:
        a.TongTienTatCaBienLai();
        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    default:
        break;
    }
}

//==============================================================================================================================================

int main()
{
    bool keeping = true;
    while (keeping)
    {
        cout << "***  ELECTRICITY  ***" << endl;
        cout << " 1 them  " << endl;
        cout << " 2 hien thi  " << endl;
        cout << " 3 tim kiem  " << endl;
        cout << " 4 tong " << endl;
        cout << " 5  " << endl;
        cout << " 6  " << endl;
        cout << " 7  " << endl;
        cout << " (^;_;^)  NHAP LUA CHON !!!!! (^;_;^) " << endl;
        cin >> check;
        if (check <= 10 && check >= 1)
        {
            menu();
            keeping = true;
        }
        else
        {
            cout << " sai ki tu !!!!" << endl;
            break;
        }
    }
}