#include<iostream>
using namespace std;
int binary_check(int[],int );
int main(){
    int n,k;
    cin>>n>>k;
    k=240-k;     
    for(int i=1;i<=n;i++){
        if((5*(i)*(i+1)/2)>k){
            cout<<i-1;
            exit(0);
        }
    }
    cout<<n;
    return 0;
}
 