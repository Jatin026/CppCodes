#include<iostream>
using namespace std;
// concept of Pointers in C++
int main(){
    int a=3;
    int* b=&a;
    cout<<"The address of a is : "<<b<<endl;
    cout<<"The value at a is : "<<*b<<endl;
    cout<<"The value at a is : "<<*&a;
    return 0;
}
