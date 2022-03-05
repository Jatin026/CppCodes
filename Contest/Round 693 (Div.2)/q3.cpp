#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;
const int N= 2e5+7;
int val[N];
ll sum(int i , int arr[], int n){
    if(i>=n) return 0 ;
    if(val[i]!=-1) return val[i];//memoisation
    return val[i]=(arr[i]+sum(i+arr[i],arr,n));
}
void solve(){
    int n;
    cin>>n;
    int arr[n];
    memset(val,-1,sizeof(val));
    inputarr(arr,n);
    ll ans=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans=max(ans,sum(i,arr,n));
    }
    cout<<ans<<"\n";
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