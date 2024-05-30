#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
struct Date
{
    int ngay;
    int thang;
    int nam;
};
class Giaodich
{
protected:
    int ma;
    Date date;
    int DonGia;
    int DienTich;

public:
    Giaodich(){};
    ~Giaodich(){};
    int ReturnMa()
    {
        return ma;
    }
    int ReturnNgay()
    {
        return date.ngay;
    }
    int ReturnThang()
    {
        return date.thang;
    }
    int ReturnNam()
    {
        return date.nam;
    }
};
//=======================================================================================================================================================

class GiaoDichDat : public Giaodich
{
private:
    char LoaiDat;

public:
    char ReturnLoaiDat() { return LoaiDat; };
    int ReturnDonGia() { return DonGia; }
    GiaoDichDat(){};
    ~GiaoDichDat(){};
    friend ostream &operator<<(ostream &out, GiaoDichDat x)
    {
        out << x.ma << endl;
        out << x.date.ngay << endl;
        out << x.date.thang << endl;
        cout << x.date.nam << endl;
        out << x.DonGia << endl;
        out << x.LoaiDat << endl;
        out << x.DienTich << endl;
        return out;
    }
    friend istream &operator>>(istream &in, GiaoDichDat &x)
    {

        cout << " ma   :";
        in >> x.ma;
        cout << " Date ->:";
        cout << " nhap ngay :";
        do
        {
            in >> x.date.ngay;
            if (x.date.ngay < 0 || x.date.ngay > 31)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.date.ngay < 0 || x.date.ngay > 31);
        cout << " nhap thang :";
        do
        {
            in >> x.date.thang;
            if (x.date.thang < 0 || x.date.thang > 12)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.date.thang < 0 || x.date.thang > 12);
        cout << " nhap nam :";
        do
        {
            in >> x.date.nam;
            if (x.date.nam > 2024)
            {
                cout << " sai ki tu nhap lai " << endl;
            }

        } while (x.date.nam > 2024);
        cout << " Don gia :";
        in >> x.DonGia;
        cout << " Loai dat  :";
        do
        {
            in.ignore();
            in >> x.LoaiDat;
            if (x.LoaiDat != 'A' && x.LoaiDat != 'B' && x.LoaiDat != 'C')
            {
                cout << " !!!!!!!!!  sai ki tu nhap lai A B hoac C !!!!!!! " << endl;
            }
        } while (x.LoaiDat != 'A' && x.LoaiDat != 'B' && x.LoaiDat != 'C');

        cout << "Dien tich :";
        in >> x.DienTich;
        return in;
    }
};
//=====================================================================================================================================================

class GiaoDichDatDoc : public Giaodich
{
private:
    char LoaiDat;

public:
    GiaoDichDatDoc(){};
    GiaoDichDatDoc(int ma, int ngay, int thang, int nam, int dongia, char loaidat, int dientich)
    {
        this->ma = ma;
        this->date.ngay = ngay;
        this->date.thang = thang;
        this->date.nam = nam;
        this->DonGia = dongia;
        this->LoaiDat = loaidat;
        this->DienTich = dientich;
    };
    ~GiaoDichDatDoc(){};
    friend ostream &operator<<(ostream &out, GiaoDichDatDoc x)
    {
        out << x.ma << endl;
        out << x.date.ngay << endl;
        out << x.date.thang << endl;
        cout << x.date.nam << endl;
        out << x.DonGia << endl;
        out << x.LoaiDat << endl;
        out << x.DienTich << endl;
        return out;
    }

    friend istream &operator>>(istream &in, GiaoDichDatDoc &x)
    {

        in >> x.ma;
        in >> x.date.ngay;
        in >> x.date.thang;
        in >> x.date.nam;
        in >> x.DonGia;
        in >> x.LoaiDat;
        in >> x.DienTich;
        return in;
    }
    void print()
    {
        cout << "ma :";
        cout << ma << endl;
        cout << "Date :";
        cout << date.ngay << "/" << date.thang << "/" << date.nam << endl;
        cout << "Don gia :";
        cout << DonGia << endl;
        cout << "Loai Dat :";
        cout << LoaiDat << endl;
        cout << "Dien tich :";
        cout << DienTich << endl;
    }
};

//=====================================================================================================================================================

class GiaoDichNha : public Giaodich
{
private:
    string LoaiNha;
    string DiaChi;

public:
    GiaoDichNha(){};
    ~GiaoDichNha(){};
    friend ostream &operator<<(ostream &out, GiaoDichNha x)
    {
        out << x.ma << endl;
        out << x.date.ngay << "/" << x.date.thang << "/" << x.date.nam << endl;
        out << x.DonGia << endl;
        out << x.LoaiNha << endl;
        out << x.DienTich << endl;
        out << x.DiaChi << endl;
        return out;
    }
    friend istream &operator>>(istream &in, GiaoDichNha &x)
    {
        cout << " ma :";
        in >> x.ma;
        cout << " Date ->:";
        cout << " nhap ngay :";
        do
        {
            in >> x.date.ngay;
            if (x.date.ngay < 0 || x.date.ngay > 31)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.date.ngay < 0 || x.date.ngay > 31);
        cout << " nhap thang :";
        do
        {
            in >> x.date.thang;
            if (x.date.thang < 0 || x.date.thang > 12)
            {
                cout << " sai ki tu nhap lai " << endl;
            }
        } while (x.date.thang < 0 || x.date.thang > 12);
        cout << " nhap nam :";
        do
        {
            in >> x.date.nam;
            if (x.date.nam > 2024)
            {
                cout << " sai ki tu nhap lai " << endl;
            }

        } while (x.date.nam > 2024);
        cout << " Don gia :";
        in >> x.DonGia;
        cout << " Loai nha  :";
        do
        {
            getline(cin, x.LoaiNha);
            if (x.LoaiNha != "cao cap" && x.LoaiNha != "thuong")
            {
                cout << " !!!!!!!!!  sai ki tu nhap lai thuong  hoac cao cap !!!!!!! " << endl;
            }

        } while (x.LoaiNha != "cao cap" && x.LoaiNha != "thuong");
        cout << "Dien tich :";
        in >> x.DienTich;
        cout << " Dia chi :";
        cin.ignore();
        getline(cin, x.DiaChi);
        return in;
    }
};

//=====================================================================================================================================================

class GiaoDichNhaDoc : public Giaodich
{
private:
    string LoaiNha;
    string DiaChi;

public:
    GiaoDichNhaDoc(){};
    ~GiaoDichNhaDoc(){};
    friend ostream &operator<<(ostream &out, GiaoDichNhaDoc x)
    {
        out << x.ma << endl;
        out << x.date.ngay << "/" << x.date.thang << "/" << x.date.nam << endl;
        out << x.DonGia << endl;
        out << x.LoaiNha << endl;
        out << x.DienTich << endl;
        out << x.DiaChi << endl;
        return out;
    }
    friend istream &operator>>(istream &in, GiaoDichNhaDoc &x)
    {
        char e;
        in >> x.ma;
        in >> x.date.ngay;
        in >> e;
        in >> x.date.thang;
        in >> e;
        in >> x.date.nam;
        in >> x.DonGia;
        in.ignore();
        getline(in, x.LoaiNha);
        in >> x.DienTich;
        in.ignore();
        getline(in, x.DiaChi);
        return in;
    }
    void print()
    {
        cout << "ma :";
        cout << ma << endl;
        cout << "Date :";
        cout << date.ngay << "/" << date.thang << "/" << date.nam << endl;
        cout << "Don gia :";
        cout << DonGia << endl;
        cout << "Loai Nha :";
        cout << LoaiNha << endl;
        cout << "Dien tich :";
        cout << DienTich << endl;
        cout << "Dia chi :";
        cout << DiaChi << endl;
    }
};
//=====================================================================================================================================================
void DienGiaoDichNha()
{
    cout << " DIEN THONG TIN GIAO DICH NHA" << endl;
    ofstream File1;
    File1.open("Nha.txt", ios::app);
    GiaoDichNha x;
    cin >> x;
    File1 << x;
    File1.close();
}
//=====================================================================================================================================================

void DienGiaoDichDat()
{
    cout << "DIEN THONG TIN GIAO DICH DAT" << endl;
    ofstream File1;
    File1.open("Dat.txt", ios::app);
    GiaoDichDat x;
    cin >> x;
    File1 << x;
    File1.close();
    int tien;
    if (x.ReturnLoaiDat() == 'A')
    {
        tien = 1000 * x.ReturnLoaiDat();
    }
    else if (x.ReturnLoaiDat() == 'B')
    {
        tien = 800 * x.ReturnLoaiDat();
    }
    else
    {
        tien = 300 * x.ReturnLoaiDat();
    }
    ofstream File2("GiaoDich.txt", ios::app);
    File2 << tien << endl;
    File2.close();
}
//=====================================================================================================================================================

void TimGiaoDichDat()
{
    int y;
    cout << " NHAP MA DE TIM GIAO DICH DAT :";
    cin >> y;
    ifstream File1;
    File1.open("Dat.txt", ios::in);
    bool check = false;
    GiaoDichDatDoc a;
    while (File1 >> a)
    {
        if (y == a.ReturnMa())
        {
            a.print();
            check = true;
        }
    }
    if (check == false)
    {
        cout << " ma khong ton tai " << endl;
    }
}
void TimGiaoDichNha()
{
    int y;
    cout << " NHAP MA DE TIM GIAO DICH NHA :";
    cin >> y;
    ifstream File1;
    File1.open("Nha.txt", ios::in);
    bool check = false;
    GiaoDichNhaDoc a;
    while (File1 >> a)
    {
        if (y == a.ReturnMa())
        {
            a.print();
            check = true;
        }
    }
    if (check == false)
    {
        cout << " ma khong ton tai " << endl;
    }
}

//=====================================================================================================================================================
void TrungBinh()
{
    ifstream File1("GiaoDich.txt", ios::in);
    int x;
    int sl = 0;
    int tong = 0;
    while (File1 >> x)
    {
        sl++;
        tong += x;
    }
    cout << sl << endl;
    cout << " trung binh giao dich dat :" << tong / sl << " $" << endl;
}
//=====================================================================================================================================================
void XuatTheoNgayThang()
{
    int ngay, thang, nam;
    cout << " nhap ngay thang nam de xuat giao dich" << endl;
    cout << " nhap ngay :";
    do
    {
        cin >> ngay;
        if (ngay < 0 || ngay > 31)
        {
            cout << " ki tu khong hop ly" << endl;
        }
    } while (ngay < 0 || ngay > 31);
    cout << " nhap thang :";
    do
    {
        cin >> thang;
        if (thang < 0 || thang > 12)
        {
            cout << " ki tu khong hop ly" << endl;
        }
    } while (thang < 0 || thang > 12);
    cout << " nhap nam :";
    do
    {
        cin >> nam;
        if (nam > 2024)
        {
            cout << " ki tu khong hop ly " << endl;
        }

    } while (nam > 2024);
    int j = 0;
    ifstream File1("Dat.txt", ios::in);
    GiaoDichDatDoc a[100];

    while (File1 >> a[j])
    {

        if (a[j].ReturnNgay() == ngay && a[j].ReturnThang() == thang && a[j].ReturnNam() == nam)
        {
            j++;
        }
    }
    int count = j;
    cout << count << endl;
    cout << " THONG TIN GIAO DICH DAT " << endl;
    cout << " ngay " << ngay << " thang " << thang << " nam " << nam << endl;
    for (int k = 0; k < count; k++)
    {
        a[k].print();
        cout << "-------------" << endl;
    }
    File1.close();
}

void XuatTheoNgayThang1()
{
    int ngay, thang, nam;
    cout << " nhap ngay thang nam de xuat giao dich" << endl;
    cout << " nhap ngay :";
    do
    {
        cin >> ngay;
        if (ngay < 0 || ngay > 31)
        {
            cout << " ki tu khong hop ly" << endl;
        }
    } while (ngay < 0 || ngay > 31);
    cout << " nhap thang :";
    do
    {
        cin >> thang;
        if (thang < 0 || thang > 12)
        {
            cout << " ki tu khong hop ly" << endl;
        }
    } while (thang < 0 || thang > 12);
    cout << " nhap nam :";
    do
    {
        cin >> nam;
        if (nam > 2024)
        {
            cout << " ki tu khong hop ly " << endl;
        }

    } while (nam > 2024);
    int j = 0;
    ifstream File1("Nha.txt", ios::in);
    GiaoDichNhaDoc a[100];

    while (File1 >> a[j])
    {

        if (a[j].ReturnNgay() == ngay && a[j].ReturnThang() == thang && a[j].ReturnNam() == nam)
        {
            j++;
        }
    }
    int count = j;
    cout << count << endl;
    cout << " THONG TIN GIAO DICH NHA " << endl;
    cout << " ngay " << ngay << " thang " << thang << " nam " << nam << endl;
    for (int k = 0; k < count; k++)
    {
        a[k].print();
        cout << "-------------" << endl;
    }
    File1.close();
}
//=====================================================================================================================================================
//=====================================================================================================================================================
//=====================================================================================================================================================
//=====================================================================================================================================================
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
        DienGiaoDichNha();
        break;
    case 2:
        DienGiaoDichDat();
        break;
    case 3:
        TimGiaoDichNha();
        break;
    case 4:
        TimGiaoDichDat();
        break;
    case 5:
        XuatTheoNgayThang();
        break;
    case 6:
        TrungBinh();
        break;
    case 7:
        XuatTheoNgayThang1();
        break;
    default:
        break;
    }
}

//=====================================================================================================================================================

int main()
{
    bool keeping = true;
    while (keeping)
    {
        cout << "*** APP QUAN LY NHA DAT ***" << endl;
        cout << " 1  them giao dich nha  " << endl;
        cout << " 2  them giao dich dat " << endl;
        cout << " 3  tim kiem giao dich nha " << endl;
        cout << " 4  tim kiem giao dich dat  " << endl;
        cout << " 5  hoa don giao dich dat theo ngay thang nam  " << endl;
        cout << " 6  trung binh tien giao dich dat " << endl;
        cout << " 7  hoa don giao dich nha theo ngay thang nam  " << endl;
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