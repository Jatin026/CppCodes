#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(s) s.begin(),s.end()
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define binarystring(n,x) bitset<n> (x).to_string()
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define pb             push_back
#define lb             lower_bound
#define ub             upper_bound
#define mk             make_pair
#define deci(x, y)     fixed<<setprecision(y)<<x
#define PI             3.141592653589793238
#define mem0(x)        memset(x,0,sizeof x)
#define mem1(x)        memset(x,-1,sizeof x)
#define pr             pair<int,int>
#define vi             vector<int>
#define vll            vector<ll>
#define vvi            vector<vi>
#define vpr            vector<pr> 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
using namespace std;

#define nline '\n'
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
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
ll BinExpItr(ll a , ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
void solve(){
    
    int n,q;
    cin>>n>>q;
    //Method 1->
    // vvi bits(32,vi(n+1,0));
    // vi v(n);
    // for(auto &x : v){
    //     cin>>x;   
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < 32; j++)
    //     {
    //         bits[j][i]=bits[j][i-1]+(int)((v[i-1]>>j)&1);
    //     }
    // }
    // while(q--){
    //     int a,b ;
    //     cin>>a>>b ;
    //     int ans=0;
    //     for (int i = 0; i < 32; i++)
    //     {
    //         ans+=((bits[i][b]-bits[i][a-1])%2)*(1<<i);
    //     }
    //     cout<<ans<<nline;
    // }
    //Method 2->
    vi prefix(n+1,0);
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        prefix[i+1]=(prefix[i]^ele);
    }
    while(q--){
        int a,b ;
        cin>>a>>b ;
        cout<<(prefix[b]^prefix[a-1])<<nline;
    }
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