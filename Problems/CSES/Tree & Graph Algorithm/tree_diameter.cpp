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
 
void dfs(int vertex , vector <vi> &v , vi &vis , vi &subc,string s){ 
    vis[vertex]=1;
    for(auto child : v[vertex]){
        if(vis[child] ) continue;
        if( s[vertex-1]==s[child-1]) subc[child]=subc[vertex]+1;   
        dfs(child,v,vis,subc,s);
     
    }
    
}
void solve(){
    int n;
    cin>>n;
 
    vector<vi> v(n+1);
    vi vis(n+1,0),subc(n+1,1);
    subc[0]=0;
    vi l(n-1),r(n-1);
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    string s;
    cin>>s;
    dfs(1,v,vis,subc,s);
    fill(all(vis),0);
    debug(subc)
    int h=0,node=-1,node2=1,h2=0;
    for (int i = 0; i < n+1; i++)
    {
        if(h<subc[i]){
            h=subc[i];
            node=i;
        }
    }
    for (int i = 0; i < n+1; i++)
    {
        if(subc[i]<h){
            if(subc[i]>h2){
                h2=subc[i];
            }
        }
    }
    vi he;
    for (int i = 0; i < n+1; i++)
    {
        if(subc[i]>=h2){
            he.pb(i+1);
        }
    }
    
    h=0;
    fill(all(subc),1);
    dfs(node,v,vis,subc,s);
    for (int i = 0; i < n+1; i++)
    {
        h=max(h,subc[i]);
    }
    debug(he)
    for (int j = 0; j < min((int)he.size(),6); j++)
    {
    debug(subc)
    fill(all(subc),1);
    fill(all(vis),0);
    dfs(he[j],v,vis,subc,s);
    for (int i = 0; i < n+1; i++)
    {
        h=max(h,subc[i]);
    }
    }
    cout<<h<<nline;
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