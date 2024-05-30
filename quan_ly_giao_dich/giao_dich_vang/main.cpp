#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>
class GiaoDich
{
protected:
    int MaGiaoDich;
    int ngay;
    int thang;
    int nam;
    int DonGia;
    int TriGia;
    int SoLuong;

public:
    GiaoDich(){};
    ~GiaoDich(){};
    virtual void print()
    {
        cout << "Ma giao dich :" << MaGiaoDich << endl;
        cout << "Ngay :" << ngay << "/" << thang << "/" << nam << endl;
        cout << "Don gia :" << DonGia << endl;
        cout << "So luong :" << SoLuong << endl;
    }
    int ReturnMa()
    {
        return MaGiaoDich;
    }
    int ReturnNgay()
    {
        return ngay;
    }
    int ReturnThang()
    {
        return thang;
    }
    int ReturnNam()
    {
        return nam;
    }
    int ReturnDonGia()
    {
        return DonGia;
    }
    int ReturnSoLuong()
    {
        return SoLuong;
    }
};

//=================================================================

class GiaoDichVang : public GiaoDich
{
private:
    string LoaiVang;

public:
    friend ostream &operator<<(ostream &out, GiaoDichVang x)
    {
        out << x.MaGiaoDich << endl;
        out << x.ngay << endl;
        out << x.thang << endl;
        out << x.nam << endl;
        out << x.DonGia << endl;
        out << x.SoLuong << endl;
        out << x.LoaiVang << endl;
        return out;
    }
    friend istream &operator>>(istream &in, GiaoDichVang &x)
    {
        cout << " nhap ma giao dich :";
        in >> x.MaGiaoDich;
        cout << " Date ->:";
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
            if (x.nam > 2024)
            {
                cout << " sai ki tu nhap lai " << endl;
            }

        } while (x.nam > 2024);
        cout << "nhap don gia :";
        in >> x.DonGia;
        cout << "nhap so luong :";
        in >> x.SoLuong;
        cout << "nhap loai vang :";
        in.ignore();
        getline(in, x.LoaiVang);
        return in;
    }
    GiaoDichVang(){};
    ~GiaoDichVang(){};
    int ReturnTriGia()
    {
        return SoLuong * DonGia;
    }
};
//=================================================================

class GiaoDichVangDoc : public GiaoDich
{
private:
    string LoaiVang;

public:
    string ReturnLoaivang()
    {
        return LoaiVang;
    }
    GiaoDichVangDoc(){};
    ~GiaoDichVangDoc(){};
    int ReturnTriGia()
    {
        return SoLuong * DonGia;
    }
    GiaoDichVangDoc(int ma, int ngay, int thang, int nam, int dongia, int soluong, string loai)
    {
        this->MaGiaoDich = ma;
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
        this->DonGia = dongia;
        this->SoLuong = soluong;
        this->LoaiVang = loai;
    }
    friend ostream &operator<<(ostream &out, GiaoDichVangDoc x)
    {
        out << x.MaGiaoDich << endl;
        out << x.ngay << endl;
        out << x.thang << endl;
        out << x.nam << endl;
        out << x.DonGia << endl;
        out << x.SoLuong << endl;
        out << x.LoaiVang << endl;
        return out;
    }
    friend istream &operator>>(istream &in, GiaoDichVangDoc &x)
    {
        in >> x.MaGiaoDich;
        in >> x.ngay;
        in >> x.thang;
        in >> x.nam;
        in >> x.DonGia;
        in >> x.SoLuong;
        in.ignore();
        getline(in, x.LoaiVang);
        return in;
    }
    void print()
    {
        GiaoDich::print();
        cout << "Loai vang :" << LoaiVang << endl;
    }
};

//===============================================================================================================

class GiaoDichTien : public GiaoDich
{
private:
    int TyGia;
    string LoaiTienTe;

public:
    friend ostream &operator<<(ostream &out, GiaoDichTien x)
    {
        out << x.MaGiaoDich << endl;
        out << x.ngay << endl;
        out << x.thang << endl;
        out << x.nam << endl;
        out << x.DonGia << endl;
        out << x.SoLuong << endl;
        out << x.TyGia << endl;
        out << x.LoaiTienTe << endl;
        return out;
    }
    friend istream &operator>>(istream &in, GiaoDichTien &x)
    {
        cout << " nhap ma giao dich :";
        in >> x.MaGiaoDich;
        cout << " Date ->:";
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
            if (x.nam > 2024)
            {
                cout << " sai ki tu nhap lai " << endl;
            }

        } while (x.nam > 2024);
        cout << "nhap don gia :";
        in >> x.DonGia;
        cout << "nhap so luong :";
        in >> x.SoLuong;
        cout << "nhap ty gia :";
        in >> x.TyGia;
        cout << "nhap loai tien :";
        in.ignore();
        getline(in, x.LoaiTienTe);
        return in;
    }
    GiaoDichTien(){};
    ~GiaoDichTien(){};
    int ReturnTriGia()
    {
        return SoLuong * DonGia * TyGia;
    }
};
//================================================================================================================
class GiaoDichTienDoc : public GiaoDich
{
private:
    int TyGia;
    string LoaiTienTe;

public:
    GiaoDichTienDoc(int ma, int ngay, int thang, int nam, int dongia, int soluong, int tygia, string loai)
    {
        this->MaGiaoDich = ma;
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
        this->DonGia = dongia;
        this->SoLuong = soluong;
        this->LoaiTienTe = loai;
        this->TyGia = tygia;
    }
    GiaoDichTienDoc(){};
    ~GiaoDichTienDoc(){};
    friend ostream &operator<<(ostream &out, GiaoDichTienDoc x)
    {
        out << x.MaGiaoDich << endl;
        out << x.ngay << endl;
        out << x.thang << endl;
        out << x.nam << endl;
        out << x.DonGia << endl;
        out << x.SoLuong << endl;
        out << x.TyGia << endl;
        out << x.LoaiTienTe << endl;
        return out;
    }
    friend istream &operator>>(istream &in, GiaoDichTienDoc &x)
    {
        in >> x.MaGiaoDich;
        in >> x.ngay;
        in >> x.thang;
        in >> x.nam;
        in >> x.DonGia;
        in >> x.SoLuong;
        in >> x.TyGia;
        in.ignore();
        getline(in, x.LoaiTienTe);
        return in;
    }
    int ReturnTriGia()
    {
        return SoLuong * DonGia * TyGia;
    }
    string ReturnLoaiTien()
    {
        return LoaiTienTe;
    }
    int ReturnTyGia()
    {
        return TyGia;
    }
    void print()
    {
        GiaoDich::print();
        cout << "loai tien :" << LoaiTienTe << endl;
    }
};
//================================================================================================================
void ThemGiaoDich()
{
    cout << " vang: them giao dich vang " << endl;
    cout << " tien: them giao dich tien " << endl;
    string chose;
    cin.ignore();
    do
    {
        getline(cin, chose);
        if (chose != "vang" && chose != "tien")
        {
            cout << "sai ki tu nhap lai !!!!!" << endl;
        }
    } while (chose != "vang" && chose != "tien");
    if (chose == "vang")
    {
        ofstream File1("Vang.txt", ios::app);
        ofstream File2("TrungBinhThuNhapVang.txt", ios::app);
        GiaoDichVang a;
        cin >> a;
        File1 << a;
        File2 << a.ReturnTriGia() << endl;
        File2.close();
        File1.close();
    }
    else
    {
        ofstream File1("Tien.txt", ios::app);
        ofstream File2("TrungBinhThuNhapTien.txt", ios::app);
        GiaoDichTien a;
        cin >> a;
        File1 << a;
        File2 << a.ReturnTriGia() << endl;
        File2.close();
        File1.close();
    }
}
//=============================================================================================================
void TimKiemGiaoDich()
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
    cout << " 1 de tim kiem giao dich vang theo ngay thang nam :" << endl;
    cout << " 2 de tim kiem giao dich tien theo ngay thang nam : " << endl;
    int check;
    cin >> check;
    if (check == 1)
    {
        cout << " ngay " << ngay << " thang " << thang << " nam " << nam << endl;
        ifstream File1("Vang.txt", ios::in);
        GiaoDichVangDoc a[100];
        int j = 0;
        while (File1 >> a[j])
        {

            if (a[j].ReturnNgay() == ngay && a[j].ReturnThang() == thang && a[j].ReturnNam() == nam)
            {
                j++;
            }
        }
        int count = j;
        for (int i = 0; i < count; i++)
        {
            a[i].print();
            cout << " -----------------------------------------" << endl;
        }
        File1.close();
    }
    else
    {
        cout << " ngay " << ngay << " thang " << thang << " nam " << nam << endl;
        ifstream File1("Tien.txt", ios::in);
        GiaoDichTienDoc a[100];
        int j = 0;
        while (File1 >> a[j])
        {

            if (a[j].ReturnNgay() == ngay && a[j].ReturnThang() == thang && a[j].ReturnNam() == nam)
            {
                j++;
            }
        }
        int count = j;
        for (int i = 0; i < count; i++)
        {
            a[i].print();
            cout << " -----------------------------------------" << endl;
        }

        File1.close();
    }
}
void TrungBinhTienGiaoDich()
{

    cout << " vang: trung binh tien giao dich vang " << endl;
    cout << " tien: trung binh tien giao dich tien " << endl;
    string chose;
    cin.ignore();
    do
    {
        getline(cin, chose);
        if (chose != "vang" && chose != "tien")
        {
            cout << "sai ki tu nhap lai !!!!!" << endl;
        }
    } while (chose != "vang" && chose != "tien");
    if (chose == "vang")
    {
        ifstream File1("TrungBinhThuNhapVang.txt", ios::in);
        int x = 0;
        int tong = 0;
        int lan = 0;
        while (File1 >> x)
        {
            tong += x;
            ++lan;
        }
        cout << "tien giao dich trung binh la :" << tong / lan << "$" << endl;
        File1.close();
    }
    else
    {
        ifstream File1("TrungBinhThuNhapTien.txt", ios::in);
        int x = 0;
        int tong = 0;
        int lan = 0;
        while (File1 >> x)
        {
            tong += x;
            ++lan;
        }
        cout << "tien giao dich trung binh la :" << tong / lan << "$" << endl;
        File1.close();
    }
}
//========================================================//===============================================================================
void ChinhSuaGiaoDichVang()
{
    cout << " nhap ma de thay doi thong tin giao dich" << endl;
    int i = 0;
    GiaoDichVangDoc a[100];
    int ma, ngay, thang, nam, dongia, soluong, trigia;
    bool check = false;
    string LoaiVang;
    do
    {

        cin >> ma;
        ifstream File1("Vang.txt", ios::in);
        while (File1 >> a[i])
        {
            if (a[i].ReturnMa() == ma)
            {
                ngay = a[i].ReturnNgay();
                thang = a[i].ReturnThang();
                nam = a[i].ReturnNam();
                dongia = a[i].ReturnDonGia();
                soluong = a[i].ReturnSoLuong();
                LoaiVang = a[i].ReturnLoaivang();
                trigia = a[i].ReturnTriGia();
                check = true;
                i--;
            }
            i++;
        }
        File1.close();
        if (check == false)
        {
            cout << " ma sai " << endl;
        }
    } while (check == false);
    int count = i;
    ofstream File2("Vang.txt", ios::trunc);
    for (int i = 0; i < count; i++)
    {
        File2 << a[i];
    }
    File2.close();
    // xoa doi tuong can sua ////////////////////////////////////==///////////////////////////////////////////////////////////////////////////
    cout << "1 chinh sua ngay thang nam " << endl;
    cout << "2 chinh sua don gia " << endl;
    cout << "3 chinh sua so luong " << endl;
    cout << "4 chinh sua loai vang  " << endl;
    int chose;
    cin >> chose;
    if (chose == 1)
    {
        int NGAY, THANG, NAM;
        cout << " nhap ngay :";
        do
        {
            cin >> NGAY;
            if (NGAY < 0 || NGAY > 31)
            {
                cout << " ki tu khong hop ly" << endl;
            }
        } while (NGAY < 0 || NGAY > 31);
        cout << " nhap thang :";
        do
        {
            cin >> THANG;
            if (THANG < 0 || THANG > 12)
            {
                cout << " ki tu khong hop ly" << endl;
            }
        } while (THANG < 0 || THANG > 12);
        cout << " nhap nam :";
        do
        {
            cin >> NAM;
            if (NAM > 2024)
            {
                cout << " ki tu khong hop ly " << endl;
            }

        } while (NAM > 2024);
        GiaoDichVangDoc x(ma, NGAY, THANG, NAM, dongia, soluong, LoaiVang);
        ofstream File1("Vang.txt", ios::app);
        File1 << x;
        File1.close();
    }
    else if (chose == 2)
    {
        ifstream File3("TrungBinhThuNhapVang.txt", ios::in);
        int TriGia[100];
        int j = 0;
        while (File3 >> TriGia[j])
        {
            if (trigia == TriGia[j])
            {
                j--;
            }
            j++;
        }
        File3.close();
        int count = j;
        ofstream File4("TrungBinhThuNhapVang.txt", ios::trunc);
        for (int i = 0; i < count; i++)
        {
            File4 << TriGia[i] << endl;
        }
        File4.close();

        // xoa tri gia
        cout << "Nhap don gia thay doi :";
        int DONGIA;
        cin >> DONGIA;
        GiaoDichVangDoc x(ma, ngay, thang, nam, DONGIA, soluong, LoaiVang);
        ofstream File1("Vang.txt", ios::app);
        File1 << x;
        File1.close();
        ofstream File2("TrungBinhThuNhapVang.txt", ios::app);
        File2 << x.ReturnTriGia() << endl;
        File2.close();
    }
    else if (chose == 3)
    {
        ifstream File3("TrungBinhThuNhapVang.txt", ios::in);
        int TriGia[100];
        int j = 0;
        while (File3 >> TriGia[j])
        {
            if (trigia == TriGia[j])
            {
                j--;
            }
            j++;
        }
        File3.close();
        int count = j;
        ofstream File4("TrungBinhThuNhapVang.txt", ios::trunc);
        for (int i = 0; i < count; i++)
        {
            File4 << TriGia[i] << endl;
        }
        File4.close();

        // xoa tri gia
        cout << "nhap so luong de thay doi :" << endl;
        int SOLUONG;
        cin >> SOLUONG;
        GiaoDichVangDoc x(ma, ngay, thang, nam, dongia, SOLUONG, LoaiVang);
        ofstream File1("Vang.txt", ios::app);
        File1 << x;
        File1.close();
        ofstream File2("TrungBinhThuNhapVang.txt", ios::app);
        File2 << x.ReturnTriGia() << endl;
        File2.close();
    }
    else if (chose == 4)
    {
        cout << "nhap loai vang de thay doi :" << endl;
        string LOAIVANG;
        cin.ignore();
        getline(cin, LOAIVANG);
        GiaoDichVangDoc x(ma, ngay, thang, nam, dongia, soluong, LOAIVANG);
        ofstream File1("Vang.txt", ios::app);
        File1 << x;
        File1.close();
    }
    else
    {
        cout << " sai ki tu!!!!!!!" << endl;
    }
}
//=================================================================================================================




void ChinhSuaGiaoDichTien()
{
    cout << " nhap ma de thay doi thong tin giao dich" << endl;
    int i = 0;
    GiaoDichTienDoc a[100];
    int ma, ngay, thang, nam, dongia, soluong, trigia, tygia;
    bool check = false;
    string LoaiTien;
    do
    {
        cin >> ma;
        ifstream File1("Tien.txt", ios::in);
        while (File1 >> a[i])
        {
            if (a[i].ReturnMa() == ma)
            {
                ngay = a[i].ReturnNgay();
                thang = a[i].ReturnThang();
                nam = a[i].ReturnNam();
                dongia = a[i].ReturnDonGia();
                soluong = a[i].ReturnSoLuong();
                LoaiTien = a[i].ReturnLoaiTien();
                tygia = a[i].ReturnTyGia();
                trigia = a[i].ReturnTriGia();
                check = true;
                i--;
            }
            i++;
        }
        File1.close();
        if (check == false)
        {
            cout << " ma sai " << endl;
        }
    } while (check == false);
    int count = i;
    ofstream File2("Tien.txt", ios::trunc);
    for (int i = 0; i < count; i++)
    {
        File2 << a[i];
    }



    File2.close();
    // xoa doi tuong can sua ////////////////////////////////////==///////////////////////////////////////////////////////////////////////////
    cout << "1 chinh sua ngay thang nam " << endl;
    cout << "2 chinh sua don gia " << endl;
    cout << "3 chinh sua so luong " << endl;
    cout << "4 chinh sua loai tien  " << endl;
    int chose;
    cin >> chose;
    if (chose == 1)
    {
        int NGAY, THANG, NAM;
        cout << " nhap ngay :";
        do
        {
            cin >> NGAY;
            if (NGAY < 0 || NGAY > 31)
            {
                cout << " ki tu khong hop ly" << endl;
            }
        } while (NGAY < 0 || NGAY > 31);
        cout << " nhap thang :";
        do
        {
            cin >> THANG;
            if (THANG < 0 || THANG > 12)
            {
                cout << " ki tu khong hop ly" << endl;
            }
        } while (THANG < 0 || THANG > 12);
        cout << " nhap nam :";
        do
        {
            cin >> NAM;
            if (NAM > 2024)
            {
                cout << " ki tu khong hop ly " << endl;
            }

        } while (NAM > 2024);
        GiaoDichTienDoc x(ma, NGAY, THANG, NAM, dongia, soluong, tygia, LoaiTien);
        ofstream File1("Tien.txt", ios::app);
        File1 << x;
        File1.close();
    }
    else if (chose == 2)
    {
        ifstream File3("TrungBinhThuNhapTien.txt", ios::in);
        int TriGia[100];
        int j = 0;
        while (File3 >> TriGia[j])
        {
            if (trigia == TriGia[j])
            {
                j--;
            }
            j++;
        }
        File3.close();
        int count = j;
        ofstream File4("TrungBinhThuNhapTien.txt", ios::trunc);
        for (int i = 0; i < count; i++)
        {
            File4 << TriGia[i] << endl;
        }
        File4.close();
        // xoa tri gia
        cout << "Nhap don gia thay doi :";
        int DONGIA;
        cin >> DONGIA;
        GiaoDichTienDoc x(ma, ngay, thang, nam, DONGIA, soluong, tygia, LoaiTien);
        ofstream File1("Tien.txt", ios::app);
        File1 << x;
        File1.close();
        ofstream File2("TrungBinhThuNhapTien.txt", ios::app);
        File2 << x.ReturnTriGia() << endl;
        File2.close();
    }
    else if (chose == 3)
    {
        ifstream File3("TrungBinhThuNhapTien.txt", ios::in);
        int TriGia[100];
        int j = 0;
        while (File3 >> TriGia[j])
        {
            if (trigia == TriGia[i])
            {
                j--;
            }
            j++;
        }
        File3.close();
        int count = j;
        ofstream File4("TrungBinhThuNhapTien.txt", ios::trunc);
        for (int i = 0; i < count; i++)
        {
            File4 << TriGia[i] << endl;
        }
        File4.close();
        // xoa tri gia
        cout << "nhap so luong de thay doi :" << endl;
        int SOLUONG;
        cin >> SOLUONG;
        GiaoDichTienDoc x(ma, ngay, thang, nam, dongia, SOLUONG, tygia, LoaiTien);
        ofstream File1("Tien.txt", ios::app);
        File1 << x;
        File1.close();
        ofstream File2("TrungBinhThuNhapTien.txt", ios::app);
        File2 << x.ReturnTriGia() << endl;
        File2.close();
    }
    else if (chose == 4)
    {
        cout << "nhap loai vang de thay doi :" << endl;
        string LOAITIEN;
        cin.ignore();
        getline(cin, LOAITIEN);
        GiaoDichTienDoc x(ma, ngay, thang, nam, dongia, soluong, tygia, LOAITIEN);
        ofstream File1("Tien.txt", ios::app);
        File1 << x;
        File1.close();
    }
    else
    {
        cout << " sai ki tu!!!!!!!" << endl;
    }



}
//=========================================================================================================================================
void XoaGiaoDichTien()
{
    cout << " nhap ma de xoa thong tin giao dich" << endl;
    int i = 0;
    GiaoDichTienDoc a[100];
    int ma, trigia;
    bool check = false;
    string LoaiTien;
    do
    {
        cin >> ma;
        ifstream File1("Tien.txt", ios::in);
        while (File1 >> a[i])
        {
            if (a[i].ReturnMa() == ma)
            {
                LoaiTien = a[i].ReturnLoaiTien();
                trigia = a[i].ReturnTriGia();
                check = true;
                i--;
            }
            i++;
        }
        File1.close();
        if (check == false)
        {
            cout << " ma sai " << endl;
        }
    } while (check == false);
    int count = i;
    ofstream File2("Tien.txt", ios::trunc);
    for (int i = 0; i < count; i++)
    {
        File2 << a[i];
    }
    File2.close();
    ifstream File3("TrungBinhThuNhapTien.txt", ios::in);
    int TriGia[100];
    int j = 0;
    while (File3 >> TriGia[j])
    {
        if (trigia == TriGia[j])
        {
            j--;
        }
        j++;
    }
    File3.close();
    int count1 = j;
    ofstream File4("TrungBinhThuNhapTien.txt", ios::trunc);
    for (int i = 0; i < count1; i++)
    {
        File4 << TriGia[i] << endl;
    }
    File4.close();
}


void XoaGiaoDichVang()
{
    cout << " nhap ma de xoa thong tin giao dich" << endl;
    int i = 0;
    GiaoDichVangDoc a[100];
    int ma, trigia;
    bool check = false;

    do
    {

        cin >> ma;
        ifstream File1("Vang.txt", ios::in);
        while (File1 >> a[i])
        {
            if (a[i].ReturnMa() == ma)
            {
                trigia = a[i].ReturnTriGia();
                check = true;
                i--;
            }
            i++;
        }
        File1.close();
        if (check == false)
        {
            cout << " ma sai " << endl;
        }
    } while (check == false);
    int count = i;
    ofstream File2("Vang.txt", ios::trunc);
    for (int i = 0; i < count; i++)
    {
        File2 << a[i];
    }
    File2.close();
    ifstream File3("TrungBinhThuNhapVang.txt", ios::in);
    int TriGia[100];
    int j = 0;
    while (File3 >> TriGia[j])
    {
        if (trigia == TriGia[j])
        {
            j--;
        }
        j++;
    }
    File3.close();
    int count1 = j;
    ofstream File4("TrungBinhThuNhapVang.txt", ios::trunc);
    for (int i = 0; i < count1; i++)
    {
        File4 << TriGia[i] << endl;
    }
    File4.close();
}



//=================================================================================================================


int check;
//=================================================================================================================

void menu()
{
    switch (check)
    {
    case 1:
        ThemGiaoDich();
        break;
    case 2:
        TimKiemGiaoDich();
        break;
    case 3:
        TrungBinhTienGiaoDich();
        break;
    case 4:
        ChinhSuaGiaoDichTien();
        break;
    case 5:
        ChinhSuaGiaoDichVang();
        break;
        break;
    case 6:
        XoaGiaoDichTien();
        break;
    case 7:
        XoaGiaoDichVang();
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
        cout << "*** SAN GIAO DICH ***" << endl;
        cout << " 1 them giao dich " << endl;
        cout << " 2 tim kiem giao dich " << endl;
        cout << " 3 trung binh tien giao dich " << endl;
        cout << " 4 chinh sua thong tin giao dich tien" << endl;
        cout << " 5 chinh sua thong tin giao dich vang" << endl;
        cout << " 6 xoa giao dich tien" << endl;
        cout << " 7 xoa giao dich vang" << endl;
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