#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
class ChuyenXe
{
protected:
    int MaChuyenXe;
    string TenTaiXe;
    int SoXe;

public:
    ChuyenXe(){};
    ~ChuyenXe(){};
    int ReturnMaChuyenXe()
    {
        return MaChuyenXe;
    }
    string ReturnTenTaiXe()
    {
        return TenTaiXe;
    }
    int ReturnSoXe()
    {
        return SoXe;
    }
};

//==================================================================

class ChuyenXeNoiTinh : public ChuyenXe
{
private:
    int SoTuyen;
    int SoKm;
    int DoanhThu;

public:
    ChuyenXeNoiTinh(){};
    ~ChuyenXeNoiTinh(){};
    ChuyenXeNoiTinh(string tentaixe, int ma, int Soxe, int Sotuyen, int Sokm)
    {

        this->TenTaiXe = tentaixe;
        this->MaChuyenXe = ma;
        this->SoXe = Soxe;
        this->SoTuyen = Sotuyen;
        this->SoKm = Sokm;
    };
    friend ostream &operator<<(ostream &out, ChuyenXeNoiTinh x)
    {
        out << x.MaChuyenXe << endl;
        out << x.TenTaiXe << endl;
        out << x.SoXe << endl;
        out << x.SoTuyen << endl;
        out << x.SoKm << endl;
        return out;
    }
    friend istream &operator>>(istream &in, ChuyenXeNoiTinh &x)
    {
        cout << " ma chuyen xe :";
        in >> x.MaChuyenXe;
        cout << " ten tai xe :";
        in.ignore();
        getline(in, x.TenTaiXe);
        cout << " So xe :";
        in >> x.SoXe;
        cout << " So tuyen :";
        in >> x.SoTuyen;
        cout << " So km :";
        in >> x.SoKm;
        return in;
    }
    int TongDoanhThu()
    {
        // so tuyen nhan so km nhan 100
        return (SoTuyen * SoKm * 100);
    }
};
//===============================================================================
class ChuyenXeNoiTinhDoc : public ChuyenXe
{
private:
    int SoTuyen;
    int SoKm;
    int DoanhThu;

public:
    ChuyenXeNoiTinhDoc(){};
    ~ChuyenXeNoiTinhDoc(){};
    int ReturnSoTuyen() { return SoTuyen; }
    int ReturnSoKm() { return SoKm; }
    ChuyenXeNoiTinhDoc(string tentaixe, int ma, int Soxe, int Sotuyen, int Sokm)
    {

        this->TenTaiXe = tentaixe;
        this->MaChuyenXe = ma;
        this->SoXe = Soxe;
        this->SoTuyen = Sotuyen;
        this->SoKm = Sokm;
    };
    friend ostream &operator<<(ostream &out, ChuyenXeNoiTinhDoc x)
    {
        out << x.MaChuyenXe << endl;
        out << x.TenTaiXe << endl;
        out << x.SoXe << endl;
        out << x.SoTuyen << endl;
        out << x.SoKm << endl;
        return out;
    }
    friend istream &operator>>(istream &in, ChuyenXeNoiTinhDoc &x)
    {

        in >> x.MaChuyenXe;
        in.ignore();
        getline(in, x.TenTaiXe);
        in >> x.SoXe;
        in >> x.SoTuyen;
        in >> x.SoKm;
        return in;
    }
    void print()
    {
        cout << "Ma CHuyen xe :" << MaChuyenXe << endl;
        cout << "Ten tai xe :" << TenTaiXe << endl;
        cout << "So xe :" << SoXe << endl;
        cout << "So tuyen :" << SoTuyen << endl;
        cout << "So KM :" << SoKm << endl;
    }
};
//===============================================================================

class ChuyenXeNgoaiTinh : public ChuyenXe
{
private:
    string NoiDen;
    int SoNgayDiduoc;
    int DoanhThu;

public:
    ChuyenXeNgoaiTinh(){};
    ~ChuyenXeNgoaiTinh(){};
    ChuyenXeNgoaiTinh(string tentaixe, int ma, int Soxe, string NoiDen, int songaydiduoc)
    {

        this->TenTaiXe = tentaixe;
        this->MaChuyenXe = ma;
        this->SoXe = Soxe;
        this->NoiDen = NoiDen;
        this->SoNgayDiduoc = songaydiduoc;
    }
    friend ostream &operator<<(ostream &out, ChuyenXeNgoaiTinh x)
    {
        out << x.MaChuyenXe << endl;
        out << x.TenTaiXe << endl;
        out << x.SoXe << endl;
        out << x.NoiDen << endl;
        out << x.SoNgayDiduoc << endl;
        return out;
    }
    friend istream &operator>>(istream &in, ChuyenXeNgoaiTinh &x)
    {
        cout << " ma chuyen xe :";
        in >> x.MaChuyenXe;
        cout << " ten tai xe :";
        in.ignore();
        getline(in, x.TenTaiXe);
        cout << " So xe :";
        in >> x.SoXe;
        cout << " Noi den :";
        in.ignore();
        getline(in, x.NoiDen);
        cout << "so ngay di duoc:";
        in >> x.SoNgayDiduoc;
        return in;
    }
    int TongDoanhThu()
    {
        return SoNgayDiduoc * 200;
    }
};
//=========================================================
class ChuyenXeNgoaiTinhDoc : public ChuyenXe
{
private:
    string NoiDen;
    int SoNgayDiduoc;
    int DoanhThu;

public:
    ChuyenXeNgoaiTinhDoc(string tentaixe, int ma, int Soxe, string NoiDen, int songaydiduoc)
    {

        this->TenTaiXe = tentaixe;
        this->MaChuyenXe = ma;
        this->SoXe = Soxe;
        this->NoiDen = NoiDen;
        this->SoNgayDiduoc = songaydiduoc;
    }
    string ReturnNoiDen()
    {
        return NoiDen;
    }
    int ReturnSoNgayDiDuoc()
    {
        return SoNgayDiduoc;
    }
    int ReturnDoanhThu()
    {
        return DoanhThu;
    }
    ChuyenXeNgoaiTinhDoc(){};
    ~ChuyenXeNgoaiTinhDoc(){};

    friend ostream &operator<<(ostream &out, ChuyenXeNgoaiTinhDoc x)
    {
        out << x.MaChuyenXe << endl;
        out << x.TenTaiXe << endl;
        out << x.SoXe << endl;
        out << x.NoiDen << endl;
        out << x.SoNgayDiduoc << endl;
        return out;
    }
    friend istream &operator>>(istream &in, ChuyenXeNgoaiTinhDoc &x)
    {
        in >> x.MaChuyenXe;
        in.ignore();
        getline(in, x.TenTaiXe);
        in >> x.SoXe;
        in.ignore();
        getline(in, x.NoiDen);
        in >> x.SoNgayDiduoc;
        return in;
    }
    void print()
    {
        cout << "Ma CHuyen xe :" << MaChuyenXe << endl;
        cout << "Ten tai xe :" << TenTaiXe << endl;
        cout << "So xe :" << SoXe << endl;
        cout << "So tuyen :" << NoiDen << endl;
        cout << "So KM :" << SoNgayDiduoc << endl;
    }
};
//==========================================================================
void CheckMaXeTonTai()
{

    int ma;
    string s;
    int check;
    do
    {
        cout << "nhap ma chuyen xe de check :";
        cin >> ma;
        ifstream File1("ChuyenXe.txt", ios::in);
        while (File1 >> s)
        {
            if (s == "NGOAITINH")
            {
                ChuyenXeNgoaiTinhDoc a;
                File1 >> a;
                if (a.ReturnMaChuyenXe() == ma)
                {
                    cout << "ma xe ton tai " << endl;
                    check = 0;
                }
                else
                {
                    check = 1;
                }
            }
            else if (s == "NOITINH")
            {
                ChuyenXeNoiTinhDoc b;
                File1 >> b;
                if (b.ReturnMaChuyenXe() == ma)
                {
                    cout << "ma xe ton tai " << endl;
                    check = 0;
                }
                else
                {
                    check = 1;
                }
            }
        }
        File1.close();
    } while (check == 0);
}
//========================================================
void NoiTinh()
{
    ofstream File1;
    ofstream File2;
    File1.open("ChuyenXe.txt", ios::app);
    ChuyenXeNoiTinh x;
    CheckMaXeTonTai();
    cin >> x;
    File1 << "NOITINH" << endl;
    File1 << x;
    File1.close();
}
int check;
//=========================================================
void NgoaiTinh()
{
    ofstream File1;
    ofstream File2;
    File1.open("ChuyenXe.txt", ios::app);
    File2.open("DoanhThu.txt", ios::app);
    CheckMaXeTonTai();
    ChuyenXeNgoaiTinh x;
    cin >> x;
    File1 << "NGOAITINH" << endl;
    File1 << x;
    File2 << x.TongDoanhThu() << endl;
    File1.close();
    File2.close();
}
//==========================================================
void DoanhThu()
{
    ifstream File;
    File.open("DoanhThu.txt");
    int x;
    int tong = 0;
    while (File >> x)
    {
        tong += x;
    }
    cout << "doanh thu chuyen xe ngoai tinh : " << tong << "$" << endl;
}
//==========================================================
void TImKiemCHuyenXe(int ma)
{
    ifstream File;
    File.open("ChuyenXe.txt");
    string x;
    while (File >> x)
    {
        if (x == "NOITINH")
        {
            ChuyenXeNoiTinhDoc a;
            File >> a;
            if (a.ReturnMaChuyenXe() == ma)
            {
                a.print();
            }
        }
        else if (x == "NGOAITINH")
        {
            ChuyenXeNgoaiTinhDoc b;
            File >> b;
            if (b.ReturnMaChuyenXe() == ma)
            {
                b.print();
            }
        }
        else
        {
            cout << " khong tim thay ma " << endl;
        }
    }
}
//=================================================================
void DocDanhSachChuyenXe()
{
    ifstream File1;
    File1.open("ChuyenXe.txt", ios::in);
    string s;
    ChuyenXeNgoaiTinhDoc a;
    ChuyenXeNoiTinhDoc b;
    while (File1 >> s)
    {
        if (s == "NOITINH")
        {
            File1 >> b;
            cout << "Chuyen xe noi tinh" << endl;
            b.print();
            cout << " |||||||||||||" << endl;
        }
        else
        {
            File1 >> a;
            cout << "Chuyen xe ngoai tinh" << endl;
            a.print();
            cout << " |||||||||||||" << endl;
        }
    }
}
//===============================================================================================================
void ChinhSuaThongTin()
{
    cout << "ban muon chinh sua thong tin nao " << endl;
    cout << " 1  sua thong tin chuyen xe noi tuyen " << endl;
    cout << " 2  sua thong tin chuyen xe ngoai tuyen " << endl;
    int check = 0;
    cin >> check;
    ChuyenXeNgoaiTinhDoc a[100];
    ChuyenXeNoiTinhDoc b[100];
    bool pass = false;
    if (check == 1)
    {

        cout << " nhap ma chuyen xe can sua :" << endl;
        int ma;
        cin >> ma;
        string x;
        int i = 0, j = 0;
        ifstream File;
        File.open("ChuyenXe.txt", ios::in);
        int MA;
        int SoXe;
        int SoTuyen;
        int SoKm;
        while (File >> x)
        {
            if (x == "NOITINH")
            {
                File >> b[i];
                if (b[i].ReturnMaChuyenXe() == ma)
                {
                    string tentaixe = b[i].ReturnTenTaiXe();
                    MA = b[i].ReturnMaChuyenXe();
                    SoXe = b[i].ReturnSoXe();
                    SoTuyen = b[i].ReturnSoTuyen();
                    SoKm = b[i].ReturnSoKm();
                    i--;
                    pass = true;
                }
                i++;
            }
            else if (x == "NGOAITINH")
            {
                File >> a[j];
                j++;
            }
        }
        File.close();

        int m = i;
        int n = j;
        ofstream File1;
        File1.open("ChuyenXe.txt", ios::trunc);
        for (int i = 0; i < m; i++)
        {
            File1 << "NOITINH" << endl;
            File1 << b[i];
        }
        for (int i = 0; i < n; i++)
        {
            File1 << "NGOAITINH" << endl;
            File1 << a[i];
        }
        File1.close();
        // xoa thanh cong
        if (pass != true)
        {
            cout << " ma xe khong ton tai " << endl;
        }
        else
        {
            cout << " sua thong tin chuyen xe ma " << ma << endl;
            // xoa duoc cai can sua
            ofstream File2;
            File2.open("ChuyenXe.txt", ios::app);
            cout << " nhap ten can sua :";
            string y;
            cin.ignore();
            getline(cin, y);
            ChuyenXeNoiTinh x(y, MA, SoXe, SoTuyen, SoKm);
            File2 << "NOITINH" << endl;
            File2 << x;
            cout << " SUA THANH TEN THANH CONG " << endl;
        }
    }
    else
    {

        cout << " nhap ma chuyen xe can sua :" << endl;
        int ma;
        cin >> ma;
        string x;
        int i = 0, j = 0;
        ifstream File;
        File.open("ChuyenXe.txt", ios::in);
        int MA;
        int SoXe;
        char NoiDen[100];
        int SoNgayDiDuoc;
        while (File >> x)
        {
            if (x == "NOITINH")
            {
                File >> b[i];
                i++;
            }
            else if (x == "NGOAITINH")
            {
                File >> a[j];
                if (a[j].ReturnMaChuyenXe() == ma)
                {
                    string tentaixe = a[j].ReturnTenTaiXe();
                    MA = a[j].ReturnMaChuyenXe();
                    SoXe = a[j].ReturnSoXe();
                    const char *t = a[j].ReturnNoiDen().c_str();
                    strcpy(NoiDen, t);
                    SoNgayDiDuoc = a[j].ReturnSoNgayDiDuoc();
                    j--;
                    pass = true;
                }
                j++;
            }
        }
        File.close();

        int m = i;
        int n = j;
        ofstream File1;
        File1.open("ChuyenXe.txt", ios::trunc);
        for (int i = 0; i < m; i++)
        {
            File1 << "NOITINH" << endl;
            File1 << b[i];
        }
        for (int i = 0; i < n; i++)
        {
            File1 << "NGOAITINH" << endl;
            File1 << a[i];
        }
        File1.close();
        // xoa thanh cong
        if (pass != true)
        {
            cout << " ma xe khong ton tai " << endl;
        }
        else
        {
            cout << " sua thong tin chuyen xe ma " << ma << endl;
            // xoa duoc cai can sua
            ofstream File2;
            File2.open("ChuyenXe.txt", ios::app);
            cout << " nhap ten can sua :";
            string y;
            cin.ignore();
            getline(cin, y);
            ChuyenXeNgoaiTinh x(y, MA, SoXe, NoiDen, SoNgayDiDuoc);
            File2 << "NGOAITINH" << endl;
            File2 << x;
            cout << " SUA TEN THANH CONG " << endl;
        }
    }
}
//==========================================================

void menu()
{

    switch (check)
    {
    case 1:
        cout << "-- them thong tin chuyen xe noi tinh-- " << endl;
        NoiTinh();
        break;
    case 2:
        cout << "--nhap thong tin chuyen xe ngoai tinh--" << endl;
        NgoaiTinh();
        break;
    case 3:
        DoanhThu();
        break;
    case 4:
        cout << "nhap ma tim kiem chuyen xe :";
        int ma;
        cin >> ma;
        TImKiemCHuyenXe(ma);
        break;
    case 5:
        ChinhSuaThongTin();
        break;
    case 6:
        DocDanhSachChuyenXe();
        break;
    default:
        cout << "(=^_^=) THANH YOU DA SU DUNG DICH VU (=^_^=)" << endl;
        break;
    }
}
//===========================================================
//===========================================================

int main()
{
    bool keeping = true;
    while (keeping)
    {
        cout << "*** APP QUAN LY XE CHUYEN XE ***" << endl;
        cout << " 1 de them thong tin chuyen xe noi tinh" << endl;
        cout << " 2 de them thong tin chuyen xe ngoai tinh " << endl;
        cout << " 3 tong doanh thu " << endl;
        cout << " 4 tim kiem chuyen xe " << endl;
        cout << " 5 chinh sua thong tin ten tai xe " << endl;
        cout << " 6 doc danh sach chuyen xe " << endl;
        cout << " (^;_;^)  NHAP LUA CHON !!!!! (^;_;^) " << endl;
        cin >> check;
        if (check <= 6 && check >= 1)
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
