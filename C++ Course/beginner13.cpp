#include<iostream>
using namespace std;
void swapPointer(int* a, int* b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
void swaprefvar(int &a,int &b){
    int temp=b;
    b=a;
    a=temp;
}

int main(){
    int a=4,b=6;
    cout<<"The value of a is : "<<a<<"\nThe value of b is : "<<b<<endl; 
    swaprefvar(a,b);
    cout<<"The value of a is : "<<a<<"\nThe value of b is : "<<b; 
    return 0;
}