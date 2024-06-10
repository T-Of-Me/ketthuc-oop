#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;
class KhachThueNhap
{
private:
    string ten;
    int tuoi;
    int scmnd;

public:
    KhachThueNhap(){};
    ~KhachThueNhap(){};

    friend ostream &operator<<(ostream &out, KhachThueNhap &k)
    {
        out << k.ten << endl;
        out << k.tuoi << endl;
        out << k.scmnd << endl;
        return out;
    };
    friend istream &operator>>(istream &in, KhachThueNhap &k)
    {
        cout << "nhap ten :";
        in.ignore();
        getline(in, k.ten);
        cout << "nhap tuoi :";
        in >> k.tuoi;
        cout << "nhap so chung minh nhan dan :";
        in >> k.scmnd;
        return in;
    };
    int Returnscmnd()
    {
        return scmnd;
    }
};
//====================================================================================================================
class KhachThueDoc
{
private:
    string ten;
    int tuoi;
    int scmnd;

public:
    KhachThueDoc(){};
    ~KhachThueDoc(){};

    friend ostream &operator<<(ostream &out, KhachThueDoc &k)
    {
        out << k.ten << endl;
        out << k.tuoi << endl;
        out << k.scmnd << endl;
        return out;
    };
    friend istream &operator>>(istream &in, KhachThueDoc &k)
    {
        in.ignore();
        getline(in, k.ten);
        in >> k.tuoi;
        in >> k.scmnd;
        return in;
    };
    int Returnscmnd()
    {
        return scmnd;
    }
    void print()
    {

        cout << "ten :" << ten << endl;
        cout << "tuoi :" << tuoi << endl;
        cout << "So chung minh nhan dan :" << scmnd << endl;
    }
};

//====================================================================================================================

//========================================================================================================
class ThuePhongDoc : public KhachThueNhap
{
private:
    int ThoiLuongThue;
    char LoaiPhong;
    int scmnd1;
    string DonGia; // theo ngay theo gio

public:
    char ReturnLoaiPhong()
    {
        return LoaiPhong;
    }
    int ReturnThoiLuong()
    {
        return ThoiLuongThue;
    }
    string ReturnDonGia()
    {
        return DonGia;
    }
    ThuePhongDoc(int scmnd, int ThoiLuongThue, char a, string DonGia)
    {
        this->ThoiLuongThue = ThoiLuongThue;
        this->LoaiPhong = a;
        this->scmnd1 = scmnd;
        this->DonGia = DonGia;
    }
    ThuePhongDoc(){};
    ~ThuePhongDoc(){};
    int ReturnScmnd1()
    {
        return scmnd1;
    }
    friend ostream &operator<<(ostream &out, ThuePhongDoc &k)
    {
        out << k.scmnd1 << endl;
        out << k.ThoiLuongThue << endl;
        out << k.LoaiPhong << endl;
        out << k.DonGia << endl;
        return out;
    };
    friend istream &operator>>(istream &in, ThuePhongDoc &k)
    {

        in >> k.scmnd1;
        in >> k.ThoiLuongThue;
        in >> k.LoaiPhong;
        in.ignore();
        getline(in, k.DonGia);
        return in;
    }
    void print()
    {
        cout << "So chung minh nhan dan :" << scmnd1 << endl;
        cout << "Thoi luong thue :" << ThoiLuongThue << " " << DonGia << endl;
        cout << "Loai phong :" << LoaiPhong << endl;
    }
};
//===============================================================
class QuanLyKhachSan
{
private:
public:
    void ThemThongTinKhachHang()
    {
        KhachThueNhap a;
        ofstream File1("ThongTinKhachHang.txt", ios::app);
        cin >> a;
        File1 << a;
        File1.close();
    }

    void QuaTrinhThuePhong()
    {

        cout << " nhap scmnd de kiem tra :";
        int scmnd;
        cin >> scmnd;
        if (ThongTinKhachHangTonTai(scmnd) != 0)
        {
            if (ThongTinThuePhongTonTai(scmnd) != 0)
            {
            }
            else
            {
                ThuePhong(scmnd);
            }
        }
        else
        {
            cout << " nhap thong tin khach hang" << endl;
            ThemThongTinKhachHang();
            cout << " nhap scmnd de thue phong :";
            cin >> scmnd;
            ThuePhong(scmnd);
        }
    }

    void ThuePhong(int scmnd)
    {
        int ThoiLuongThue;
        string DonGia;
        char LoaiPhong;
        cout << "nhap loai phong:";
        do
        {
            cin >> LoaiPhong;
            if (LoaiPhong != 'A' && LoaiPhong != 'B' && LoaiPhong != 'C')
            {
                cout << " sai ki tu !!!!!!!!" << endl;
                cout << " co 1 loai phong A B C" << endl;
            }

        } while (LoaiPhong != 'A' && LoaiPhong != 'B' && LoaiPhong != 'C');
        cout << "nhap kieu thue phong :";
        do
        {
            getline(cin, DonGia);
            if (DonGia != "ngay" && DonGia != "gio")
            {
                cout << " co hai kieu ngay va gio " << endl;
            }
        } while (DonGia != "ngay" && DonGia != "gio");
        if (DonGia == "ngay")
        {
            cout << "thue bao nhieu ngay :";
            cin >> ThoiLuongThue;
        }
        else
        {
            cout << "thue bao nhieu gio :";
            cin >> ThoiLuongThue;
        }
        ThuePhongDoc a(scmnd, ThoiLuongThue, LoaiPhong, DonGia);
        ofstream File1("ThongTinThuePhong.txt", ios::app);
        File1 << a;
        File1.close();
    }

    int ThongTinKhachHangTonTai(int scmnd)
    {
        // kiem tra thong tin khach hang

        ifstream File1("ThongTinKhachHang.txt", ios::in);
        KhachThueDoc a;
        while (File1 >> a)
        {
            if (a.Returnscmnd() == scmnd)
            {
                cout << "thong tin khach hang ton tai " << endl;
                return 1;
                File1.close();
            }
        }
        File1.close();
        return 0;
    }

    int ThongTinThuePhongTonTai(int scmnd)
    {
        ifstream File1("ThongTinThuePhong.txt", ios::in);
        ThuePhongDoc a;
        while (File1 >> a)
        {
            if (a.ReturnScmnd1() == scmnd)
            {
                cout << "khach hang dang thue phong" << endl;
                a.print();
                File1.close();
                return 1;
            }
        }
        cout << "Khach hang chua thue phong!!!!!" << endl;
        File1.close();
        return 0;
    }

    void KiemTraThongTinKhachHangDaThuePhong()
    {
        ifstream File1("ThongTinThuePhong.txt", ios::in);
        cout << "nhap scmnd khach de kiem tra thong tin :";
        int scmnd;
        cin >> scmnd;
        ThuePhongDoc a;
        bool check = false;
        while (File1 >> a)
        {
            if (a.ReturnScmnd1() == scmnd)
            {
                check = true;
                a.print();
                break;
            }
        }
        if (check == false)
        {
            cout << "thong tin khach hang chua ton tai" << endl;
        }
        File1.close();
    }
    void XemThongTinKhachHangThue()
    {
        ifstream File1("ThongTinKhachHang.txt", ios::in);
        cout << "nhap scmnd khach de kiem tra thong tin :";
        int k;
        cin >> k;
        bool check = false;
        KhachThueDoc a;
        while (File1 >> a)
        {
            if (a.Returnscmnd() == k)
            {

                a.print();
                File1.close();
                check = true;
                break;
            }
        }
        if (check == false)
        {
            cout << "thong tin khach hang chua ton tai" << endl;
        }
        File1.close();
    }
};
// ================================================================================================================

class HoaDon
{
private:
public:
    void XuatHoaDon()
    {
        ifstream File1("ThongTinThuePhong.txt", ios::in);
        ThuePhongDoc a;
        cout << "nhap scmnd de xuat hoa don : ";
        int scmnd;
        cin >> scmnd;
        char lp;
        int tl;
        string dg;
        bool check = false;
        while (File1 >> a)
        {
            if (a.ReturnScmnd1() == scmnd)
            {
                lp = a.ReturnLoaiPhong();
                tl = a.ReturnThoiLuong();
                dg = a.ReturnDonGia();
                InHoaDon(scmnd, lp, tl, dg);
                check = true;
                File1.close();
                break;
            }
        }
        if (check == false)
        {
            cout << "thong tin khach hang chua ton tai" << endl;
        }
    }
    void InHoaDon(int scmnd, char loaiPhong, int ThoiLuong, string DonGia)
    {
        int tong = 0;
        if (DonGia == "gio")
        {
            if (loaiPhong == 'A')
            {
                tong = 500 * ThoiLuong;
            }
            else if (loaiPhong == 'B')
            {
                tong = 300 * ThoiLuong;
            }
            else
            {
                tong = 100 * ThoiLuong;
            }
            cout << "=======HOA DON==========" << endl;
            cout << " so chung minh nhan dan :" << scmnd << endl;
            cout << "Thanh tien :" << tong << " cho " << ThoiLuong << " gio" << endl;
            cout << "========================" << endl;
        }
        else if (DonGia == "ngay")
        {
            if (loaiPhong == 'A')
            {
                tong = 500 * ThoiLuong * 24 * 1 / 2;
            }
            else if (loaiPhong == 'B')
            {
                tong = 300 * ThoiLuong * 24 * 1 / 2;
            }
            else
            {
                tong = 100 * ThoiLuong * 24 * 1 / 2;
            }
            cout << "=======HOA DON==========" << endl;
            cout << " so chung minh nhan dan :" << scmnd << endl;
            cout << "Thanh tien :" << tong << " cho " << ThoiLuong << " ngay" << endl;
            cout << "========================" << endl;
        }

        ofstream File1("ThuNhap.txt", ios::app);
        File1 << tong << endl;
        File1.close();
    }
    void TongThuNhap()
    {
        ifstream File1("ThuNhap.txt");
        int x = 0;
        int tong = 0;
        while (File1 >> x)
        {
            tong += x;
        }
        cout << "tong thu nhap la :" << tong << "$" << endl;
        File1.close();
    }
};

//====================================================================================================================
//====================================================================================================================
int answer;
void menu()
{
    QuanLyKhachSan a;
    HoaDon b;
    switch (answer)
    {
    case 1:
        a.QuaTrinhThuePhong();
        break;
    case 2:
        a.ThemThongTinKhachHang();
        break;
    case 3:
        a.KiemTraThongTinKhachHangDaThuePhong();
        break;
    case 4:
        a.XemThongTinKhachHangThue();
        break;
    case 5:
        b.XuatHoaDon();
        break;
    case 6:
        b.TongThuNhap();
        break;
    case 7:

        break;
    case 8:

        break;
    case 9:

        break;
    default:
        cout << "Bad choice! Exit program: \n";
        break;
    }
}

// ===================================================================================================================
int main()
{
    bool keepLooping = true;
    while (keepLooping)
    {

        cout << "------CHAO MUNG DEN VOI KHACH SAN------  " << endl;
        cout << " (1) thue phong  " << endl;
        cout << " (2) them thong tin khach hang  " << endl;
        cout << " (3) kiem tra thong tin thue phong " << endl;
        cout << " (4) kiem tra thong tin khach hang " << endl;
        cout << " (5) xuat hoa don " << endl;
        cout << " (6) tong thu nhap  " << endl;
        cout << " (7) " << endl;
        cout << " (8)  " << endl;
        cout << " (9)    " << endl;
        cin >> answer;
        menu();
        if (answer >= 1 && answer <= 10)
            keepLooping = true;
        else
            keepLooping = false;
    }
    getch();
    return answer;
}
