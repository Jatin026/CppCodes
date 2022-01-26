#include<bits/stdc++.h>
using namespace std;
int sumof(int n){
    int ans=0;
    if(n<10) return n;
    ans+=n%10+sumof(n/10);
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<sumof(n);
    return 0;
}