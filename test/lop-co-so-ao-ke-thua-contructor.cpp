#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base constructor called." << endl;
    }
};

class Derived1 : virtual public Base
{
public:
    Derived1()
    {
        cout << "Derived1 constructor called." << endl;
    }
};

class Derived2 : virtual public Base
{
public:
    Derived2()
    {
        cout << "Derived2 constructor called." << endl;
    }
};

class FinalDerived : public Derived1, public Derived2
{
public:
    FinalDerived()
    {
        cout << "FinalDerived constructor called." << endl;
    }
};

int main()
{
    FinalDerived obj;
    return 0;
}