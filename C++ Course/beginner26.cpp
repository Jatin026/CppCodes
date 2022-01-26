#include <iostream>
using namespace std;
class Complex
{
    int a, b;

public:
    Complex(void);
    void getinfo()
    {
        cout << "The complex number are : " << a << "+" << b << "i" << endl;
    }
};
Complex ::Complex(void)
{ // it is used to initialize the object.
    //-->Default Constructor as it takes no value.
    //Constructor is a special member of the class , its name is same as that of a class.
    a = 0;
    b = 0;
}
int main()
{
    Complex c;
    c.getinfo();
    return 0;
}
/* Properties of Construtors
1.It Should be declared in the public section of the class
2.They are automatically invoked whenever a new object is created.
3.They cannot return values and does not have return type.
4.It can have default arguments.
5.We cannot refer to their address.*/