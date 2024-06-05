#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
class TaiLieu
{
protected:
    int Ma;
    string TenNhaSanXuat;
    int SoBanPhatHanh;

public:
    void print()
    {
        cout << "Ma :" << Ma << endl;
        cout << "Ten nha san xuat :" << TenNhaSanXuat << endl;
        cout << "So ban phat hanh :" << SoBanPhatHanh << endl;
    }
    int ReturnMa()
    {
        return Ma;
    }
};

//==============================================================================================
class Sach : public TaiLieu
{
private:
    string TenTacGia;
    int SoTrang;

public:
    Sach(){};
    ~Sach(){};
    friend ostream &operator<<(ostream &out, Sach x)
    {
        out << x.Ma << endl;
        out << x.TenNhaSanXuat << endl;
        out << x.SoBanPhatHanh << endl;

        out << x.TenTacGia << endl;
        out << x.SoTrang << endl;

        return out;
    }
    friend istream &operator>>(istream &in, Sach &x)
    {
        in >> x.Ma;
        in.ignore();
        getline(in, x.TenNhaSanXuat);
        in >> x.SoBanPhatHanh;

        in.ignore();
        getline(in, x.TenTacGia);
        in >> x.SoTrang;

        return in;
    }
    void print()
    {
        TaiLieu::print();
        cout << "Ten tac gia :" << TenTacGia << endl;
        cout << "So trang  :" << SoTrang << endl;
    }

}; //========================================================================================================================
class SachNhap : public TaiLieu
{
private:
    string TenTacGia;
    int SoTrang;

public:
    SachNhap(){};
    ~SachNhap(){};
    friend ostream &operator<<(ostream &out, SachNhap x)
    {
        out << x.Ma << endl;
        out << x.TenNhaSanXuat << endl;
        out << x.SoBanPhatHanh << endl;

        out << x.TenTacGia << endl;
        out << x.SoTrang << endl;

        return out;
    }
    friend istream &operator>>(istream &in, SachNhap &x)
    {
        cout << "nhap ma :";
        in >> x.Ma;
        cout << "nhap nha san xuat " << endl;
        in.ignore();
        getline(in, x.TenNhaSanXuat);
        cout << "nhap so ban phat hanh " << endl;
        in >> x.SoBanPhatHanh;

        cout << "nhap ten tac gia " << endl;
        in.ignore();
        getline(in, x.TenTacGia);
        cout << "nhap so trang :" << endl;
        in >> x.SoTrang;

        return in;
    }
};
//==============================================================================================

class TapChi : public TaiLieu
{
private:
    int SoPhatHanh;
    int ThangPhatHanh;

public:
    TapChi(){};
    ~TapChi(){};
    friend ostream &operator<<(ostream &out, TapChi x)
    {
        out << x.Ma << endl;
        out << x.TenNhaSanXuat << endl;
        out << x.SoBanPhatHanh << endl;

        out << x.SoPhatHanh << endl;
        out << x.ThangPhatHanh << endl;

        return out;
    }
    friend istream &operator>>(istream &in, TapChi &x)
    {
        in >> x.Ma;
        in.ignore();
        getline(in, x.TenNhaSanXuat);
        in >> x.SoBanPhatHanh;

        in >> x.SoPhatHanh;
        in >> x.ThangPhatHanh;

        return in;
    }
    void print()
    {
        TaiLieu::print();
        cout << "So phat hanh :" << SoPhatHanh << endl;
        cout << "Thang phat hanh :" << ThangPhatHanh << endl;
    }
};
//==============================================================================================

class TapChiNhap : public TaiLieu
{
private:
    int SoPhatHanh;
    int ThangPhatHanh;

public:
    TapChiNhap(){};
    ~TapChiNhap(){};
    friend ostream &operator<<(ostream &out, TapChiNhap x)
    {
        out << x.Ma << endl;
        out << x.TenNhaSanXuat << endl;
        out << x.SoBanPhatHanh << endl;

        out << x.SoPhatHanh << endl;
        out << x.ThangPhatHanh << endl;

        return out;
    }
    friend istream &operator>>(istream &in, TapChiNhap &x)
    {
        cout << "nhap ma :";
        in >> x.Ma;
        cout << "nhap nha san xuat " << endl;
        in.ignore();
        getline(in, x.TenNhaSanXuat);
        cout << "nhap so ban phat hanh " << endl;
        in >> x.SoBanPhatHanh;
        cout << "nhap so phat hanh " << endl;
        in >> x.SoPhatHanh;
        cout << "nhap thang phat hanh " << endl;
        in >> x.ThangPhatHanh;

        return in;
    }
};

////==============================================================================================

class Bao : public TaiLieu
{
private:
    int NgayPhatHanh;

public:
    Bao(){};
    ~Bao(){};
    void print()
    {
        TaiLieu::print();
        cout << "Ngay phat hanh :" << NgayPhatHanh << endl;
    }
    friend ostream &operator<<(ostream &out, Bao x)
    {
        out << x.Ma << endl;
        out << x.TenNhaSanXuat << endl;
        out << x.SoBanPhatHanh << endl;

        out << x.NgayPhatHanh << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Bao &x)
    {
        cout << "nhap ma :";
        in >> x.Ma;
        cout << "nhap nha san xuat " << endl;
        in.ignore();
        getline(in, x.TenNhaSanXuat);
        cout << "nhap so ban phat hanh " << endl;
        in >> x.SoBanPhatHanh;
        cout << "nhap ngay phat hanh " << endl;
        in >> x.NgayPhatHanh;
        return in;
    }
}; ////==============================================================================================

class BaoNhap : public TaiLieu
{
private:
    int NgayPhatHanh;

public:
    BaoNhap(){};
    ~BaoNhap(){};
    friend ostream &operator<<(ostream &out, BaoNhap x)
    {
        out << x.Ma << endl;
        out << x.TenNhaSanXuat << endl;
        out << x.SoBanPhatHanh << endl;

        out << x.NgayPhatHanh << endl;
        return out;
    }
    friend istream &operator>>(istream &in, BaoNhap &x)
    {
        in >> x.Ma;
        in.ignore();
        getline(in, x.TenNhaSanXuat);
        in >> x.SoBanPhatHanh;

        in >> x.NgayPhatHanh;
        return in;
    }
};
//==============================================================================================

class QuanLyAnPham
{
private:
public:
    void ThemTaiLieu()
    {
        cout << " 1 sach" << endl;
        cout << " 2 tap chi" << endl;
        cout << " 3 bao " << endl;
        int chose;
        cout << " moi nhap lua chon " << endl;
        cin >> chose;

        if (chose == 1)
        {

            cout << "nhap ma de kiem tra tai lieu ";
            int ma;
            bool check = false;
            do
            {
                Sach b;
                int ok = 0;
                cin >> ma;
                ifstream file1("Sach.txt", ios::in);
                while (file1 >> b)
                {
                    if (b.ReturnMa() == ma)
                    {
                        cout << "loading.........." << endl;
                        cout << "ma sach ton tai " << endl;
                        ok = 1;
                        break;
                    }
                }

                if (ok != 1)
                {
                    cout << "ma sach khong ton tai - ban co the them " << endl;
                    check = true;
                }
                file1.close();
            } while (check == false);

            SachNhap a;
            ofstream file("Sach.txt", ios::app);
            cin >> a;
            file << a;
            file.close();
        }
        else if (chose == 2)
        {
            cout << "nhap ma de kiem tra tai lieu ";
            int ma;
            bool check = false;
            do
            {
                TapChi b;
                int ok = 0;
                cin >> ma;
                ifstream file1("TapChi.txt", ios::in);
                while (file1 >> b)
                {
                    if (b.ReturnMa() == ma)
                    {
                        cout << "loading.........." << endl;
                        cout << "ma TapChi ton tai " << endl;
                        ok = 1;
                        break;
                    }
                }

                if (ok != 1)
                {
                    cout << "ma TapChi khong ton tai - ban co the them " << endl;
                    check = true;
                }
                file1.close();
            } while (check == false);
            TapChiNhap a;
            ofstream file("TapChi.txt", ios::app);
            cin >> a;
            file << a;
            file.close();
        }
        else if (chose == 3)
        {
            cout << "nhap ma de kiem tra tai lieu ";
            int ma;
            bool check = false;
            do
            {
                Bao b;
                int ok = 0;
                cin >> ma;
                ifstream file1("Bao.txt", ios::in);
                while (file1 >> b)
                {
                    if (b.ReturnMa() == ma)
                    {
                        cout << "loading.........." << endl;
                        cout << "ma Bao ton tai " << endl;
                        ok = 1;
                        break;
                    }
                }

                if (ok != 1)
                {
                    cout << "ma Bao khong ton tai - ban co the them " << endl;
                    check = true;
                }
                file1.close();
            } while (check == false);
            BaoNhap a;
            ofstream file("Bao.txt", ios::app);
            cin >> a;
            file << a;
            file.close();
        }
        else
        {
            cout << "sai ki tu !!!!!!!!!!!!" << endl;
        }
    }

    void HienThiThongTin()
    {
        cout << "danh sach cac tai lieu" << endl;
        ifstream file1("Sach.txt", ios::in);
        ifstream file2("TapChi.txt", ios::in);
        ifstream file3("Bao.txt", ios::in);
        Sach a;
        TapChi b;
        Bao c;
        while (file1 >> a)
        {
            a.print();
            cout << "///////////////////" << endl;
        }
        while (file2 >> b)
        {
            b.print();
            cout << "///////////////////" << endl;
        }
        while (file3 >> c)
        {
            c.print();
            cout << "///////////////////" << endl;
        }
        file1.close();
        file2.close();
        file3.close();
    }
    void TiemKiemTaiLieu()
    {
        cout << " 1 sach" << endl;
        cout << " 2 tap chi" << endl;
        cout << " 3 bao " << endl;
        int chose;
        cout << " moi nhap lua chon " << endl;
        cin >> chose;
        int ma;
        if (chose == 1)
        {
            cout << "nhap ma de tim " << endl;
            cin >> ma;
            Sach a;
            bool check = false;
            ifstream file1("Sach.txt", ios::in);
            while (file1 >> a)
            {
                if (a.ReturnMa() == ma)
                {
                    a.print();
                    check = true;
                }
            }
            if (check == false)
            {
                cout << "sai ma" << endl;
            }
            file1.close();
        }
        else if (chose == 2)
        {
            cout << "nhap ma de tim " << endl;
            cin >> ma;
            Sach a;
            bool check = false;
            ifstream file1("TapChi.txt", ios::in);
            while (file1 >> a)
            {
                if (a.ReturnMa() == ma)
                {
                    a.print();
                    check = true;
                }
            }
            if (check == false)
            {
                cout << "sai ma" << endl;
            }
            file1.close();
        }
        else if (chose == 3)
        {
            cout << "nhap ma de tim " << endl;
            cin >> ma;
            Sach a;
            bool check = false;
            ifstream file1("Bao.txt", ios::in);
            while (file1 >> a)
            {
                if (a.ReturnMa() == ma)
                {
                    a.print();
                    check = true;
                }
            }
            if (check == false)
            {
                cout << "sai ma" << endl;
            }
            file1.close();
        }
        else
        {
            cout << "sai ki tu !!!" << endl;
        }
    }
};
int check;
//=====================================================================================================================================================

void menu()
{
    QuanLyAnPham a;
    switch (check)
    {
    case 1:
        a.ThemTaiLieu();
        break;
    case 2:
        a.HienThiThongTin();
        break;
    case 3:
        a.TiemKiemTaiLieu();
        break;
    }
}
//=============================================================================================================================================
int main()
{
    bool keeping = true;
    while (keeping)
    {
        cout << "*** SAN GIAO DICH ***" << endl;
        cout << " 1  them tai lieu" << endl;
        cout << " 2  hien thi danh sach tai lieu " << endl;
        cout << " 3  tim kiem tai lieu  " << endl;
        cout << " 4   " << endl;
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