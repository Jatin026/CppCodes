#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;
bool good(ll n, ll h , ll arr[] , ll k){
    ll sum=0;
    for (int i = 0; i < n-1 ; i++)
    {
        sum+=min(arr[i+1]-arr[i],k);
    }
    sum+=k;
    return (sum>=h);
}
void solve(){
    ll n,h;
    cin>>n>>h;
    ll arr[n];
    inputarr(arr,n);
    ll l=0,r=h, mid;
    while (l+1<r)
    {
        mid=(l+r)/2;
        if(good(n,h,arr,mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<r<<"\n";
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