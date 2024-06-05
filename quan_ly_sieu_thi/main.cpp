

#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>

template <class T>
T sort(T a[50], int m)
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
    return a[0];
}

//===========================================================================================================

class HangHoa
{
protected:
    int MaHang;
    string TenHang;
    int SoLuongTon;
    int DonGia;

public:
    HangHoa(){};
    friend void CapNhatThongTin();
    ~HangHoa(){};
    void print()
    {
        cout << "Ma hang :" << MaHang << endl;
        cout << "Ten hang :" << TenHang << endl;
        cout << "So luong ton kho :" << SoLuongTon << endl;
        cout << "Don gia :" << DonGia << endl;
    }
};

//====================================================================================================================================================

class ThucPhamNhap : public HangHoa
{
private:
    int NgaySanXuat;
    int ThangSanXuat;
    int NamSanXuat;
    int NgayHetHan;
    int ThangHetHan;
    int NamHetHan;
    string NhaCungCap;

public:
    ThucPhamNhap(int ma, int soluong, int dongia, int ngays, int thangs, int nams, int ngayh, int thangh, int namh, string tenhang, string nhacungcap)
    {
        this->MaHang = ma;
        this->SoLuongTon = soluong;
        this->DonGia = dongia;
        this->NgaySanXuat = ngays;
        this->ThangSanXuat = thangs;
        this->NamSanXuat = nams;
        this->NgayHetHan = ngayh;
        this->ThangHetHan = thangh;
        this->NamHetHan = namh;
        this->TenHang = tenhang;
        this->NhaCungCap = nhacungcap;
    };
    ThucPhamNhap(){};
    ~ThucPhamNhap(){};

    friend ostream &operator<<(ostream &out, ThucPhamNhap x)
    {
        out << x.MaHang << endl;
        out << x.TenHang << endl;
        out << x.SoLuongTon << endl;
        out << x.DonGia << endl;

        out << x.NgaySanXuat << endl;
        out << x.ThangSanXuat << endl;
        out << x.NamSanXuat << endl;
        out << x.NgayHetHan << endl;
        out << x.ThangHetHan << endl;
        out << x.NamHetHan << endl;
        out << x.NhaCungCap << endl;
        return out;
    }
    friend istream &operator>>(istream &in, ThucPhamNhap &x)
    {
        cout << " nhap ma giao dich :";
        in >> x.MaHang;
        cout << "nhap ten hang :";
        in.ignore();
        getline(in, x.TenHang);
        cout << "nhap so luong :";
        in >> x.SoLuongTon;
        cout << "nhap don gia :";
        in >> x.DonGia;

        cout << "  nhap ngay san xuat -->";
        cout << " nhap ngay :";
        do
        {
            in >> x.NgaySanXuat;
            if (x.NgaySanXuat < 0 || x.NgaySanXuat > 31)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.NgaySanXuat < 0 || x.NgaySanXuat > 31);
        cout << " nhap thang :";
        do
        {
            in >> x.ThangSanXuat;
            if (x.ThangSanXuat < 0 || x.ThangSanXuat > 12)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.ThangSanXuat < 0 || x.ThangSanXuat > 12);
        cout << " nhap nam :";
        do
        {
            in >> x.NamSanXuat;
            if (x.NamSanXuat > 2024)
            {
                cout << " sai ki tu nhap lai " << endl;
            }

        } while (x.NamSanXuat > 2024);
        cout << "  nhap ngay het han -->";
        cout << " nhap ngay :";
        do
        {
            in >> x.NgayHetHan;
            if (x.NgayHetHan < 0 || x.NgayHetHan > 31)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.NgayHetHan < 0 || x.NgayHetHan > 31);
        cout << " nhap thang :";
        do
        {
            in >> x.ThangHetHan;
            if (x.ThangHetHan < 0 || x.ThangHetHan > 12)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.ThangHetHan < 0 || x.ThangHetHan > 12);
        cout << " nhap nam :";
        do
        {
            in >> x.NamHetHan;
            if (x.NamHetHan > 2024)
            {
                cout << " sai ki tu nhap lai " << endl;
            }

        } while (x.NamHetHan > 2024);
        cout << "nhap nha cung cap :";
        in.ignore();
        getline(in, x.NhaCungCap);

        return in;
    }
};
//====================================================================================================================================================
class ThucPham : public HangHoa
{
private:
    int NgaySanXuat;
    int ThangSanXuat;
    int NamSanXuat;
    int NgayHetHan;
    int ThangHetHan;
    int NamHetHan;
    string NhaCungCap;

public:
    friend class QuanLy;
    friend void CapNhatThongTin();
    int TriTonKho()
    {
        return SoLuongTon * DonGia * (1 + 5 / 100);
    }
    friend bool operator<(ThucPham a, ThucPham b)
    {
        return a.TriTonKho() < b.TriTonKho();
    }
    friend int CheckMaHangHoaTonTai(int c, int b, string a);
    friend void TimKiem();
    ThucPham(){};
    ~ThucPham(){};
    friend void XoaHangHoa();
    friend ostream &operator<<(ostream &out, ThucPham x)
    {
        out << x.MaHang << endl;
        out << x.TenHang << endl;
        out << x.SoLuongTon << endl;
        out << x.DonGia << endl;

        out << x.NgaySanXuat << endl;
        out << x.ThangSanXuat << endl;
        out << x.NamSanXuat << endl;
        out << x.NgayHetHan << endl;
        out << x.ThangHetHan << endl;
        out << x.NamHetHan << endl;
        out << x.NhaCungCap << endl;
        return out;
    }
    friend istream &operator>>(istream &in, ThucPham &x)
    {
        in >> x.MaHang;
        in.ignore();
        getline(in, x.TenHang);
        in >> x.SoLuongTon;
        in >> x.DonGia;

        in >> x.NgaySanXuat;
        in >> x.ThangSanXuat;
        in >> x.NamSanXuat;
        in >> x.NgayHetHan;
        in >> x.ThangHetHan;
        in >> x.NamHetHan;

        in.ignore();
        getline(in, x.NhaCungCap);
        return in;
    }
    void print()
    {
        HangHoa::print();
        cout << "ngay san xuat :" << NgaySanXuat << "/" << ThangSanXuat << "/" << NamSanXuat << endl;
        cout << "ngay het han :" << NgayHetHan << "/" << ThangHetHan << "/" << NamHetHan << endl;
        cout << "Nha cung cap :" << NhaCungCap << endl;
    }
};
//====================================================================================================================================================4

class DienMayNhap : public HangHoa
{
private:
    int ThoiGianBaoHanh;
    int CongXuat;
    string ChungLoai;

public:
    DienMayNhap(){};
    ~DienMayNhap(){};
    friend ostream &operator<<(ostream &out, DienMayNhap x)
    {
        out << x.MaHang << endl;
        out << x.TenHang << endl;
        out << x.SoLuongTon << endl;
        out << x.DonGia << endl;

        out << x.ThoiGianBaoHanh << endl;
        out << x.CongXuat << endl;
        out << x.ChungLoai << endl;

        return out;
    }
    friend istream &operator>>(istream &in, DienMayNhap &x)
    {
        cout << " nhap ma giao dich :";
        in >> x.MaHang;
        cout << "nhap ten hang :";
        in.ignore();
        getline(in, x.TenHang);
        cout << "nhap so luong :";
        in >> x.SoLuongTon;
        cout << "nhap don gia :";
        in >> x.DonGia;

        cout << "Nhap thoi gian bao hanh :";
        in >> x.ThoiGianBaoHanh;
        cout << "Nhap cong xuat :";
        in >> x.CongXuat;
        cout << "nhap chung loai :";
        in.ignore();
        getline(in, x.ChungLoai);

        return in;
    }
};
//===============================================================================================================================================

class DienMay : public HangHoa
{
private:
    int ThoiGianBaoHanh;
    int CongXuat;
    string ChungLoai;

public:
    friend class QuanLy;
    int TriTonKho()
    {
        return SoLuongTon * DonGia * (1 + 10 / 100);
    }
    friend bool operator<(DienMay a, DienMay b)
    {
        return a.TriTonKho() < b.TriTonKho();
    }
    friend void CapNhatThongTin();
    friend void XoaHangHoa();
    friend int CheckMaHangHoaTonTai(int c, int b, string a);
    friend void TimKiem();
    friend void CapNhatThongTinDienMay();
    DienMay(int mahang, int soluong, int dongia, int thoigianbaohanh, int congxuat, string tenhang, string chungloai)
    {
        this->MaHang = mahang;
        this->SoLuongTon = soluong;
        this->DonGia = dongia;
        this->ThoiGianBaoHanh = thoigianbaohanh;
        this->CongXuat = congxuat;
        this->TenHang = tenhang;
        this->ChungLoai = chungloai;
    };
    ~DienMay(){};
    DienMay(){};
    friend ostream &operator<<(ostream &out, DienMay x)
    {
        out << x.MaHang << endl;
        out << x.TenHang << endl;
        out << x.SoLuongTon << endl;
        out << x.DonGia << endl;

        out << x.ThoiGianBaoHanh << endl;
        out << x.CongXuat << endl;
        out << x.ChungLoai << endl;

        return out;
    }
    friend istream &operator>>(istream &in, DienMay &x)
    {

        in >> x.MaHang;
        in.ignore();
        getline(in, x.TenHang);
        in >> x.SoLuongTon;
        in >> x.DonGia;
        in >> x.ThoiGianBaoHanh;
        in >> x.CongXuat;
        in.ignore();
        getline(in, x.ChungLoai);
        return in;
    }
    void print()
    {
        HangHoa::print();
        cout << "Thoi gian bao hanh :" << ThoiGianBaoHanh << " gio " << endl;
        cout << "Cong xuat :" << CongXuat << "KW" << endl;
        cout << "Chung loai :" << ChungLoai << endl;
    }
};
//=====================================================================================================================================================

class MayMacNhap : public HangHoa
{
private:
    string TenNhaSanXuat;
    int NgayNhapKho;
    int ThangNhapKho;
    int NamNhapKho;

public:
    MayMacNhap(){};
    ~MayMacNhap(){};
    friend ostream &operator<<(ostream &out, MayMacNhap x)
    {
        out << x.MaHang << endl;
        out << x.TenHang << endl;
        out << x.SoLuongTon << endl;
        out << x.DonGia << endl;

        out << x.NgayNhapKho << endl;
        out << x.ThangNhapKho << endl;
        out << x.NamNhapKho << endl;
        out << x.TenNhaSanXuat << endl;
        return out;
    }
    friend istream &operator>>(istream &in, MayMacNhap &x)
    {
        cout << " nhap ma giao dich :";
        in >> x.MaHang;
        cout << "nhap ten hang :";
        in.ignore();
        getline(in, x.TenHang);
        cout << "nhap so luong :";
        in >> x.SoLuongTon;
        cout << "nhap don gia :";
        in >> x.DonGia;

        cout << "  nhap ngay nhap kho  -->";
        cout << " nhap ngay :";
        do
        {
            in >> x.NgayNhapKho;
            if (x.NgayNhapKho < 0 || x.NgayNhapKho > 31)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.NgayNhapKho < 0 || x.NgayNhapKho > 31);
        cout << " nhap thang :";
        do
        {
            in >> x.ThangNhapKho;
            if (x.ThangNhapKho < 0 || x.ThangNhapKho > 12)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.ThangNhapKho < 0 || x.ThangNhapKho > 12);
        cout << " nhap nam :";
        do
        {
            in >> x.NamNhapKho;
            if (x.NamNhapKho > 2024)
            {
                cout << " sai ki tu nhap lai " << endl;
            }

        } while (x.NamNhapKho > 2024);
        cout << "Nhap ten nha san xuat :";
        in.ignore();
        getline(in, x.TenNhaSanXuat);

        return in;
    }
};

//=====================================================================================================================================================
class MayMac : public HangHoa
{
private:
    string TenNhaSanXuat;
    int NgayNhapKho;
    int ThangNhapKho;
    int NamNhapKho;

public:
    friend class QuanLy;
    int TriTonKho()
    {
        return SoLuongTon * DonGia * (1 + 10 / 100);
    }
    friend bool operator<(MayMac a, MayMac b)
    {
        return a.TriTonKho() < b.TriTonKho();
    }
    void print()
    {
        HangHoa::print();
        cout << "ten nha san xuat :" << TenNhaSanXuat << endl;
        cout << "ngay nhap :" << NgayNhapKho << "/" << ThangNhapKho << "/" << NamNhapKho << endl;
    }
    friend void CapNhatThongTin();
    friend void TimKiem();
    friend void XoaHangHoa();
    friend void CapNhatThongTinMayMac();
    friend int CheckMaHangHoaTonTai(int c, int b, string a);
    MayMac(int mahang, int soluong, int dongia, int ngay, int thang, int nam, string tenhang, string tennhasanxuat)
    {
        this->MaHang = mahang;
        this->SoLuongTon = soluong;
        this->DonGia = dongia;
        this->NgayNhapKho = ngay;
        this->ThangNhapKho = thang;
        this->NamNhapKho = nam;
        this->TenNhaSanXuat = tennhasanxuat;
        this->TenHang = tenhang;
    };
    MayMac(){};
    ~MayMac(){};
    friend ostream &operator<<(ostream &out, MayMac x)
    {
        out << x.MaHang << endl;
        out << x.TenHang << endl;
        out << x.SoLuongTon << endl;
        out << x.DonGia << endl;

        out << x.NgayNhapKho << endl;
        out << x.ThangNhapKho << endl;
        out << x.NamNhapKho << endl;
        out << x.TenNhaSanXuat << endl;
        return out;
    }
    friend istream &operator>>(istream &in, MayMac &x)
    {

        in >> x.MaHang;
        in.ignore();
        getline(in, x.TenHang);
        in >> x.SoLuongTon;
        in >> x.DonGia;
        in >> x.NgayNhapKho;
        in >> x.ThangNhapKho;
        in >> x.NamNhapKho;
        in.ignore();
        getline(in, x.TenNhaSanXuat);

        return in;
    }
};

int CheckMaHangHoaTonTai(int chose, int z, string ten)
{
    if (chose == 1)
    {
        ThucPham a;
        ifstream File("ThucPham.txt", ios::in);
        while (File >> a)
        {
            if (a.MaHang == z && a.TenHang == ten)
            {
                cout << "Ma hang hoa ton tai " << endl;
                return 1;
            }
        }
        cout << "ma khong ton tai " << endl;
        return 0;
    }
    else if (chose == 2)
    {
        DienMay a;
        ifstream File("DienMay.txt", ios::in);
        while (File >> a)
        {
            if (a.MaHang == z && a.TenHang == ten)
            {
                cout << "Ma hang hoa ton tai " << endl;
                return 1;
            }
        }
        cout << "ma khong ton tai " << endl;
        return 0;
    }
    else
    {
        MayMac a;
        ifstream File("MayMac.txt", ios::in);
        while (File >> a)
        {
            if (a.MaHang == z && a.TenHang == ten)
            {
                cout << "Ma hang hoa ton tai " << endl;
                return 1;
            }
        }
        cout << "ma khong ton tai " << endl;
        return 0;
    }
}
class QuanLy
{
private:
public:
    void CapNhatThongTinMayMac()
    {
        int ma, soluong, dongia, ngay, thang, nam;
        char tenhang[100], tennhasanxuat[100];
        string t;
        bool checking = false;
        do
        {
            cout << "nhap ma de tim san pham :";
            cin >> ma;
            cout << "nhap ten:";
            cin.ignore();
            getline(cin, t);
            MayMac a;
            ifstream File("MayMac.txt", ios::in);
            while (File >> a)
            {
                if (a.MaHang == ma && a.TenHang == t)
                {
                    cout << "da tim thay ma ....." << endl;
                    checking = true;
                }
            }
            if (checking == false)
            {
                cout << "ma san pham khong ton tai " << endl;
            }
            File.close();
        } while (checking == false);
        MayMac a;
        ifstream File1("MayMac.txt", ios::in);
        ofstream File2("MayMacTemp.txt", ios::trunc);
        while (File1 >> a)
        {
            if (a.MaHang == ma && a.TenHang == t)
            {
                cout << " Loading........" << endl;
                soluong = a.SoLuongTon;
                dongia = a.DonGia;
                ngay = a.NgayNhapKho;
                thang = a.ThangNhapKho;
                nam = a.NamNhapKho;
                const char *t = a.TenHang.c_str();
                strcpy(tenhang, t);
                const char *k = a.TenNhaSanXuat.c_str();
                strcpy(tennhasanxuat, k);
            }
            else
            {
                File2 << a;
            }
        }
        File1.close();
        File2.close();
        ifstream File4("MayMacTemp.txt", ios::in);
        ofstream File3("MayMac.txt", ios::trunc);
        while (File4 >> a)
        {
            File3 << a;
        }
        File3.close();
        File4.close();
        cout << "1 thay doi ngay nhap kho " << endl;
        cout << "2 thay doi ten nha san xuat" << endl;
        cout << "3 thay doi luong ton" << endl;
        cout << "4 thay doi don gia" << endl;
        int check;
        cin >> check;
        if (check == 1)
        {
            int NGAY, THANG, NAM;
            cout << " nhap ngay :";
            do
            {
                cin >> NGAY;
                if (NGAY < 0 || NGAY > 31)
                {
                    cout << " sai ki tu nhap lai " << endl;
                }
            } while (NGAY < 0 || NGAY > 31);
            cout << " nhap thang :";
            do
            {
                cin >> THANG;
                if (THANG < 0 || THANG > 12)
                {
                    cout << " sai ki tu nhap lai " << endl;
                }
            } while (THANG < 0 || THANG > 12);
            cout << " nhap nam :";
            do
            {
                cin >> NAM;
                if (NAM > 2024)
                {
                    cout << " sai ki tu nhap lai " << endl;
                }

            } while (NAM > 2024);
            MayMac x(ma, soluong, dongia, NGAY, THANG, NAM, tenhang, tennhasanxuat);
            ofstream File5("MayMac.txt", ios::app);
            File5 << x;
            File5.close();
        }
        else if (check == 2)
        {
            cout << "nhap ten :";
            string NHASANXUAT;
            cin.ignore();
            getline(cin, NHASANXUAT);
            MayMac x(ma, soluong, dongia, ngay, thang, nam, tenhang, NHASANXUAT);
            ofstream File5("MayMac.txt", ios::app);
            File5 << x;
            File5.close();
        }
        else if (check == 3)
        {

            cout << "luong ton :";
            int LUONGTON;
            cin >> LUONGTON;
            MayMac x(ma, LUONGTON, dongia, ngay, thang, nam, tenhang, tennhasanxuat);
            ofstream File5("MayMac.txt", ios::app);
            File5 << x;
            File5.close();
        }
        else if (check == 2)
        {
            cout << "don gia :";
            int DONGIA;
            cin >> DONGIA;
            MayMac x(ma, soluong, DONGIA, ngay, thang, nam, tenhang, tennhasanxuat);
            ofstream File5("MayMac.txt", ios::app);
            File5 << x;
            File5.close();
        }
    }
    void ThemHangHoa()
    {
        cout << "1 them thuc pham" << endl;
        cout << "2 them dien may" << endl;
        cout << "3 them may mac" << endl;
        int chose;
        int ma = 0;
        cout << "nhap lua chon " << endl;
        string ten;
        cin >> chose;
        if (chose == 1)
        {
            cout << "Nhap ma va ten de kiem tra thuc pham " << endl;
            do
            {
                cin >> ma;
                cout << "ten :";
                cin.ignore();
                getline(cin, ten);
            } while (CheckMaHangHoaTonTai(chose, ma, ten));
            ThucPhamNhap a;
            ofstream File("ThucPham.txt", ios::app);
            cin >> a;
            File << a;
            File.close();
        }
        else if (chose == 2)
        {
            cout << "Nhap ma de kiem tra dien may " << endl;
            do
            {
                cin >> ma;
                cout << "ten :";
                cin.ignore();
                getline(cin, ten);
            } while (CheckMaHangHoaTonTai(chose, ma, ten));
            cout << "them dien may" << endl;
            DienMay a;
            ofstream File("DienMay.txt", ios::app);
            cin >> a;
            File << a;
            File.close();
        }
        else if (chose == 3)
        {
            cout << "Nhap ma de kiem tra may mac" << endl;
            do
            {
                cin >> ma;
                cout << "ten :";
                cin.ignore();
                getline(cin, ten);
            } while (CheckMaHangHoaTonTai(chose, ma, ten));
            cout << "them may moc" << endl;
            MayMac a;
            ofstream File("MayMac.txt", ios::app);
            cin >> a;
            File << a;
            File.close();
        }
        else
        {
            cout << " sai ki tu !!!!!!!!!" << endl;
        }
    }
    void CapNhatThongTinDienMay()
    {
        int ma, soluong, dongia, thoigianbaohanh, congxuat;
        char tenhang[100], chungloai[100];
        string t;
        bool checking = false;
        do
        {
            cout << "nhap ma de tim san pham :";

            cin >> ma;
            cout << "nhap ten :";
            cin.ignore();

            getline(cin, t);
            DienMay a;
            ifstream File("DienMay.txt", ios::in);
            while (File >> a)
            {
                if (a.MaHang == ma && a.TenHang == t)
                {
                    cout << "da tim thay ma ....." << endl;
                    checking = true;
                }
            }
            if (checking == false)
            {
                cout << "ma san pham khong ton tai " << endl;
            }
            File.close();

        } while (checking == false);
        DienMay a;
        ifstream File1("DienMay.txt", ios::in);
        ofstream File2("DienMayTemp.txt", ios::trunc);
        while (File1 >> a)
        {
            if (a.MaHang == ma && a.TenHang == t)
            {
                cout << " Loading........" << endl;
                soluong = a.SoLuongTon;
                dongia = a.DonGia;
                thoigianbaohanh = a.ThoiGianBaoHanh;
                congxuat = a.CongXuat;
                const char *t = a.TenHang.c_str();
                strcpy(tenhang, t);
                const char *k = a.ChungLoai.c_str();
                strcpy(chungloai, k);
            }
            else
            {
                File2 << a;
            }
        }
        File1.close();
        File2.close();
        ifstream File4("DienMayTemp.txt", ios::in);
        ofstream File3("DienMay.txt", ios::trunc);
        while (File4 >> a)
        {
            File3 << a;
        }
        File3.close();
        File4.close();

        // xoa doi tuong thanh cong
        cout << "1 thay doi thoi gian bao hanh " << endl;
        cout << "2 thay doi cong xuat" << endl;
        cout << "3 thay doi chung loai" << endl;
        cout << "4 thay doi luong ton" << endl;
        cout << "5 thay doi don gia" << endl;
        int check;
        cin >> check;
        if (check == 1)
        {
            int THOIGIANBAOHANH;
            cout << "nhap thoi gian bao hanh thay the :";
            cin >> THOIGIANBAOHANH;
            DienMay x(ma, soluong, dongia, THOIGIANBAOHANH, congxuat, tenhang, chungloai);
            ofstream File5("DienMay.txt", ios::app);
            File5 << x;
            File5.close();
        }
        else if (check == 2)
        {
            int CONGXUAT;
            cout << "nhap cong xuat thay the :";
            cin >> CONGXUAT;
            DienMay x(ma, soluong, dongia, thoigianbaohanh, CONGXUAT, tenhang, chungloai);
            ofstream File5("DienMay.txt", ios::app);
            File5 << x;
            File5.close();
        }
        else if (check == 3)
        {
            string CHUNGLOAI;
            cout << "nhap chung loai  thay the :";
            cin.ignore();
            getline(cin, CHUNGLOAI);
            DienMay x(ma, soluong, dongia, thoigianbaohanh, congxuat, tenhang, CHUNGLOAI);
            ofstream File5("DienMay.txt", ios::app);
            File5 << x;
            File5.close();
        }
        else if (check == 4)
        {
            cout << "nhap luong ton thay the:";
            int LUONGTON;
            cin >> LUONGTON;
            DienMay x(ma, LUONGTON, dongia, thoigianbaohanh, congxuat, tenhang, chungloai);
            ofstream File5("DienMay.txt", ios::app);
            File5 << x;
            File5.close();
        }
        else if (check == 5)
        {
            cout << "nhap don gia thay the :";
            int DONGIA;
            cin >> DONGIA;
            DienMay x(ma, soluong, DONGIA, thoigianbaohanh, congxuat, tenhang, chungloai);
            ofstream File5("DienMay.txt", ios::app);
            File5 << x;
            File5.close();
        }
        else
        {
            cout << "sai ki tu !!!!!!!!!!! " << endl;
        }
    }
    void CapNhatThongTin()
    {
        cout << "1   thuc pham" << endl;
        cout << "2   dien may" << endl;
        cout << "3   may mac" << endl;
        int chose;
        cout << "nhap lua chon :";
        cin >> chose;
        if (chose == 1)
        {
            int ma;
            int soluong, dongia, ngayh, thangh, namh, ngays, thangs, nams;
            string t;
            char tenhang[100], nhacungcap[100];
            bool checking = false;
            do
            {
                cout << "nhap ma de tim san pham :";

                cin >> ma;
                cout << "nhap ten :";
                cin.ignore();
                getline(cin, t);
                ThucPham a;
                ifstream File("ThucPham.txt", ios::in);
                while (File >> a)
                {
                    if (a.MaHang == ma && a.TenHang == t)
                    {
                        cout << "da tim thay ma ....." << endl;
                        checking = true;
                    }
                }
                if (checking == false)
                {
                    cout << "ma san pham khong ton tai " << endl;
                }
                File.close();

            } while (checking == false);

            ThucPham a;
            ifstream File1("ThucPham.txt", ios::in);
            ofstream File2("ThucPhamTemp.txt", ios::trunc);
            while (File1 >> a)
            {
                if (a.MaHang == ma && a.TenHang == t)
                {
                    cout << " Loading........" << endl;
                    soluong = a.SoLuongTon;
                    dongia = a.DonGia;
                    ngayh = a.NgayHetHan;
                    thangh = a.ThangHetHan;
                    namh = a.NamHetHan;
                    ngays = a.NgaySanXuat;
                    thangs = a.ThangSanXuat;
                    nams = a.NamSanXuat;
                    const char *t = a.TenHang.c_str();
                    strcpy(tenhang, t);
                    const char *k = a.NhaCungCap.c_str();
                    strcpy(nhacungcap, k);
                }
                else
                {
                    File2 << a;
                }
            }
            File1.close();
            File2.close();
            ifstream File4("ThucPhamTemp.txt", ios::in);
            ofstream File3("ThucPham.txt", ios::trunc);
            while (File4 >> a)
            {
                File3 << a;
            }
            File3.close();
            File4.close();

            // xoa doi tuong thanh cong
            cout << "1 thay doi ngay san xuat " << endl;
            cout << "2 thay doi ngay het han" << endl;
            cout << "3 thay doi nha cung cap" << endl;
            cout << "4 thay doi luong ton" << endl;
            cout << "5 thay doi don gia" << endl;
            int check;
            cin >> check;
            if (check == 1)
            {
                int NGAY, THANG, NAM;
                cout << " nhap ngay :";
                do
                {
                    cin >> NGAY;
                    if (NGAY < 0 || NGAY > 31)
                    {
                        cout << " sai ki tu nhap lai " << endl;
                    }
                } while (NGAY < 0 || NGAY > 31);
                cout << " nhap thang :";
                do
                {
                    cin >> THANG;
                    if (THANG < 0 || THANG > 12)
                    {
                        cout << " sai ki tu nhap lai " << endl;
                    }
                } while (THANG < 0 || THANG > 12);
                cout << " nhap nam :";
                do
                {
                    cin >> NAM;
                    if (NAM > 2024)
                    {
                        cout << " sai ki tu nhap lai " << endl;
                    }

                } while (NAM > 2024);
                ThucPhamNhap x(ma, soluong, dongia, NGAY, THANG, NAM, ngayh, thangh, namh, tenhang, nhacungcap);
                ofstream File5("ThucPham.txt", ios::app);
                File5 << x;
                File5.close();
            }
            else if (check == 2)
            {
                int NGAY, THANG, NAM;
                cout << " nhap ngay :";
                do
                {
                    cin >> NGAY;
                    if (NGAY < 0 || NGAY > 31)
                    {
                        cout << " sai ki tu nhap lai " << endl;
                    }
                } while (NGAY < 0 || NGAY > 31);
                cout << " nhap thang :";
                do
                {
                    cin >> THANG;
                    if (THANG < 0 || THANG > 12)
                    {
                        cout << " sai ki tu nhap lai " << endl;
                    }
                } while (THANG < 0 || THANG > 12);
                cout << " nhap nam :";
                do
                {
                    cin >> NAM;
                    if (NAM > 2024)
                    {
                        cout << " sai ki tu nhap lai " << endl;
                    }

                } while (NAM > 2024);
                ThucPhamNhap x(ma, soluong, dongia, ngays, thangs, nams, NGAY, THANG, NAM, tenhang, nhacungcap);
                ofstream File5("ThucPham.txt", ios::app);
                File5 << x;
                File5.close();
            }
            else if (check == 3)
            {
                cout << "nhap ten nha cung cap thay the :";
                string NHACUNGCAP;
                cin.ignore();
                getline(cin, NHACUNGCAP);
                ThucPhamNhap x(ma, soluong, dongia, ngays, thangs, nams, ngayh, thangh, namh, tenhang, NHACUNGCAP);
                ofstream File5("ThucPham.txt", ios::app);
                File5 << x;
                File5.close();
            }
            else if (check == 4)
            {
                cout << "nhap luong ton thay the:";
                int LUONGTON;
                cin >> LUONGTON;
                ThucPhamNhap x(ma, LUONGTON, dongia, ngays, thangs, nams, ngayh, thangh, namh, tenhang, nhacungcap);
                ofstream File5("ThucPham.txt", ios::app);
                File5 << x;
                File5.close();
            }
            else if (check == 5)
            {
                cout << "nhap don gia thay the :";
                int DONGIA;
                cin >> DONGIA;
                ThucPhamNhap x(ma, soluong, DONGIA, ngays, thangs, nams, ngayh, thangh, namh, tenhang, nhacungcap);
                ofstream File5("ThucPham.txt", ios::app);
                File5 << x;
                File5.close();
            }
            else
            {
                cout << "sai ki tu !!!!!!!!!!! " << endl;
            }
        }
        else if (chose == 2)
        {
            CapNhatThongTinDienMay();
        }
        else if (chose == 3)
        {
            CapNhatThongTinMayMac();
        }
        else
        {
            cout << " sai ki tu " << endl;
        }
    }

    //=====================================================================================================================================================

    //=====================================================================================================================================================

    void TimKiem()
    {
        cout << "1 tim thuc pham" << endl;
        cout << "2 tim dien may" << endl;
        cout << "3 tim may mac" << endl;
        int chose;
        cout << "nhap lua chon :";
        cin >> chose;
        string ten;
        int ma = 0;
        if (chose == 1)
        {
            cout << "Nhap ma de kiem tra thuc pham " << endl;
            do
            {
                cin >> ma;
                cout << "ten :";
                cin.ignore();
                getline(cin, ten);
            } while (!CheckMaHangHoaTonTai(chose, ma, ten));
            ThucPham a;
            ifstream File("ThucPham.txt", ios::in);
            while (File >> a)
            {
                if (a.MaHang == ma && a.TenHang == ten)
                {
                    a.print();
                    break;
                }
            }
            File.close();
        }
        else if (chose == 2)
        {
            cout << "Nhap ma de kiem tra dien may " << endl;
            do
            {
                cin >> ma;
                cout << "ten :";
                cin.ignore();
                getline(cin, ten);
            } while (!CheckMaHangHoaTonTai(chose, ma, ten));
            DienMay a;
            ifstream File("DienMay.txt", ios::in);
            while (File >> a)
            {
                if (a.MaHang == ma && a.TenHang == ten)
                {
                    a.print();
                    break;
                }
            }
            File.close();
        }
        else if (chose == 3)
        {
            cout << "Nhap ma de kiem tra may mac " << endl;
            do
            {
                cin >> ma;
                cout << "ten :";
                cin.ignore();
                getline(cin, ten);
            } while (!CheckMaHangHoaTonTai(chose, ma, ten));
            MayMac a;
            ifstream File("MayMac.txt", ios::in);
            while (File >> a)
            {
                if (a.MaHang == ma && a.TenHang == ten)
                {
                    a.print();
                    break;
                }
            }
            File.close();
        }
        else
        {
            cout << "sai ki tu " << endl;
        }
    }
    //=====================================================================================================================================================

    //=====================================================================================================================================================

    //=====================================================================================================================================================

    //=====================================================================================================================================================
    void XoaHangHoa()
    {
        cout << "1   thuc pham" << endl;
        cout << "2   dien may" << endl;
        cout << "3   may mac" << endl;
        int chose;
        cout << "nhap lua chon :";
        cin >> chose;
        if (chose == 1)
        {
            int ma;
            bool checking = false;
            do
            {
                cout << "nhap ma de tim san pham :";

                cin >> ma;
                ThucPham a;
                ifstream File("ThucPham.txt", ios::in);
                while (File >> a)
                {
                    if (a.MaHang == ma)
                    {
                        cout << "da tim thay ma ....." << endl;
                        checking = true;
                    }
                }
                if (checking == false)
                {
                    cout << "ma san pham khong ton tai " << endl;
                }
                File.close();

            } while (checking == false);

            ThucPham a;
            ifstream File1("ThucPham.txt", ios::in);
            ofstream File2("ThucPhamTemp.txt", ios::trunc);
            while (File1 >> a)
            {
                if (a.MaHang == ma)
                {
                    cout << " Loading........" << endl;
                }
                else
                {
                    File2 << a;
                }
            }
            File1.close();
            File2.close();
            ifstream File4("ThucPhamTemp.txt", ios::in);
            ofstream File3("ThucPham.txt", ios::trunc);
            while (File4 >> a)
            {
                File3 << a;
            }
            File3.close();
            File4.close();
            cout << "da xoa ma " << ma << "cua thuc pham" << endl;
        }
        else if (chose == 2)
        {
            int ma;
            bool checking = false;
            do
            {
                cout << "nhap ma de tim san pham :";
                cin >> ma;
                MayMac a;
                ifstream File("DienMay.txt", ios::in);
                while (File >> a)
                {
                    if (a.MaHang == ma)
                    {
                        cout << "da tim thay ma ....." << endl;
                        checking = true;
                    }
                }
                if (checking == false)
                {
                    cout << "ma san pham khong ton tai " << endl;
                }
                File.close();

            } while (checking == false);
            DienMay a;
            ifstream File1("DienMay.txt", ios::in);
            ofstream File2("DienMayTemp.txt", ios::trunc);
            while (File1 >> a)
            {
                if (a.MaHang == ma)
                {
                    cout << " Loading........" << endl;
                }
                else
                {
                    File2 << a;
                }
            }
            File1.close();
            File2.close();
            ifstream File4("DienMayTemp .txt", ios::in);
            ofstream File3("DienMay.txt", ios::trunc);
            while (File4 >> a)
            {
                File3 << a;
            }
            File3.close();
            File4.close();
            cout << "da xoa " << endl;
        }
        else if (chose == 3)
        {
            int ma;
            bool checking = false;
            do
            {
                cout << "nhap ma de tim san pham :";
                cin >> ma;
                MayMac a;
                ifstream File("MayMac.txt", ios::in);
                while (File >> a)
                {
                    if (a.MaHang == ma)
                    {
                        cout << "da tim thay ma ....." << endl;
                        checking = true;
                    }
                }
                if (checking == false)
                {
                    cout << "ma san pham khong ton tai " << endl;
                }
                File.close();
            } while (checking == false);
            MayMac a;
            ifstream File1("MayMac.txt", ios::in);
            ofstream File2("MayMacTemp.txt", ios::trunc);
            while (File1 >> a)
            {
                if (a.MaHang == ma)
                {
                    cout << " Loading........" << endl;
                }
                else
                {
                    File2 << a;
                }
            }
            File1.close();
            File2.close();
            ifstream File4("MayMacTemp.txt", ios::in);
            ofstream File3("MayMac.txt", ios::trunc);
            while (File4 >> a)
            {
                File3 << a;
            }
            File3.close();
            File4.close();
            cout << "da xoa " << endl;
        }
        else
        {
            cout << " ki tu sai !!!!" << endl;
        }
    }
    //=====================================================================================================================================================
    void MaxThucPham()
    {
        ThucPham b;
        ThucPham a[50];
        int i = 0;
        ifstream file("ThucPham.txt", ios::in);
        while (file >> a[i])
        {
            i++;
        }
        int m = i;
        file.close();
        b = sort(a, m);
        b.print();
    }
    //=====================================================================================================================================================

    //=====================================================================================================================================================
    void MacDienMay()
    {
        DienMay b;
        DienMay a[50];
        int i = 0;
        ifstream file("DienMay.txt", ios::in);
        while (file >> a[i])
        {
            i++;
        }
        int m = i;
        file.close();
        cout << "mat hang co gia tri ton kho lon nhat :" << endl;
        b = sort(a, m);
        b.print();
    };
    void MaxMayMac()
    {
        MayMac b;
        MayMac a[50];
        int i = 0;
        ifstream file("MayMac.txt", ios::in);
        while (file >> a[i])
        {
            i++;
        }
        int m = i;
        file.close();
        cout << "mat hang co gia tri ton kho lon nhat :" << endl;
        b = sort(a, m);
        b.print();
    };
};
int check;
//=====================================================================================================================================================

void menu()
{
    QuanLy a;
    switch (check)
    {
    case 1:
        a.ThemHangHoa();
        break;
    case 2:
        a.TimKiem();
        break;
    case 3:
        a.CapNhatThongTin();
        break;
    case 4:
        a.XoaHangHoa();
        break;
    case 5:
        a.MaxThucPham();
        break;
    case 6:
        a.MacDienMay();
        break;
    case 7:
        a.MaxMayMac();
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
        cout << " 1  them hang hoa moi " << endl;
        cout << " 2  tim kiem hang hoa " << endl;
        cout << " 3  cap nhat thong tin hang hoa " << endl;
        cout << " 4  xoa hang hoa  " << endl;
        cout << " 5 gia tri ton kho lon nhat cua thuc pham " << endl;
        cout << " 6 gia tri ton kho lon nhat cua dien may" << endl;
        cout << " 7 gia tri ton kho lon nhat cua may mac " << endl;
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
