#include<iostream>
using namespace std;
class Base1{
    protected:
        int data1;
    public:
        void set_data1(int a){
            data1=a;
        }
};
class Base2{
    protected:
        int data2;
    public:
        void set_data2(int a){
            data2=a;
        }
};
class Base3{
    protected:
        int data3;
    public:
       void set_data3(int a){
            data3=a;
        }
};
class Derived : public Base1, public Base2,public Base3{
    protected:
        int data4;
    public:
        void display(){
            cout<<"The value of data1 is : "<<data1<<endl;
            cout<<"The value of data2 is : "<<data2<<endl;
            cout<<"The value of data3 is : "<<data3<<endl;
            data4=data1*data2*data3;
            cout<<"The value of data4 is : "<<data4<<endl;
        }
};
int main(){
    Derived d;
    d.set_data1(7);
    d.set_data2(5);
    d.set_data3(3);
    d.display();
    return 0;
}