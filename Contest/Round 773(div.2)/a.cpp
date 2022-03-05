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
    int cnt=0;
    int x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(y1==y2){
        if(((y3>y2) && y2<0) || (y2>0 && (y3<y2) )) cnt=abs(x2-x1);
    }
    if(y2==y3){
        if(((y1>y2) && y2<0) || (y2>0 && (y1<y2) )) cnt=abs(x2-x3);
    }
    if(y1==y3){
        if(((y2>y1) && y1<0) || (y1>0 && (y2<y1) )) cnt=abs(x1-x3);
    }
    cout<<cnt<<"\n";
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