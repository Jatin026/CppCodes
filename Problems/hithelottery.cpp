#include<iostream>
using namespace std;
int main(){
    int n ,count=0;
    cin>>n;
    if(n>=100){
        count+=(n/100);
        n=n%100;
    }
    if(n>=20){
        count+=(n)/20;
        n=n%20;
    }
    if(n>=10){
        count+=n/10;
        n=n%10;
    }
    if(n>=1){
        count+=n/5+n%5;
 }
    cout<<count;
    return 0;
}