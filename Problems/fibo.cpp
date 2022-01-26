#include<iostream>
using namespace std;
int fibo(int n){
    if(n==1){
        return 0;
    }
    else if(n==2)
        return 1;
    else
        return(fibo(n-2)+fibo(n-1));
}

int main(){
    int n,a=0,b=1,c;
    cin>>n;
    cout<<fibo(n)<<endl;
    while (n-->2)
    {
        c=a+b;
        a=b;
        b=c;
    }
    cout<<c;
    return 0;
}