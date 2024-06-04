#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Display()
    {
        cout << "class Base" << endl;
    }
};

class Derived : public Base
{
public:
    void Display()
    {
        cout << "class Derived" << endl;
    }
};

void Show(Base *B)
{
    B->Display();
}

int main()
{
    Base *B = new Base;
    Derived *D = new Derived;
    B->Display(); // Base::Display()
    D->Display(); // Derived::Display()
    Show(B);      // Base::Display()
    Show(D);      // Derived::Display()
    return 0;
}



