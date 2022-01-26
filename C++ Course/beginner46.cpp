#include<iostream>
using namespace std;

int main(){
    int a;
    a=70;
    int* p=&a;
    cout<<"The value of a is : "<<*p<<endl;
    int* ptr=new int(50);
    cout<<"The value at address  ptr is : "<<*ptr<<endl;
    int* arr=new int [3];
    arr[0]=1;
    *(arr+1)=2;
    arr[2]=3;
    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;
    cout<<arr[2]<<endl;
    return 0;
}




 