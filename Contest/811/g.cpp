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
vvi adj;
vi vis,red,blue,ans;
vll prefA,prefB;
void dfs2(int vertex){
    vis[vertex]=1;
    for(auto child : adj[vertex]){
        if(!vis[child]){
            prefA[child]=prefA[vertex]+red[child-2];
            prefB[child]=prefB[vertex]+blue[child-2];
            dfs2(child);
        }
    }
}
void dfs(int v){
    vis[v]=1;
    for(auto u : adj[v]){
        if(!vis[u]){
            if(prefA[u]<prefB[u]){
                ans[u]=ans[v]+1;
            }
            else{
                ans[u]=ans[v];
            }
            dfs(u);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    red.clear();
    blue.clear();
    adj.clear();
    vis.clear();
    ans.clear();
 
    prefA.clear();
    prefB.clear();
    red.resize(n-1);
    blue.resize(n-1);
    prefA.resize(n+1,0);
    prefB.resize(n+1,0);
    adj.resize(n+1);
    vis.resize(n+1);
    ans.resize(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int a;
        cin>>a>>blue[i]>>red[i];
        adj[i+2].pb(a);
        adj[a].pb(i+2);
    }
    dfs2(1);
    debug(prefA)
    fill(all(vis),0);
    dfs(1);
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i+1]<<' ';
    }
    cout<<nline;

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