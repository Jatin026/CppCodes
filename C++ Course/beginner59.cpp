#include<iostream>
using namespace std;
template<class T>
class MyClass{
    T data;
    public:
        MyClass(T a ){
            data=a;
        }
        void display();
};
template<class T>
void MyClass<T> :: display(){
        cout<<data<<endl;
}
void func(int a){
    cout<<"FUNC 1"<<a<<endl;
}
template<class T>
void func(T a){
    cout<<"Template Function"<<a<<endl;
}
int main(){
    // MyClass<float> c(5.32);
    // c.display();
    func(7);//Exact match takes the higher priority.
    func(7.77);
    return 0;
}
