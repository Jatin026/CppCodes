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
            res=(res*a);
        }
        a=(a*a);
        b>>=1;
    }
    return res;
}
void solve(){
    ll a,b,ans=0;
    cin>>a>>b;
    if(max(a,b)%2==0){
        ans+=abs(b-max(a,b))+abs(a-1);
    }
    else{
       ans+=abs(a-max(a,b))+abs(b-1); 
    }
    cout<<(ans+BinExpItr(max(a,b)-1,2)+1LL)<<"\n";
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