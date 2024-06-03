#include <iostream>

// Khai báo lớp trừu tượng "DongVat"
class DongVat
{
public:
    // Phương thức trừu tượng "AnUong"
    virtual void AnUong() = 0;

    // Phương thức trừu tượng "DiChuyen"
    virtual void DiChuyen() = 0;
};

// Lớp "ConNguoi" kế thừa từ lớp "DongVat"
class ConNguoi : public DongVat
{
public:
    // Ghi đè phương thức "AnUong"
    void AnUong()
    {
        std::cout << "Con người có thể ăn uống!" << std::endl;
    }

    // Ghi đè phương thức "DiChuyen"
    void DiChuyen()
    {
        std::cout << "Con người có thể di chuyển!" << std::endl;
    }
};

int main()
{
    // Tạo đối tượng từ lớp "ConNguoi"
    ConNguoi nguoi;
    nguoi.AnUong();   // Kết quả: "Con người có thể ăn uống!"
    nguoi.DiChuyen(); // Kết quả: "Con người có thể di chuyển!"

    return 0;
}
