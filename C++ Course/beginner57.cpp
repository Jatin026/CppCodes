#include<iostream>
using namespace std;
template<class T1=int , class T2=float>//Example of Default Data type in Template.
class MyClass{
    T1 a;
    T2 b;
    public:
        MyClass(T1 x , T2 y){
            a=x;
            b=y;
        }
        void display(){
            cout<<a<<endl<<b<<endl;
        }
}; 
int main(){
    MyClass <> obj1(3,6.3);
    obj1.display();
    MyClass <char,string> obj2 ('d',"Hello Welcome");
    obj2.display();
    return 0;
}