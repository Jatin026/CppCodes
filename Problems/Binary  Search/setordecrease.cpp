#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    ll n,k,count=0,sum=0;
    cin>>n>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    sortarr(arr);
    for (int i = n-1; i > 0; --i)
    {
        if(sum<=k) break;
        if(arr[i]!=arr[0]) {
        // cout<<sum<<"   "<<i<<"\n";
        sum-=arr[i];
        sum+=arr[0];    
        count++;
    }
    }
    if(sum<=k) cout<<count<<'\n';
    else{
        cout<<sum-k+count<<'\n';
    }

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