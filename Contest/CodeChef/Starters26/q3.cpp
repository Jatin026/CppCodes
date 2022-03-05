#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
using namespace std;

ll BinExpItr(int a , int b){
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
    int n,x,y,ans=INT_MAX;
    cin>>n>>x>>y;
    for (int b = 0; b <= ceil(n*1.0/100); b++)
    {
        for (int c = 0; c <= ceil(n*1.0/4); c++)
    {
        // cout<<c<<" chala \n";
        if(b*100+c*4>=n) ans=min(ans,(b*x+c*y));
    }
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