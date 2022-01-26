#include<iostream>
using namespace std; 
int fib(int n){
    if (n==0){
        return 1;
    }
    else if (n==1){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
         
    }
}
int main(){
    int n;
    cout<<"Enter the number of sequence of fibonnanci : " ;
    cin>>n;
    cout<<"The following nth term of sequence is : "<<fib(n);
    return 0;
}

