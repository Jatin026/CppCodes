#include<iostream>
using namespace std;
bool chk_prime(int n){
    for(int b=2; b<n ; b++)
    {
       if( n%b == 0) {
        return 0;
       }
    }
    return 1;
}
int main(){
    int n,maxv=0 ;
    cin>>n;
    while(n>100){
        int k=n%1000;
        if(chk_prime(k)==1){
            maxv=maxv>k ? maxv : k;
        }
        n=n/10;
    }
    cout<<maxv;
    return 0;
}