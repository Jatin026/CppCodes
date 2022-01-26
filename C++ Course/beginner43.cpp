#include<iostream>
using namespace std;
class A{
    public:
        void greet(){
            cout<<"Hello"<<endl;
        }
};
class B{
    public:
        void greet(){
            cout<<"Namaste"<<endl;
        }
        void say(){
            cout<<"Example of preference and overwriting"<<endl;
        }
};
class C: public B ,public A{
    public:
    //It overwrites the above function say.
        void greet(){
            A::greet();
            B::greet();//Ambiguous Resolving
        };
        void say(){
            cout<<"Example of preference and overwriting, use of say of C"<<endl;
        }
};
int main(){
    C c;
    c.greet();
    B b;
    b.say();
    c.say();
    return 0;
}