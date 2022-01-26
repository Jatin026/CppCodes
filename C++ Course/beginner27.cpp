#include <iostream>
using namespace std;
class Complex
{
    int a, b;

public:
    Complex(int , int );
    void getinfo()
    {
        cout << "The complex number are : " << a << "+" << b << "i" << endl;
    }
};
Complex ::Complex(int x,int y)//This is a parameterized constructor as it takes two parameters.
{
    a = x;
    b = y;
}
int main()
{
    Complex c(3,5);//Implicit Call
    c.getinfo();
    Complex d=Complex(6,10);//Explicit Call
    d.getinfo();
    return 0;
}