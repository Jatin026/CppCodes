#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool good(ll x , ll n){
    return ((x*x+x*x*x)>=n);
}
ll binary(ll n){
    ll l=0,r=n,ans;
    while (l+1<r)
    {
        ll mid=(l+r)/2;
        if(good(mid,n)){
            ans=mid;
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return ans;
}
int main(){
    
    return 0;
}