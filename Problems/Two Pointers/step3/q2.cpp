#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;
long long sum(ll x){
    return (x*(x+1)/2);
}
void solve(){
    ll n,s;
    cin>>n>>s;
    ll arr[n+1]={0};
    for (int i = 1; i <=n ; i++)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    ll l=1 , ans=0;
    for (int r = 1; r <= n ; r++)
    {
        while(arr[r]-arr[l-1]>s){
            l++;
        }
        ans+=sum(r-l+1);
    }
    cout<<ans;
}
int main(){
    FAST
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}