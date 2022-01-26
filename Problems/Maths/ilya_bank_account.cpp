#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n>=0) cout<<n;
    else cout<<max((n-n%10)/10, ((n-n%100)/10)+n%10);
    return 0;
}