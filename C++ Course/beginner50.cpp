#include<iostream>
using namespace std;
class Base{
    public:
        int var_base_class;
        void display(){
            cout<<"The value of base class variable is : "<<var_base_class<<endl;
        }
    
};
class Derived : public Base {
    public:
        int var_Derived_class;
        void display(){
            cout<<"The value of base class variable is : "<<var_base_class<<endl;
            cout<<"The value of Derived class variable is : "<<var_Derived_class<<endl;
            }
};
int main(){
    Derived *derived_class_pointer= new Derived;
    derived_class_pointer->var_Derived_class=45;
    derived_class_pointer->var_base_class=500;
    derived_class_pointer->display();
    return 0;
}