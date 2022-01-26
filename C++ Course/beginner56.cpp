#include<iostream>
using namespace std;
template<class T1,class T2>
class MyClass{
    T1 data1;
    T2 data2;
    public:
        MyClass(T1 a , T2 b){
            data1=a;
            data2=b;
        }
        void display(){
            cout<<data1<<endl<<data2;
        }
};
int main(){
    MyClass<int ,string > student(1,"Aa");
    student.display();
    return 0;
}