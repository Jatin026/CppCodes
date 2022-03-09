#include<bits/stdc++.h>
using namespace std;
int power(int x , int n){
   return  pow(x,n);
}

int main(){
    int s,t,i=1;
    cin>>s>>t;
    while(pow(s,i)<t){
        i++;
    }
    cout<<i-1;
    return 0;
}