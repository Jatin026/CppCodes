#include<iostream>
using namespace std;
int sum(int,int);//Example of Prototype function
void g(void);
int main(){
    int num1,num2;
    cout<<"Enter Num1  : ";
    cin>>num1;
    cout<<"Enter Num2  : ";
    cin>>num2;//num1 and num2 are actual parameters
    cout<<"Their sum is : "<<sum(num1,num2);
    g();
    return 0;
}
int sum(int a,int b){
    int c;//a and b are formal parameters
    c=a+b;
    return c;
}
void g(){
    cout<<"\nThank you for using the program.";
}