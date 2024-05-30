#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <cstring>

class HoGiaDinh
{
private:
    string Ten; // const 
    int SoNha; // const  
    int MaCongToDien; // const 

public:
    HoGiaDinh(){};
    ~HoGiaDinh(){};
    int ReturnMaCong() { return MaCongToDien; };
};

//==================================================================================================================

class BienLai
{
private:
    HoGiaDinh HOGIADINH;
    int ChiSoDienCu;
    int ChiSoDienMoi;

public:
    BienLai(){};
    ~BienLai(){};
    int SoTienPhaiTra()
    {

        return ChiSoDienMoi * 1000;
    };
};

//==================================================================================================================

class DanhSachBienLai
{
private:
    BienLai b;

public:
    DanhSachBienLai(){};
    ~DanhSachBienLai(){};
    void ThemBienLai() {};
    void HienThiDanhSachBienLai() {}; // theo ten hoac ma cong to dien 
    void TimKiemBienLai() {};
    void TongTienTatCaBienLai() {};
};

//====================================================================================================================

int check;
//=====================================================================================================================

void menu()
{
    switch (check)
    {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

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
        cout << "***  ELECTRICITY  ***" << endl;
        cout << " 1  " << endl;
        cout << " 2  " << endl;
        cout << " 3  " << endl;
        cout << " 4  " << endl;
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