#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
template <class T>
void sort(T a[50], int m)
{

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - 1 - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
template <class T>
void sortGiam(T a[50], int m)
{

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
class Sach
{
protected:
    int Ma;
    int ngay, thang, nam;
    int DonGia;
    int SoLuong;
    string NhaXuatBan;

public:
    void print()
    {
        cout << "Ma :" << Ma << endl;
        cout << "Ngay xuat :" << ngay << "/" << thang << "/" << nam << endl;
        cout << "Don gia :" << DonGia << endl;
        cout << "So Luong :" << SoLuong << endl;
        cout << "Nha xuat ban :" << NhaXuatBan << endl;
    }
    bool operator<(Sach b)
    {
        if (nam < b.nam)
        {
            return true;
        }
        else if (thang < b.thang)
        {
            return true;
        }
        else if (ngay < b.ngay)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>(Sach b)
    {
        if (SoLuong > b.SoLuong)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
//====================================================================================================================================================

class SachGiaoTrinh : public Sach
{
private:
    string TinhTrang;

public:
    SachGiaoTrinh(){};
    ~SachGiaoTrinh(){};
    int ThanhTien()
    {
        if (TinhTrang == "MOI")
        {
            return SoLuong * DonGia;
        }
        else
        {
            return SoLuong * DonGia * 1 / 2;
        }
    }

    friend istream &operator>>(istream &in, SachGiaoTrinh &x)
    {
        in >> x.Ma;
        in >> x.ngay;
        in >> x.thang;
        in >> x.nam;
        in >> x.DonGia;
        in >> x.SoLuong;
        in >> x.NhaXuatBan;
        in >> x.TinhTrang;
        return in;
    }
    friend ostream &operator<<(ostream &out, SachGiaoTrinh x)
    {
        out << x.Ma << endl;
        out << x.ngay << endl;
        out << x.thang << endl;

        out << x.nam << endl;
        out << x.DonGia << endl;
        out << x.SoLuong << endl;
        out << x.NhaXuatBan << endl;
        out << x.TinhTrang << endl;

        return out;
    }
    void print()
    {
        Sach::print();
        cout << "tinh trang : " << TinhTrang << endl;
    }
};
//====================================================================================================================================================

class SachGiaoTrinhNhap : public Sach
{
private:
    string TinhTrang;

public:
    friend istream &operator>>(istream &in, SachGiaoTrinhNhap &x)
    {
        cout << "nhap ma :";
        in >> x.Ma;
        cout << " nhap ngay :";
        do
        {
            in >> x.ngay;
            if (x.ngay < 0 || x.ngay > 31)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.ngay < 0 || x.ngay > 31);
        cout << " nhap thang :";
        do
        {
            in >> x.thang;
            if (x.thang < 0 || x.thang > 12)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.thang < 0 || x.thang > 12);
        cout << " nhap nam :";
        do
        {
            in >> x.nam;
            if (x.nam > 2025 || x.nam < 0)
            {
                cout << " sai ki tu nhap lai " << endl;
            }

        } while (x.nam > 2025 || x.nam < 0);
        cout << "nhap don gia :";
        in >> x.DonGia;
        cout << "nhap so luong :";
        in >> x.SoLuong;
        cout << "nhap nha xuat ban :";
        in.ignore();
        getline(in, x.NhaXuatBan);
        do
        {
            getline(in, x.TinhTrang);

            if (x.TinhTrang != "MOI" && x.TinhTrang != "CU")
            {
                cout << "cu phap sai " << endl;
            }

        } while (x.TinhTrang != "MOI" && x.TinhTrang != "CU");

        return in;
    }
    friend ostream &operator<<(ostream &out, SachGiaoTrinhNhap x)
    {
        out << x.Ma << endl;

        out << x.ngay << endl;
        out << x.thang << endl;
        out << x.nam << endl;

        out << x.DonGia << endl;
        out << x.SoLuong << endl;
        out << x.NhaXuatBan << endl;
        out << x.TinhTrang << endl;

        return out;
    }
};

//====================================================================================================================================================
class SachThamKhao : public Sach
{
private:
    int Thue;

public:
    SachThamKhao(){};
    ~SachThamKhao(){};
    friend istream &operator>>(istream &in, SachThamKhao &x)
    {
        in >> x.Ma;
        in >> x.ngay;
        in >> x.thang;
        in >> x.nam;

        in >> x.DonGia;
        in >> x.SoLuong;
        in.ignore();
        getline(in, x.NhaXuatBan);
        in >> x.Thue;
        return in;
    }
    friend ostream &operator<<(ostream &out, SachThamKhao x)
    {
        out << x.Ma << endl;
        out << x.ngay << endl;
        out << x.thang << endl;
        out << x.nam << endl;
        out << x.DonGia << endl;
        out << x.SoLuong << endl;
        out << x.NhaXuatBan << endl;
        out << x.Thue << endl;

        return out;
    }
    void print()
    {
        Sach::print();
        cout << "thue :" << Thue << endl;
    }
};

//====================================================================================================================================================
class SachThamKhaoNhap : public Sach
{
private:
    int Thue;

public:
    friend istream &operator>>(istream &in, SachThamKhaoNhap &x)
    {
        cout << "nhap ma :";
        in >> x.Ma;
        cout << " nhap ngay :";
        do
        {
            in >> x.ngay;
            if (x.ngay < 0 || x.ngay > 31)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.ngay < 0 || x.ngay > 31);
        cout << " nhap thang :";
        do
        {
            in >> x.thang;
            if (x.thang < 0 || x.thang > 12)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.thang < 0 || x.thang > 12);
        cout << " nhap nam :";
        do
        {
            in >> x.nam;
            if (x.nam > 2025 || x.nam < 0)
            {
                cout << " sai ki tu nhap lai " << endl;
            }

        } while (x.nam > 2025 || x.nam < 0);
        cout << "nhap don gia :";
        in >> x.DonGia;
        cout << "nhap so luong :";
        in >> x.SoLuong;
        cout << "nhap nha xuat ban :";
        in.ignore();
        getline(in, x.NhaXuatBan);
        cout << "nhap thue :";
        in >> x.Thue;
        return in;
    }
    friend ostream &operator<<(ostream &out, SachThamKhaoNhap x)
    {
        out << x.Ma << endl;
        out << x.ngay << endl;
        out << x.thang << endl;
        out << x.nam << endl;
        out << x.DonGia << endl;
        out << x.SoLuong << endl;
        out << x.NhaXuatBan << endl;
        out << x.Thue << endl;

        return out;
    }
};
//====================================================================================================================================================
class DanhSachSach
{
private:
public:
    void Them()
    {
        cout << "1 sach giao trinh " << endl;
        cout << "2 sach tham khao " << endl;
        int chose;
        cin >> chose;
        if (chose == 1)
        {
            ofstream file("SachGiaoTrinh.txt", ios::app);
            SachGiaoTrinhNhap a;
            cin >> a;

            file << a;
            file.close();
        }
        else if (chose == 2)
        {
            ofstream file("SachThamKhao.txt", ios::app);
            SachThamKhaoNhap a;
            cin >> a;

            file << a;
            file.close();
        }
        else
        {
            cout << " khong hop le " << endl;
        }
    }

    void DanhSach()
    {
        cout << "1 sach giao trinh " << endl;
        cout << "2 sach tham khao " << endl;
        int chose;
        cin >> chose;
        if (chose == 1)
        {
            ifstream file("SachGiaoTrinh.txt", ios::in);
            SachGiaoTrinh a;
            while (file >> a)
            {
                a.print();
                cout << "/////////////////////" << endl;
            }
            file.close();
        }
        else if (chose == 2)
        {
            ifstream file("SachThamKhao.txt", ios::in);
            SachThamKhao a;
            while (file >> a)
            {
                a.print();
                cout << "/////////////////////" << endl;
            }
            file.close();
        }
        else
        {
            cout << " khong hop le " << endl;
        }
    }

    void SortGiaoTrinh()
    {
        SachGiaoTrinh a[1000];
        int i = 0;
        ifstream file("SachGiaoTrinh.txt", ios::in);
        while (file >> a[i])
        {
            i++;
        }
        int m = i;
        sort(a, m);
        for (int i = 0; i < m; i++)
        {
            a[i].print();
        }
    }

    void SortThamKhao()
    {
        SachThamKhao a[1000];
        int i = 0;
        ifstream file("SachThamKhao.txt", ios::in);
        while (file >> a[i])
        {
            i++;
        }
        int m = i;
        sort(a, m);
        for (int i = 0; i < m; i++)
        {
            a[i].print();
        }
    }
    void SortGiaoTrinhSL()
    {
        SachGiaoTrinh a[1000];
        int i = 0;
        ifstream file("SachGiaoTrinh.txt", ios::in);
        while (file >> a[i])
        {
            i++;
        }
        int m = i;
        sortGiam(a, m);
        for (int i = 0; i < m; i++)
        {
            a[i].print();
        }
    }
    void SortThamKhaoSL()
    {
        SachThamKhao a[1000];
        int i = 0;
        ifstream file("SachThamKhao.txt", ios::in);
        while (file >> a[i])
        {
            i++;
        }
        int m = i;
        sortGiam(a, m);
        for (int i = 0; i < m; i++)
        {
            a[i].print();
        }
    }
};

//====================================================================================================================================================
//====================================================================================================================================================
int check;
//=====================================================================================================================================================

void menu()
{
    DanhSachSach a;
    switch (check)
    {
    case 1:
        a.Them();
        break;
    case 2:
        a.DanhSach();
        break;
    case 3:
        a.SortGiaoTrinh();
        break;
    case 4:
        a.SortThamKhao();
        break;
    case 5:
        a.SortGiaoTrinhSL();
        break;
    case 6:
        a.SortThamKhaoSL();
        break;
    case 7:

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
        cout << " 1  them  " << endl;
        cout << " 2  liet ke danh sach " << endl;
        cout << " 3  xap xep giao trinh theo ngay " << endl;
        cout << " 4  xap xep tham khao theo ngay " << endl;
        cout << " 5  xap xep giao trinh so luong " << endl;
        cout << " 6  xap xep tham khao so luong " << endl;
        cout << " 7   " << endl;
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




