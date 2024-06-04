#include <iostream>
using namespace std;

class MyNumber {
private:
    int value;

public:
    MyNumber(int val) : value(val) {}

    // Nạp chồng toán tử ++ (tiền tố)
    MyNumber operator++() {
        value++;
        return *this;
    }

    // Nạp chồng toán tử ++ (hậu tố)
    MyNumber operator++(int) {
        MyNumber temp = *this;
        value++;
        return temp;
    }

    int getValue() {
        return value;
    }
};

int main() {
    MyNumber num(5);

    // Sử dụng toán tử ++
    cout << "Giá trị ban đầu: " << num.getValue() << endl;
    MyNumber  a = num++;
    cout << "Sau hậu tố ++: " << num.getValue() << endl;
    cout << "Giá trị trả về từ hậu tố ++: " << a.getValue() << endl;

    MyNumber preIncrement = ++num;
    cout << "Sau tiền tố ++: " << num.getValue() << endl;
    cout << "Giá trị trả về từ tiền tố ++: " << preIncrement.getValue() << endl;

    return 0;
}
