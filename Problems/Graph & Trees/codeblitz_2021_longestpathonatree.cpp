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
template <class T, class V> void _print(pair <T, V> p) {cerr << '{'; _print(p.first); cerr << ','; _print(p.second); cerr << '}';}
template <class T> void _print(vector <T> v) {cerr << '['; for (T i : v) {_print(i); cerr << ' ';} cerr << ']';}
template <class T> void _print(set <T> v) {cerr << '['; for (T i : v) {_print(i); cerr << ' ';} cerr << ']';}
template <class T> void _print(multiset <T> v) {cerr << '['; for (T i : v) {_print(i); cerr << ' ';} cerr << ']';}
template <class T, class V> void _print(map <T, V> v) {cerr << '['; for (auto i : v) {_print(i); cerr << ' ';} cerr << ']';}
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
 
pr dfs(int vertex , vector <vi> &v , vi &vis , vi &subc){ 
    vis[vertex]=1;
    pr p = {1,1};
    for(auto child : v[vertex]){
        if(vis[child] ) continue;
        subc[child]=subc[vertex]+1;   
        if(p.second<subc[child]){
            p={child,subc[child]};
        }
        pr x  = dfs(child,v,vis,subc);
        if(x.second>p.second){
            p=x;
        }
    } 
    return (p); 
}
void solve(){
    int n;
    cin>>n;
 
    vector<vi> v(n+1);
    vi vis(n+1,0),subc(n+1,1),vis2(n+1,0),subc2(n+1,1);
    subc[0]=0;
    vi l(n-1),r(n-1);
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        l[i]=a;
        r[i]=b;
    }
    string s;
    cin>>s;
    for (int i = 0; i < n-1; i++)
    {
        if(s[l[i]-1]==s[r[i]-1]){
            v[l[i]].pb(r[i]);
            v[r[i]].pb(l[i]);
        }
    }
    int ans=1;
    for (int i = 1; i < n; i++)
    {
        if(vis[i]) continue;
        else{
            
            pr p = dfs(i,v,vis,subc);
            pr x= dfs(p.first,v,vis2,subc2);
            ans=max(ans,x.second);
        }
    }
 
    cout<<ans<<nline;
    //cout<<dfs2(1,v,vis,subc)<<nline;
}
int main(){
    FAST
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}