#include <iostream>
using namespace std;
class Complex
{
    int a;
    int b;
//*********Constructor Overloading**************
public:
    Complex(int x, int y)
    {
        a = x;
        b = y;
    }
    Complex(int x){
        a=x;
        b=0;
    }
    Complex(){
        a=0;
        b=0;
    }
    void getinfo()
    {
        cout << "The complex number are : " << a << "+" << b << "i" << endl;
    }
}; 
int main()
{
    Complex c(3,5);
    c.getinfo();
    Complex d(7);
    d.getinfo();
    Complex e;
    e.getinfo();
    return 0;
}