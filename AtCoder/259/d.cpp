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
struct v{
    ll x,y,r;
    bool intersection(v u){
       return ((x-u.x)*(x-u.x)+(y-u.y)*(y-u.y)<=(r+u.r)*(r+u.r) & (x-u.x)*(x-u.x)+(y-u.y)*(y-u.y)>=(r-u.r)*(r-u.r)); 
    }
};
void dfs(int vertex , vi &vis , vvi &adj){
    vis[vertex]=1;
    for(auto child : adj[vertex]){
        if(vis[child]) continue;
        dfs(child,vis,adj);
    }
}
void solve(){
    ll n,si,sj,fi,fj;
    cin>>n>>si>>sj>>fi>>fj;
    vector<v> vertices(n);
    vll starting , finish;
    for (int i = 0; i < n; i++)
    {
        v vertice;
        cin>>vertice.x>>vertice.y>>vertice.r;
        vertices[i]=vertice;
        if((si-vertice.x)*(si-vertice.x)+(sj-vertice.y)*(sj-vertice.y)==(vertice.r)*(vertice.r)) starting.pb(i+1);
        if((fi-vertice.x)*(fi-vertice.x)+(fj-vertice.y)*(fj-vertice.y)==(vertice.r)*(vertice.r)) finish.pb(i+1);
    }
    vvi adj(n+1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i!=j){
                if(vertices[i].intersection(vertices[j])){
                    adj[i+1].pb(j+1);
                    adj[j+1].pb(i+1);
                }
            }
        }  
    }
 
    vi vis(n+1,0);
    for(auto x : starting){
        dfs(x,vis,adj);
    }
    for(auto x : finish){
        if(vis[x]){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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