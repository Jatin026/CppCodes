#include<iostream>
using namespace std;
int main(){
    int a=7;
    float b=7.89f;
    int & y=a;


    cout<<"This is an illustration of TYPECASTING : "<<a+b<<endl;
    cout<<"This is an illustration of TYPECASTING : "<<a+int(b)<<endl;
    cout<<"This is an illustration of TYPECASTING : "<<a+(int)b<<endl;
    cout<<"This is an illustration of TYPECASTING : "<<a+float(b)<<endl;
    cout<<y;
    return 0;
}
