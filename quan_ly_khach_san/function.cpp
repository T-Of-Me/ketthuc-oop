#include"header.h"
void TongTienThuNhap()
{

    int tong = 0;
    int x;
    cout << " tong so tien thu duoc ";
    ifstream file;
    file.open("thunhap.txt");
    while (file >> x)
    {
        tong += x;
    }
    cout << tong << endl;
    file.close();
}



