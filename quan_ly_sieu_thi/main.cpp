

#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>

class HangHoa
{
protected:
    int MaHang;
    string TenHang;
    int SoLuongTon;
    int DonGia;

public:
    HangHoa(){};
    ~HangHoa(){};
    virtual void print()
    {
        cout << "Ma hang :" << MaHang << endl;
        cout << "Ten hang :" << TenHang << endl;
        cout << "So luong ton kho :" << SoLuongTon << endl;
        cout << "Don gia :" << DonGia << endl;
    }
    int ReturnMa()
    {
        return MaHang;
    }
    string ReturnTenHang()
    {
        return TenHang;
    }
    int ReturnSoLuong()
    {
        return SoLuongTon;
    }
    int ReturnDonGia()
    {
        return DonGia;
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
    ThucPham(int ma, int soluong, int dongia, int ngays, int thangs, int nams, int ngayh, int thangh, int namh, string tenhang, string nhacungcap)
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
    ThucPham(){};
    ~ThucPham(){};

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
class ThucPhamDoc : public HangHoa
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
    int ReturnNgaySanXuat()
    {
        return NgayHetHan;
    }
    int ReturnThangSanXuat()
    {
        return ThangSanXuat;
    }
    int ReturnNamSanXuat()
    {
        return NamSanXuat;
    }
    int ReturnNgayHetHan()
    {
        return NgayHetHan;
    }
    int ReturnThangHetHan()
    {
        return ThangHetHan;
    }
    int ReturnNamHetHan()
    {
        return NamHetHan;
    }
    string ReturnNhaCungCap()
    {
        return NhaCungCap;
    }
    ThucPhamDoc(){};
    ~ThucPhamDoc(){};
    friend ostream &operator<<(ostream &out, ThucPhamDoc x)
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
    friend istream &operator>>(istream &in, ThucPhamDoc &x)
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

class DienMay : public HangHoa
{
private:
    int ThoiGianBaoHanh;
    int CongXuat;
    string ChungLoai;

public:
    DienMay(){};
    ~DienMay(){};
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
//====================================================================================================================================================4

class DienMayDoc : public HangHoa
{
private:
    int ThoiGianBaoHanh;
    int CongXuat;
    string ChungLoai;

public:
    string ReturnChungLoai()
    {
        return ChungLoai;
    }
    int ReturnThoiGianBaoHanh()
    {
        return ThoiGianBaoHanh;
    }
    int ReturnCongXuat()
    {
        return CongXuat;
    }
    DienMayDoc(int mahang, int soluong, int dongia, int thoigianbaohanh, int congxuat, string tenhang, string chungloai)
    {
        this->MaHang = mahang;
        this->SoLuongTon = soluong;
        this->DonGia = dongia;
        this->ThoiGianBaoHanh = thoigianbaohanh;
        this->CongXuat = congxuat;
        this->TenHang = tenhang;
        this->ChungLoai = chungloai;
    };
    ~DienMayDoc(){};
    DienMayDoc(){};
    friend ostream &operator<<(ostream &out, DienMayDoc x)
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
    friend istream &operator>>(istream &in, DienMayDoc &x)
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

class MayMac : public HangHoa
{
private:
    string TenNhaSanXuat;
    int NgayNhapKho;
    int ThangNhapKho;
    int NamNhapKho;

public:
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
class MayMacDoc : public HangHoa
{
private:
    string TenNhaSanXuat;
    int NgayNhapKho;
    int ThangNhapKho;
    int NamNhapKho;

public:
    void print()
    {
        HangHoa::print();
        cout << "ten nha san xuat :" << TenNhaSanXuat << endl;
        cout << "ngay nhap :" << NgayNhapKho << "/" << ThangNhapKho << "/" << NamNhapKho << endl;
    }
    int ReturnNgayNgapKho()
    {
        return NgayNhapKho;
    }
    int ReturnThangNgapKho()
    {
        return ThangNhapKho;
    }
    int ReturnNamNgapKho()
    {
        return NamNhapKho;
    }
    string ReturnTenNhaSanXuat()
    {
        return TenNhaSanXuat;
    }
    MayMacDoc(int mahang, int soluong, int dongia, int ngay, int thang, int nam, string tenhang, string tennhasanxuat)
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
    MayMacDoc(){};
    ~MayMacDoc(){};
    friend ostream &operator<<(ostream &out, MayMacDoc x)
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
    friend istream &operator>>(istream &in, MayMacDoc &x)
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
        ThucPhamDoc a;
        ifstream File("ThucPham.txt", ios::in);
        while (File >> a)
        {
            if (a.ReturnMa() == z && a.ReturnTenHang() == ten)
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
        DienMayDoc a;
        ifstream File("DienMay.txt", ios::in);
        while (File >> a)
        {
            if (a.ReturnMa() == z && a.ReturnTenHang() == ten)
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
        MayMacDoc a;
        ifstream File("MayMac.txt", ios::in);
        while (File >> a)
        {
            if (a.ReturnMa() == z && a.ReturnTenHang() == ten)
            {
                cout << "Ma hang hoa ton tai " << endl;
                return 1;
            }
        }
        cout << "ma khong ton tai " << endl;
        return 0;
    }
}
//=====================================================================================================================================================
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
        ThucPham a;
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
        ThucPhamDoc a;
        ifstream File("ThucPham.txt", ios::in);
        while (File >> a)
        {
            if (a.ReturnMa() == ma && a.ReturnTenHang() == ten)
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
        DienMayDoc a;
        ifstream File("DienMay.txt", ios::in);
        while (File >> a)
        {
            if (a.ReturnMa() == ma && a.ReturnTenHang() == ten)
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
        MayMacDoc a;
        ifstream File("MayMac.txt", ios::in);
        while (File >> a)
        {
            if (a.ReturnMa() == ma && a.ReturnTenHang() == ten)
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
        DienMayDoc a;
        ifstream File("DienMay.txt", ios::in);
        while (File >> a)
        {
            if (a.ReturnMa() == ma && a.ReturnTenHang() == t)
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
    DienMayDoc a;
    ifstream File1("DienMay.txt", ios::in);
    ofstream File2("DienMayTemp.txt", ios::trunc);
    while (File1 >> a)
    {
        if (a.ReturnMa() == ma && a.ReturnTenHang() == t)
        {
            cout << " Loading........" << endl;
            soluong = a.ReturnSoLuong();
            dongia = a.ReturnDonGia();
            thoigianbaohanh = a.ReturnThoiGianBaoHanh();
            congxuat = a.ReturnCongXuat();
            const char *t = a.ReturnTenHang().c_str();
            strcpy(tenhang, t);
            const char *k = a.ReturnChungLoai().c_str();
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
        DienMayDoc x(ma, soluong, dongia, THOIGIANBAOHANH, congxuat, tenhang, chungloai);
        ofstream File5("DienMay.txt", ios::app);
        File5 << x;
        File5.close();
    }
    else if (check == 2)
    {
        int CONGXUAT;
        cout << "nhap cong xuat thay the :";
        cin >> CONGXUAT;
        DienMayDoc x(ma, soluong, dongia, thoigianbaohanh, CONGXUAT, tenhang, chungloai);
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
        DienMayDoc x(ma, soluong, dongia, thoigianbaohanh, congxuat, tenhang, CHUNGLOAI);
        ofstream File5("DienMay.txt", ios::app);
        File5 << x;
        File5.close();
    }
    else if (check == 4)
    {
        cout << "nhap luong ton thay the:";
        int LUONGTON;
        cin >> LUONGTON;
        DienMayDoc x(ma, LUONGTON, dongia, thoigianbaohanh, congxuat, tenhang, chungloai);
        ofstream File5("DienMay.txt", ios::app);
        File5 << x;
        File5.close();
    }
    else if (check == 5)
    {
        cout << "nhap don gia thay the :";
        int DONGIA;
        cin >> DONGIA;
        DienMayDoc x(ma, soluong, DONGIA, thoigianbaohanh, congxuat, tenhang, chungloai);
        ofstream File5("DienMay.txt", ios::app);
        File5 << x;
        File5.close();
    }
    else
    {
        cout << "sai ki tu !!!!!!!!!!! " << endl;
    }
}
//=====================================================================================================================================================
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
        MayMacDoc a;
        ifstream File("MayMac.txt", ios::in);
        while (File >> a)
        {
            if (a.ReturnMa() == ma && a.ReturnTenHang() == t)
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
    MayMacDoc a;
    ifstream File1("MayMac.txt", ios::in);
    ofstream File2("MayMacTemp.txt", ios::trunc);
    while (File1 >> a)
    {
        if (a.ReturnMa() == ma && a.ReturnTenHang() == t)
        {
            cout << " Loading........" << endl;
            soluong = a.ReturnSoLuong();
            dongia = a.ReturnDonGia();
            ngay = a.ReturnNgayNgapKho();
            thang = a.ReturnThangNgapKho();
            nam = a.ReturnNamNgapKho();
            const char *t = a.ReturnTenHang().c_str();
            strcpy(tenhang, t);
            const char *k = a.ReturnTenNhaSanXuat().c_str();
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
        MayMacDoc x(ma, soluong, dongia, NGAY, THANG, NAM, tenhang, tennhasanxuat);
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
        MayMacDoc x(ma, soluong, dongia, ngay, thang, nam, tenhang, NHASANXUAT);
        ofstream File5("MayMac.txt", ios::app);
        File5 << x;
        File5.close();
    }
    else if (check == 3)
    {

        cout << "luong ton :";
        int LUONGTON;
        cin >> LUONGTON;
        MayMacDoc x(ma, LUONGTON, dongia, ngay, thang, nam, tenhang, tennhasanxuat);
        ofstream File5("MayMac.txt", ios::app);
        File5 << x;
        File5.close();
    }
    else if (check == 2)
    {
        cout << "don gia :";
        int DONGIA;
        cin >> DONGIA;
        MayMacDoc x(ma, soluong, DONGIA, ngay, thang, nam, tenhang, tennhasanxuat);
        ofstream File5("MayMac.txt", ios::app);
        File5 << x;
        File5.close();
    }
}
//=====================================================================================================================================================

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
            ThucPhamDoc a;
            ifstream File("ThucPham.txt", ios::in);
            while (File >> a)
            {
                if (a.ReturnMa() == ma && a.ReturnTenHang() == t)
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

        ThucPhamDoc a;
        ifstream File1("ThucPham.txt", ios::in);
        ofstream File2("ThucPhamTemp.txt", ios::trunc);
        while (File1 >> a)
        {
            if (a.ReturnMa() == ma && a.ReturnTenHang() == t)
            {
                cout << " Loading........" << endl;
                soluong = a.ReturnSoLuong();
                dongia = a.ReturnDonGia();
                ngayh = a.ReturnNgayHetHan();
                thangh = a.ReturnThangHetHan();
                namh = a.ReturnNamHetHan();
                ngays = a.ReturnNgaySanXuat();
                thangs = a.ReturnThangSanXuat();
                nams = a.ReturnNamSanXuat();
                const char *t = a.ReturnTenHang().c_str();
                strcpy(tenhang, t);
                const char *k = a.ReturnNhaCungCap().c_str();
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
            ThucPham x(ma, soluong, dongia, NGAY, THANG, NAM, ngayh, thangh, namh, tenhang, nhacungcap);
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
            ThucPham x(ma, soluong, dongia, ngays, thangs, nams, NGAY, THANG, NAM, tenhang, nhacungcap);
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
            ThucPham x(ma, soluong, dongia, ngays, thangs, nams, ngayh, thangh, namh, tenhang, NHACUNGCAP);
            ofstream File5("ThucPham.txt", ios::app);
            File5 << x;
            File5.close();
        }
        else if (check == 4)
        {
            cout << "nhap luong ton thay the:";
            int LUONGTON;
            cin >> LUONGTON;
            ThucPham x(ma, LUONGTON, dongia, ngays, thangs, nams, ngayh, thangh, namh, tenhang, nhacungcap);
            ofstream File5("ThucPham.txt", ios::app);
            File5 << x;
            File5.close();
        }
        else if (check == 5)
        {
            cout << "nhap don gia thay the :";
            int DONGIA;
            cin >> DONGIA;
            ThucPham x(ma, soluong, DONGIA, ngays, thangs, nams, ngayh, thangh, namh, tenhang, nhacungcap);
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
            ThucPhamDoc a;
            ifstream File("ThucPham.txt", ios::in);
            while (File >> a)
            {
                if (a.ReturnMa() == ma)
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

        ThucPhamDoc a;
        ifstream File1("ThucPham.txt", ios::in);
        ofstream File2("ThucPhamTemp.txt", ios::trunc);
        while (File1 >> a)
        {
            if (a.ReturnMa() == ma)
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
        cout << "da xoa ma ........" << endl;
    }
    else if (chose == 2)
    {
        int ma;
        bool checking = false;
        do
        {
            cout << "nhap ma de tim san pham :";
            cin >> ma;
            MayMacDoc a;
            ifstream File("DienMay.txt", ios::in);
            while (File >> a)
            {
                if (a.ReturnMa() == ma)
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
        DienMayDoc a;
        ifstream File1("DienMay.txt", ios::in);
        ofstream File2("DienMayTemp.txt", ios::trunc);
        while (File1 >> a)
        {
            if (a.ReturnMa() == ma)
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
            MayMacDoc a;
            ifstream File("MayMac.txt", ios::in);
            while (File >> a)
            {
                if (a.ReturnMa() == ma)
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
        MayMacDoc a;
        ifstream File1("MayMac.txt", ios::in);
        ofstream File2("MayMacTemp.txt", ios::trunc);
        while (File1 >> a)
        {
            if (a.ReturnMa() == ma)
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

//=====================================================================================================================================================

//=====================================================================================================================================================

int check;
//=====================================================================================================================================================

void menu()
{
    switch (check)
    {
    case 1:
        ThemHangHoa();
        break;
    case 2:
        TimKiem();
        break;
    case 3:
        CapNhatThongTin();
        break;
    case 4:
        XoaHangHoa();
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
