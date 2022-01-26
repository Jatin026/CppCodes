#include <iostream>
using namespace std;
class Simple
{
    int a;
    int b;
    //Default Arguments in Constructor.Default arguments cant be used in constructor overloading.
public:
    Simple(int x, int y = 9)
    {
        a = x;
        b = y;
    }
    // Simple (int x){ Error will pop up because it is ambiguous
    //     a=x;
    //     b=0;
    // }
    void getdata()
    {
        cout << "The value of data is " << a << ',' << b;
    }
};
int main()
{
    Simple c(1);
    c.getdata();
    return 0;
}