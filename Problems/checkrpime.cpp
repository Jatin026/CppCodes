#include<iostream>
using namespace std;

int main(){
    int a;
    cout<<"enter the number \n";
    cin>>a;

    for(int b=2; b<a ; b++)
    {
       if( a%b == 0) {
        cout<< " the number is not prime \n"; 
        exit(0);
       }
    }
    cout<<"The number is prime";
    return 0;
}