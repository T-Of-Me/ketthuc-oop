#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <time.h>
//=====================================================================================================================================================

using namespace std;

class CustomerNhap
{
    friend ostream &operator<<(ostream &, CustomerNhap &);
    friend istream &operator>>(istream &, CustomerNhap &);

private:
    int id;
    string name;
    string phoneNum;
    string email;

public:
    string getPhoneNum() { return phoneNum; };
    int getID() { return id; };
};
ostream &operator<<(ostream &out, CustomerNhap &cus)
{
    out << cus.id << endl;
    out << cus.name << endl;
    out << cus.phoneNum << endl;
    out << cus.email << endl;
    return out;
}
istream &operator>>(istream &in, CustomerNhap &cus)
{
    cout << "nhap id khach hang :";
    in >> cus.id;
    cout << "nhap ten :";
    in.ignore();
    getline(in, cus.name);
    cout << "nhap std :";
    in >> cus.phoneNum;
    cout << "nhap email :";
    in.ignore();
    getline(in, cus.email);
    return in;
}
//=====================================================================================================================================================

class CustomerDoc
{
    friend ostream &operator<<(ostream &, CustomerDoc &);
    friend istream &operator>>(istream &, CustomerDoc &);

private:
    int id;
    string name;
    string phoneNum;
    string email;

public:
    CustomerDoc(){};
    string ReturnPhoneNum() { return phoneNum; };
    int ReturnID() { return id; };
    string ReturnName() { return name; };
    string ReturnEmail() { return email; }
    CustomerDoc(int id, string name, string phone, string email)
    {
        this->id = id;
        this->name = name;
        this->phoneNum = phone;
        this->email = email;
    }

    void print()
    {
        cout << "id khach hang :" << id << endl;
        cout << "ten :" << name << endl;
        cout << "std :" << phoneNum << endl;
        cout << "nhap email :" << email << endl;
    }
};
ostream &operator<<(ostream &out, CustomerDoc &cus)
{
    out << cus.id << endl;
    out << cus.name << endl;
    out << cus.phoneNum << endl;
    out << cus.email << endl;
    return out;
}
istream &operator>>(istream &in, CustomerDoc &cus)
{
    in >> cus.id;
    in.ignore();
    getline(in, cus.name);
    in >> cus.phoneNum;
    in.ignore();
    getline(in, cus.email);
    return in;
}

//=====================================================================================================================================================

class CarNhap
{
    friend ostream &operator<<(ostream &, CarNhap &);
    friend istream &operator>>(istream &, CarNhap &);

private:
    int id;
    string name;
    string model;
    string color;
    int speed;
    bool autoM;
    string licensePal;

public:
    int getId() { return id; };
};
ostream &operator<<(ostream &out, CarNhap &cr)
{

    out << cr.id << endl;
    out << cr.name << endl;
    out << cr.model << endl;
    out << cr.color << endl;
    out << cr.speed << endl;
    return out;
}
istream &operator>>(istream &in, CarNhap &cr)
{
    cout << "---NHAP THONG TIN XE---";
    cout << " nhap id xe :";
    in >> cr.id;
    cout << "nhap ten xe :";
    in.ignore();
    getline(in, cr.name);
    cout << "nhap model :";
    in >> cr.model;
    cout << "nhap color :";
    in >> cr.color;
    cout << "nhap speed :";
    in >> cr.speed;
    return in;
}
//=====================================================================================================================================================

class CarDoc
{
    friend ostream &operator<<(ostream &, CarDoc &);
    friend istream &operator>>(istream &, CarDoc &);

private:
    int id;
    string name;
    string model;
    string color;
    int speed;
    bool autoM;
    string licensePal;

public:
    CarDoc(){};
    int getId() { return id; };
    void print()
    {
        cout << "id :" << id << endl;
        cout << "ten xe :" << name << endl;
        cout << "model :" << model << endl;
        cout << "color :" << color << endl;
        cout << "speed :" << speed << endl;
    }
};
ostream &operator<<(ostream &out, CarDoc &cr)
{
    out << cr.id << endl;
    out << cr.name << endl;
    out << cr.model << endl;
    out << cr.color << endl;
    out << cr.speed << endl;
    return out;
}
istream &operator>>(istream &in, CarDoc &cr)
{
    in >> cr.id;
    in.ignore();
    getline(in, cr.name);
    in >> cr.model;
    in >> cr.color;
    in >> cr.speed;
    return in;
}
//=====================================================================================================================================================

class Rental
{

    friend ostream &operator<<(ostream &, Rental &);
    friend istream &operator>>(istream &, Rental &);

private:
    int idCar;
    int idCus;
    int ngay;
    int gio;

public:
    Rental(){};
    Rental(int idCa, int idCu, int ng, int g)
    {
        this->idCar = idCa;
        this->idCus = idCu;
        this->gio = g;
        this->ngay = ng;
    };
    int getNgay() { return ngay; };
    int getGio() { return gio; };
    int IdCar()
    {
        return idCar;
    }
    int IdCus()
    {
        return idCus;
    }
};
ostream &operator<<(ostream &out, Rental &rt)
{
    out << endl
        << " " << rt.idCar << " " << rt.idCus << " " << rt.ngay << " " << rt.gio;
    return out;
}
istream &operator>>(istream &in, Rental &rt)
{
    in >> rt.idCar;
    in >> rt.idCus;
    in >> rt.ngay;
    in >> rt.gio;
    return in;
}
//==================================================================================================================================================
int CheckMaXeTonTai(int MaNhap)
{
    ifstream File("Car.txt", ios::in);
    CarDoc a;
    while (File >> a)
    {
        if (a.getId() == MaNhap)
        {
            cout << "xe da ton tai" << endl;
            return 1;
        }
    }
    cout << "  xe chua ton tai " << endl;
    return 0;
}

//=====================================================================================================================================================

//=====================================================================================================================================================
void NhapThongTinXe()
{
    ofstream File1, File2;
    File1.open("Car.txt", ios::app);
    File2.open("CarCoDich.txt", ios::app);
    CarNhap a;
    do
    {
        cin >> a;
    } while (CheckMaXeTonTai(a.getId()) == 1);
    File1 << a;
    File2 << a;
    File1.close();
    File2.close();
}
//=====================================================================================================================================================
int CheckIdKhachHangTonTai(int check)
{
    ifstream File;
    File.open("ThongTinKhachHang.txt", ios::in);
    CustomerDoc a;
    while (File >> a)
    {
        if (a.ReturnID() == check)
        {
            cout << " thong tin khach hang ton tai" << endl;
            return 1;
        }
    }
    cout << " thong tin khach hang chua ton tai " << endl;
    return 0;
}
//=====================================================================================================================================================
void DaThueXeNaokhong()
{
    cout << " Nhap id khach hang kiem tra" << endl;
    int Cus;
    do
    {
        cin >> Cus;
    } while (CheckIdKhachHangTonTai(Cus) == 0);
    ifstream File1;
    File1.open("ThueXe.txt", ios::in);
    Rental x;
    int y[100];
    ifstream File2;
    File2.open("CarCoDich.txt", ios::in);
    CarDoc z[100];
    int i = 0;
    int j = 0;
    int n[100];
    int g[1000];
    while (File1 >> x)
    {
        if (x.IdCus() == Cus)
        {
            y[j] = x.IdCar();
            n[j] = x.getNgay();
            g[j] = x.getGio();
            j++;
        }
    }
    int count2 = j;
    File1.close();
    while (File2 >> z[i])
    {
        i++;
    }
    int count = i;
    for (int j = 0; j < count2; j++)
    {
        for (int i = 0; i < count; i++)
        {
            if (z[i].getId() == y[j])
            {
                z[i].print();
                cout << "Gio thue :" << g[j] << endl;
                cout << "Ngay thue :" << n[j] << endl;
                cout << "-------------------" << endl;
            }
        }
    }

    if (j == 0)
    {
        cout << " khach hang chua thue xe nao ca" << endl;
    }

    File2.close();
}
//=====================================================================================================================================================
void ThueXe(int idCus)
{
    cout << " tien hanh quan trinh thue xe " << endl;
    cout << " nhap id xe :";
    int idXe;
    do
    {
        cin >> idXe;
    } while (CheckMaXeTonTai(idXe) == 0);
    cout << " xe ton tai bat dau thue" << endl;
    // ghi file thue
    ofstream FIle("ThueXe.txt", ios::app);
    int ngay, gio;
    cout << "nhap ngay :";
    cin >> ngay;
    cout << "nhap gio :";
    cin >> gio;
    Rental x(idXe, idCus, ngay, gio);
    FIle << x;
    // xoa xe
    ifstream File1("Car.txt", ios::in);
    CarDoc c[100];
    int i = 0;
    while (File1 >> c[i])
    {

        if (c[i].getId() == idXe)
        {
            i--;
        }
        i++;
    }
    int count2 = 0;
    count2 = i;
    File1.close();
    //=====
    //=====
    ofstream File2("Car.txt", ios::trunc);
    for (int i = 0; i < count2; i++)
    {
        File2 << c[i];
    }
    File2.close();
    FIle.close();
}
//=====================================================================================================================================================
void TraXe1()
{
    // xoa o lop thue

    int iDKhach;
    Rental a;
    int i = 0;
    int check = 0; // file chi doc 1 lan
    do
    {
        ifstream File1("ThueXe.txt", ios::in);
        cout << " Nhap id khach xe de tra :";
        cin >> iDKhach;
        while (File1 >> a)
        {
            if (a.IdCus() == iDKhach)
            {
                --i;
                check = 1;
            }
            i++;
        }
        if (check == 0)
        {
            cout << " khach hang chua thue xe" << endl;
            i = 0;
        }
        File1.close();
    } while (check == 0); // khach co dang thue hay khong
    int j = 0;
    int idCarCanTra;
    Rental k[100];
    int checking = 0;
    do
    {
        ifstream File5("ThueXe.txt", ios::in);
        cout << " nhap id car can tra :";
        cin >> idCarCanTra;
        while (File5 >> k[j])
        {
            if (k[j].IdCar() == idCarCanTra)
            {
                j--;
                checking = 1;
            }
            j++;
        }
        if (checking == 0)
        {
            j = 0;
            cout << " id car sai " << endl;
        }
        File5.close();
    } while (checking == 0);
    int GioThue = k[j].getGio();
    int NgayThue = k[j].getNgay();
    int count = j;
    ofstream File2("ThueXe.txt", ios::trunc);
    for (int j = 0; j < count; j++)
    {
        File2 << k[j];
    }
    File2.close();
    //= xoa thanh cong
    ifstream File3("CarCoDich.txt", ios::in);
    CarDoc b;
    while (File3 >> b)
    {
        if (b.getId() == idCarCanTra)
        {
            break;
        }
    }
    File3.close();
    ofstream File4("Car.txt", ios::app);
    File4 << b;
    File4.close();
    // lay thong tin khach hang
    string ten;
    ifstream File6("ThongTinKhachHang.txt", ios::in);
    CustomerDoc cus;
    while (File6 >> cus)
    {
        if (cus.ReturnID() == iDKhach)
        {
            break;
        }
    }
    ten = cus.ReturnName();
    cout << " =========HOA DON========== " << endl;
    cout << " ten nguoi thue :" << ten << endl;
    cout << " thanh toan :" << NgayThue * 500 + GioThue * 50 << "$" << endl;
    // hoa don
}

//=====================================================================================================================================================
void NhapThongTinKhachHang()
{
    cout << "Nhap thong tin khach hang " << endl;
    ofstream File1("ThongTinKhachHang.txt", ios::app);
    CustomerNhap a;
    cin >> a;
    File1 << a;
    File1.close();
}

//=====================================================================================================================================================

void QuaTrinhThueXe()
{
    cout << "nhap ID khach hang" << endl;
    int idKhach;
    cin >> idKhach;
    if (CheckIdKhachHangTonTai(idKhach) == 1)
    {

        ThueXe(idKhach);
    }
    else
    {
        NhapThongTinKhachHang();
        ThueXe(idKhach);
    }
}
//=====================================================================================================================================================

void DanhSachXeChuaDuocTHue()
{
    cout << "danh sach xe chua duoc thue :" << endl;
    ifstream File1;
    File1.open("Car.txt", ios::in);
    CarDoc a;
    while (File1 >> a)
    {
        a.print();
        cout << " ........................." << endl;
    }
    File1.close();
}

//===================================================================================================================================================
void ChinhSuaTen()
{
    cout << "nhap id khach hang can sua ten :";
    string name, sdt, email;
    int id;
    CustomerDoc a;
    int check = 0;
    do
    {
        cin >> id;
        ifstream File1("ThongTinKhachHang.txt", ios::in);
        while (File1 >> a)
        {
            if (a.ReturnID() == id)
            {
                check = 1;
                break;
            }
        }
        if (check == 0)
        {
            cout << " khong ton tai khach hang " << endl;
        }
        File1.close();
    } while (check == 0);
    // sau day la xoa
    CustomerDoc b[100];
    int i = 0;
    ifstream File2("ThongTinKhachHang.txt", ios::in);
    while (File2 >> b[i])
    {
        if (b[i].ReturnID() == id)
        {
            i--;
        }
        i++;
    }
    int count = i;
    File2.close();
    ofstream File3("ThongTinKhachHang.txt", ios::trunc);
    for (int i = 0; i < count; i++)
    {
        File3 << b[i];
    }
    File3.close();
    // thay doi thong tin
    ofstream File4("ThongTinKhachHang.txt", ios::app);
    sdt = a.ReturnPhoneNum();
    email = a.ReturnEmail();
    cout << " nhap ten thay doi :" << endl;
    cin.ignore();
    getline(cin, name);
    CustomerDoc z(id, name, sdt, email);
    File4 << z;
    File4.close();
    cout << " thay doi ten thanh cong" << endl;
    //====
}
//===================================================================================================================================================
void ChinhSuaSdt()
{
    cout << "nhap id khach hang can sua sdt :";
    string name, sdt, email;
    int id;
    CustomerDoc a;
    int check = 0;
    do
    {
        cin >> id;
        ifstream File1("ThongTinKhachHang.txt", ios::in);
        while (File1 >> a)
        {
            if (a.ReturnID() == id)
            {
                check = 1;
                break;
            }
        }
        if (check == 0)
        {
            cout << " khong ton tai khach hang " << endl;
        }
        File1.close();
    } while (check == 0);
    // sau day la xoa
    CustomerDoc b[100];
    int i = 0;
    ifstream File2("ThongTinKhachHang.txt", ios::in);
    while (File2 >> b[i])
    {
        if (b[i].ReturnID() == id)
        {
            i--;
        }
        i++;
    }
    int count = i;
    File2.close();
    ofstream File3("ThongTinKhachHang.txt", ios::trunc);
    for (int i = 0; i < count; i++)
    {
        File3 << b[i];
    }
    File3.close();
    // thay doi thong tin
    ofstream File4("ThongTinKhachHang.txt", ios::app);
    name = a.ReturnName();
    email = a.ReturnEmail();
    cout << " nhap sdt thay doi :" << endl;
    cin.ignore();
    getline(cin, sdt);
    CustomerDoc z(id, name, sdt, email);
    File4 << z;
    File4.close();
    cout << " thay doi sdt thanh cong" << endl;
    //====
}
//===================================================================================================================================================
void ChinhSuaEmail()
{
    cout << "nhap id khach hang can sua Email :";
    string name, sdt, email;
    int id;
    CustomerDoc a;
    int check = 0;
    do
    {
        cin >> id;
        ifstream File1("ThongTinKhachHang.txt", ios::in);
        while (File1 >> a)
        {
            if (a.ReturnID() == id)
            {
                check = 1;
                break;
            }
        }
        if (check == 0)
        {
            cout << " khong ton tai khach hang " << endl;
        }
        File1.close();
    } while (check == 0);
    // sau day la xoa
    CustomerDoc b[100];
    int i = 0;
    ifstream File2("ThongTinKhachHang.txt", ios::in);
    while (File2 >> b[i])
    {
        if (b[i].ReturnID() == id)
        {
            i--;
        }
        i++;
    }
    int count = i;
    File2.close();
    ofstream File3("ThongTinKhachHang.txt", ios::trunc);
    for (int i = 0; i < count; i++)
    {
        File3 << b[i];
    }
    File3.close();
    // thay doi thong tin
    ofstream File4("ThongTinKhachHang.txt", ios::app);
    name = a.ReturnName();
    sdt = a.ReturnPhoneNum();
    cout << " nhap email thay doi :" << endl;
    cin.ignore();
    getline(cin, email);
    CustomerDoc z(id, name, sdt, email);
    File4 << z;
    File4.close();
    cout << " thay doi email thanh cong" << endl;
    //====
}

//===================================================================================================================================================

void DanhSachKhachHang()
{
    CustomerDoc a;
    ifstream File("ThongTinKhachHang.txt", ios::in);
    cout << " nhap id de xem thong tin khach hang: " << endl;
    int id;
    cin >> id;
    while (File >> a)
    {
        if (id == a.ReturnID())
        {
            a.print();
            cout << "--------------------" << endl;
        }
    }
}
//===================================================================================================================================================

void HoaDon()
{
}
//===================================================================================================================================================
int answer;
void menu()
{

    switch (answer)
    {
    case 1:
        NhapThongTinXe();
        break;
    case 2:
        QuaTrinhThueXe();
        break;
    case 3:
        DanhSachXeChuaDuocTHue();
        break;
    case 4:
        DaThueXeNaokhong();
        break;
    case 5:
        TraXe1();
        break;
    case 6:
        ChinhSuaTen();
        break;
    case 7:
        ChinhSuaSdt();
        break;
    case 8:
        ChinhSuaEmail();
        break;
    case 9:
        DanhSachKhachHang();
        break;
    default:
        cout << "Bad choice! Exit program: \n";
        break;
    }
}
//=====================================================================================================================================================
int main()
{
    bool keepLooping = true;
    while (keepLooping)
    {

        cout << "Nhap de lua chon thao tac  " << endl;
        cout << " (1) Nhap thong tin xe" << endl;
        cout << " (2) thue xe " << endl;
        cout << " (3) Danh sach xe chua duoc thue " << endl;
        cout << " (4) Thong tin thue xe cua khach hang " << endl;
        cout << " (5) Tra xe  " << endl;
        cout << " (6)Chinh sua ten khach hang  " << endl;
        cout << " (7)Chinh sua sdt khach hang  " << endl;
        cout << " (8)Chinh sua email khach hang  " << endl;
        cout << " (9) Thong tin khach hang  " << endl;
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
