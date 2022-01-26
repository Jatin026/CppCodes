#include<iostream>
using namespace std;
class Base1{
    int data1;
    public:
        Base1(int x){
            data1=x;
            cout<<"The Base1 Constructor is called "<<endl;
        }
        void display(){
            cout<<"The value of data1 is : "<<data1<<endl;
        }
};
class Base2{
    int data2;
    public:
        Base2(int y){
            data2=y;
            cout<<"The Base2 Constructor is called "<<endl;
        }
        void display(){
            cout<<"The value of data2 is : "<<data2<<endl;
        }
};
class Derived : public Base2 , public Base1{
    int der1,der2;
    public:
        Derived(int d1,int d2,int x,int y):Base2(y),Base1(x){
            der1=d1;
            der2=d2;
            cout<<"The Derived Constructor is called "<<endl;
        }
        void display(){
            Base1::display();
            Base2::display();
            cout<<"The value of derived1 is : "<<der1<<endl;
            cout<<"The value of derived2 is : "<<der2<<endl;
        }

};
int main(){
    Derived der(6,7,8,9);
    der.display();
    return 0;
}