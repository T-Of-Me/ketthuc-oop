#include <iostream>
using namespace std;

class A
{
public:
    int a = 1;
};
class B : virtual public A
{
public:
};
class C : virtual public A
{
public:
};
class D : public B, public C
{
public:
};
int main()
{
    D h;
    cout << h.a << endl;
}
 