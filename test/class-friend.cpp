#include <iostream>
using namespace std;

class B
{
private:
    int b;

public:
    B()
    {
        b = 10;
    }

    friend class A;
};

class A
{
public:
    void print(B arg)
    {
        cout << arg.b;
    }
};

int main()
{
    B b;
    A a;
    a.print(b);
    return 0;
}