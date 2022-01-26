#include <iostream>
using namespace std;
class Base
{
    int data1;
public:
    int data2;
    void setdata();
    int getdata();
};
void Base::setdata()
{
    data1 = 10;
    data2 = 20;
}
int Base ::getdata()
{
    return (data1);
}
class Derived : Base//Default Inheritance is private
{
    int data3;

public:
    void process()
    {
        setdata();//The function is mandatory to call here as it is a private member of the derived class.
        data3 = data2 * getdata();
    }
    void display()
    {
        cout << "The value of data1  is " << getdata()<<endl;
        cout << "The value of data2  is " << data2<<endl;
        cout << "The value of data3  is " << data3<<endl;
    }
};

int main()
{
    Derived d;
    d.process();
    d.display();
    return 0;
}