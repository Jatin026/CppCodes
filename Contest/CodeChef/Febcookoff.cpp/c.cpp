#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
using namespace std;

ll BinExpItr(ll a , ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[k];
    int ans[n];
    inputarr(arr,k);
    sortarr(arr);
    for (int i = 1; i <=n; i++)
    {
        ans[i-1]=i;
    }
    for (int i = 0; i < k; i++)
    {
        if(i==0) reverse(ans,ans+arr[i]);
        if(i>0){
            reverse(ans+(arr[i-1]),ans+min(arr[i],n));
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    cout<<"\n";
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