#include<iostream>
using namespace std;
int main(){
    int a=4 ,b=8;
    cout<<"This Program is for the illustration of different types of operator  in C++"<<endl;
    cout<<"The value of a++ : "<<a++;
    cout<<"\nThe value of ++a : "<<++a;
    cout<<"\n \nThis Program is for the illustration of different types of Logical operator  in C++"<<endl;
    cout<<"\nThis will show whether a==b : "<<(a==b);
    cout<<"\nThis will show whether a<=b : "<<(a<=b);
    cout<<"\nThis will show whether a>=b : "<<(a>=b);
    cout<<"\nThis will show whether a!=b : "<<(a!=b);
    cout<<"\nThis will show whether a<=b && a==b : "<<((a>=b)&&(a==b));
    cout<<"\nThis will show whether a>=b || a==b : "<<((a>=b)||(a==b));
    return 0;
}