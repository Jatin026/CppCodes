#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%10==0&& n<=10) cout<<n/5;
    else{
        cout<<2*(n/10)+1;
    }
    return 0;
}