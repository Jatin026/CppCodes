#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    ll n,s;
    cin>>n>>s;
    ll arr[n+1]={0};
    for (int i = 1; i <=n ; i++)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    ll r=1 , ans=0;
    for (int l = 1; l <= n ; l++)
    {
        while(arr[r]-arr[l-1]<s && r<=n){
            r++;
        }
        if(arr[r]-arr[l-1]>=s && r<=n) {
            ans+=n-r+1 ;
        }
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