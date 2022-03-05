#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<' '; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
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
    int arr[n],pref[n+1]={0};
    vector<int> max_sub(n+1,INT_MIN);
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i-1];
        pref[i]=arr[i-1]+pref[i-1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            max_sub[j-i]=max(pref[j]-pref[i],max_sub[j-i]);
        }
    }
    for (int i = 0; i <= n; i++)
    {
        int ans=INT_MIN;
        for (int j = 0; j <= n; j++)
        {
            ans=max(ans,max_sub[j]+min(i,j)*k);  //  
        }
        cout<<ans<<" ";
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