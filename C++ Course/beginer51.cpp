#include<iostream>
using namespace std;
class Base{
    public:
        int var_base_class=100;
        virtual void display(){
            cout<<"The value of base class variable is : "<<var_base_class<<endl;
        }
    
};
class Derived : public Base {
    public:
        int var_Derived_class=50;
        void display(){
            cout<<"The value of base class variable is : "<<var_base_class<<endl;
            cout<<"The value of Derived class variable is : "<<var_Derived_class<<endl;
            }
};
int main(){
    Base * base_class_pointer= new Derived;
    base_class_pointer->display();
    return 0;
}     