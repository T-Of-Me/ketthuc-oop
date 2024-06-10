#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
class SinhVien
{
protected:
    string ten;
    int tuoi;
    string lop;
    string khoa;

public:
    SinhVien();
    SinhVien(string, int, string, string);
    void Input();
    void Output();
    string ReturnTen()
    {
        return ten;
    }
};
SinhVien::SinhVien()
{
    ten = "";
    tuoi = 0;
    lop = "";
    khoa = "";
}
SinhVien::SinhVien(string t, int t_, string l, string k)
{
    ten = t;
    tuoi = t_;
    lop = l;
    khoa = k;
}
void SinhVien::Input()
{
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, ten);

    cout << "Nhap tuoi: ";
    cin >> tuoi;

    cout << "Nhap lop: ";
    cin.ignore();
    getline(cin, lop);

    cout << "Nhap khoa: ";
    cin.ignore();
    getline(cin, khoa);
}
void SinhVien::Output()
{
    cout << "Ten: " << ten << "\nTuoi: " << tuoi << "\nLop: " << lop << "\nKhoa: " << khoa << endl;
}
//=================================================================================================
class TheMuon : public SinhVien
{
    //     friend ostream &operator<<(ostream&,TheMuon &);
    friend istream &operator>>(istream &, TheMuon &);

protected:
    string ma_phieu;
    string ngay_muon;
    string han_tra;
    string so_hieu_sach;

public:
    friend class PhieuMuonSach;
    TheMuon();
    TheMuon(string, int, string, string, string, string, string, string);
    void Input();
    void Output();
    string get_ma();
};
// ostream &operator<<(ostream & out, TheMuon &tm) {
//     out<<tm.ten<<"  "<<tm.tuoi<<"  "<<tm.lop<<"  "<<tm.khoa<<"  "<<tm.ma_phieu<<"  "<<tm.ngay_muon<<"  "<<tm.han_tra<<"  "<<tm.so_hieu_sach<<endl;
//     return out;
// }
istream &operator>>(istream &in, TheMuon &tm)
{
    in >> tm.ten >> tm.tuoi >> tm.lop >> tm.khoa >> tm.ma_phieu >> tm.ngay_muon >> tm.han_tra >> tm.so_hieu_sach;
    return in;
}
TheMuon::TheMuon()
{
    ten = "";
    tuoi = 0;
    lop = "";
    khoa = "";
    ma_phieu = "";
    ngay_muon = "";
    han_tra = "";
    so_hieu_sach = "";
}
TheMuon::TheMuon(string t, int t_, string l, string k, string m, string nm, string ht, string shs) : SinhVien(t, t_, l, k)
{
    ma_phieu = m;
    ngay_muon = nm;
    han_tra = ht;
    so_hieu_sach = shs;
}
void TheMuon::Input()
{
    SinhVien::Input();
    cout << "Nhap ma phieu: ";
    getline(cin, ma_phieu);
    cout << "Nhap ngay muon: ";
    getline(cin, ngay_muon);
    cout << "Nhap han tra: ";
    getline(cin, han_tra);
    cout << "Nhap so hieu sach: ";
    getline(cin, so_hieu_sach);
}
void TheMuon::Output()
{
    SinhVien::Output();
    cout << "Ma phieu: " << ma_phieu << "\nNgay muon: " << ngay_muon << "\nHan tra: " << han_tra << "\nSo hieu sach: " << so_hieu_sach << "\n";
}
string TheMuon::get_ma()
{
    return ma_phieu;
}
//=================================================================================================
class PhieuMuonSach
{
private:
    TheMuon N[1000];

public:
    void Them(int);
    void Display(int);
    void ThongKe(int n)
    {
        string s;
        int k = 0;
        cout << "nhap ten de kiem tra " << endl;
        getline(cin, s);
        for (int i = 0; i < n; i++)
        {
            if (s == N[i].ReturnTen())
            {
                ++k;
            }
        }
        cout << "so phieu nguoi thue :  " << k << endl;
    }
    void Xoa(int n)
    {
        string s;
        cout << "nhap ten de xoa " << endl;
        getline(cin, s);
        TheMuon M[100];
        int i = 0;
        int j = 0;
        while (n != i - 1)
        {
            if (s == N[j].ReturnTen())
            {
                j--;
            }
            M[i] = N[j];
            i++;
            j++;
        }
        int m = j;
        for (int i = 0; i < m; i++)
        {
            M[i].Output();
        }
        for (int i = 0; i < m; i++)
        {
            N[i] = M[i];
        }
    }
    void Sua(int n)
    {
        string s;
        cout << "nhap ten de sua " << endl;
        getline(cin, s);
        TheMuon M[100];
        int i = 0;
        int j = 0;

        string ten;
        int tuoi;
        string lop;
        string khoa;
        string ma_phieu;
        string ngay_muon;
        string han_tra;
        string so_hieu_sach;
        while (n != i - 1)
        {
            if (s == N[j].ReturnTen())
            {
                tuoi = N[j].tuoi;
                lop = N[j].lop;
                khoa = N[j].khoa;
                ma_phieu = N[j].ma_phieu;
                ngay_muon = N[j].ngay_muon;
                han_tra = N[j].han_tra;
                so_hieu_sach = N[j].so_hieu_sach;

                j--;
            }
            M[i] = N[j];
            i++;
            j++;
        }
        int m = j;
        for (int i = 0; i < m; i++)
        {
            N[i] = M[i];
        }

        TheMuon x(s, tuoi, lop, khoa, ma_phieu, ngay_muon, han_tra, so_hieu_sach);
        N[i] = x;
    }
};
void PhieuMuonSach::Them(int n)
{
    for (int i = 0; i < n; i++)
    {
        N[i].Input();
        cout << endl;
    }
}
void PhieuMuonSach::Display(int n)
{
    for (int i = 0; i < n; i++)
    {
        N[i].Output();

        cout << endl;
    }
}

//=================================================================================================
int answer;
void menu(int n)
{

    PhieuMuonSach a;
    cout << "nhap so luong ";
    cin >> n;
    switch (answer)
    {
    case 1:
        a.Them(n);
        break;
    case 2:
        a.Sua(n);
        break;
    case 3:
        a.Display(n);
        break;
    case 4:
        a.Xoa(n);
        break;
    case 5:

        break;
    case 6:

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
int n;
// ===================================================================================================================
int main()
{
    bool keepLooping = true;
    while (keepLooping)
    {

        cout << "------CHAO MUNG DEN VOI KHACH SAN------  " << endl;
        cout << " (1)  them  " << endl;
        cout << " (2)   sua " << endl;
        cout << " (3)  dis " << endl;
        cout << " (4)   xoa" << endl;
        cout << " (5)   " << endl;
        cout << " (6)    " << endl;
        cout << " (7) " << endl;
        cout << " (8)  " << endl;
        cout << " (9)    " << endl;
        cin >> answer;
        menu(n);
        if (answer >= 1 && answer <= 10)
            keepLooping = true;
        else
            keepLooping = false;
    }
    return answer;
}
