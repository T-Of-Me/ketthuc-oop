#include <iostream>
using namespace std;

class MyClass {
public:
    int value;

    // Hàm khởi tạo sao chép
    MyClass(const MyClass& source) {
        value = source.value + 100;
    }

    // Hàm khởi tạo thông thường
    MyClass(int val) {
        value = val;
    }
};

int main() {
    MyClass obj1(100);
    MyClass obj2 = obj1; // Gọi hàm khởi tạo sao chép

    cout << "Giá trị của obj2: " << obj2.value << endl;

    return 0;
}
