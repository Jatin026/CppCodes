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
    string s,x;
    cin>>s>>x;
    map<char,int> m;
    int ans=0;
    for (int i = 0; i < 26; i++)
    {
        m[s[i]]=i+1;
    }
    for (int i = 0; i < x.size()-1; i++)
    {
        ans+=abs(m[x[i]]-m[x[i+1]]);
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