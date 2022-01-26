#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%2==1){
        cout<<0;
        exit(0);
    }
    cout<<(1LL<<n/2);
    return 0;
}