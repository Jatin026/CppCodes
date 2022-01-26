#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long int n,k;
    cin>>n>>k;
    if(n%2==0){
        if(n/2>=k){
            cout<<2*k-1;
        }
        else{
            cout<<2*(k-n/2);
        }
    }
    else{
        if(n/2+1>=k){
            cout<<2*k-1;
        }
        else{
            cout<<2*(k-n/2-1);
        }
    }
    return 0;
}