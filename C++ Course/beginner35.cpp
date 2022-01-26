#include<iostream>
using namespace std;
class Employee{
    public:
        int id;
        int salary=10000;
        Employee(){}
        Employee(int a){
            id=a;
        }
};
class WhiteHat : private Employee{
    public:
        WhiteHat(int a){
            id=a;
        }
        void display(){
            cout<<id;
        }
};
int main(){ 
    Employee Ramesh(1);
    cout<<Ramesh.id<<endl;
    cout<<Ramesh.salary<<endl;
    WhiteHat Harry(1);
    Harry.display();
    return 0;    
}