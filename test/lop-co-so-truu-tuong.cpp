#include <iostream>
using namespace std;
// Khai báo lớp trừu tượng "HinhHoc"
class HinhHoc
{
public:
    // Phương thức trừu tượng "TinhDienTich"
    virtual double TinhDienTich() = 0;

    // Phương thức trừu tượng "TinhChuVi"
    virtual double TinhChuVi() = 0;
};

// Lớp "HinhTron" kế thừa từ lớp "HinhHoc"
class HinhTron : public HinhHoc
{
private:
    double banKinh;

public:
    HinhTron(double r) : banKinh(r) {}

    // Ghi đè phương thức "TinhDienTich"
    double TinhDienTich()
    {
        return 3.14 * banKinh * banKinh;
    }

    // Ghi đè phương thức "TinhChuVi"
    double TinhChuVi()
    {
        return 2 * 3.14 * banKinh;
    }
};

// Lớp "HinhChuNhat" kế thừa từ lớp "HinhHoc"
class HinhChuNhat : public HinhHoc
{
private:
    double chieuDai;
    double chieuRong;

public:
    HinhChuNhat(double dai, double rong) : chieuDai(dai), chieuRong(rong) {}

    // Ghi đè phương thức "TinhDienTich"
    double TinhDienTich()
    {
        return chieuDai * chieuRong;
    }

    // Ghi đè phương thức "TinhChuVi"
    double TinhChuVi()
    {
        return 2 * (chieuDai + chieuRong);
    }
};

int main()
{
    // Tạo đối tượng từ lớp "HinhTron"
    HinhTron hinhTron(5.0);
    cout << "Diện tích hình tròn: " << hinhTron.TinhDienTich() << endl;
    cout << "Chu vi hình tròn: " << hinhTron.TinhChuVi() << endl;

    // Tạo đối tượng từ lớp "HinhChuNhat"
    HinhChuNhat hinhChuNhat(4.0, 6.0);
    cout << "Diện tích hình chữ nhật: " << hinhChuNhat.TinhDienTich() << endl;
    cout << "Chu vi hình chữ nhật: " << hinhChuNhat.TinhChuVi() << endl;

    return 0;
}
