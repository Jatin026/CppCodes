#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
using namespace std;

void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    ll l=0 , r=2e9;
    while(l<=r){
        ll mid=(l+r)/2;
        if(mid-mid/n>k){
            r=mid-1;
        }
        else if(mid-mid/n<k){
            l=mid+1;
        }
        else{
            ans=mid;
            r=mid-1;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}