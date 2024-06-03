#include <iostream>
using namespace std;

class MyClass
{
private:
    static double a;

public:
    static void set(int x) { a = x; };
    static void show() { cout << a; };
};

double MyClass::a = 0;

int main()
{
    MyClass::set(10);
   MyClass::show();
}