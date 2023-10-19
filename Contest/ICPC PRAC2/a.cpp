#include<bits/stdc++.h>
#include<chrono>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(s) s.begin(),s.end()
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define binarystring(n,x) bitset<n> (x).to_string()
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define MOD            1000000007
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
           // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
           return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const {
           static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
};
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
class Mint
{
//WARNING:
//Be very careful not to use two Mints with different mods for any operation
//No guarantee of behavior in this case
public:
ll val;
static ll mod_exp(ll a, ll b){ ll res=1;   a=a%MOD; while(b>0){ if(b%2==1) res=(res*a)%MOD; b/=2; a=(a*a)%MOD; } return res; }
static ll gcdExtended(ll a, ll b, ll *x, ll *y) { if (a == 0) { *x = 0, *y = 1; return b; } ll x1, y1; ll gcd = gcdExtended(b%a, a, &x1, &y1);*x = y1 - (b/a) * x1; *y = x1; return gcd; }
static ll modInverse(ll a) { ll x, y; 	ll g = gcdExtended(a, MOD, &x, &y); g++; ll res = (x%MOD);	if(res < 0) res += MOD;	return res;} 
Mint(){	val = 0;} 
Mint(ll x){	val = x%MOD;	if(val < 0) val += MOD;}
Mint& operator +=(const Mint &other){	val += other.val;	if(val >= MOD) val -= MOD; return (*this); }
Mint& operator -=(const Mint &other){   val -= other.val;if(val < 0) val += MOD;  return (*this); }
Mint& operator *=(const Mint &other){	val = (val * other.val)%MOD; return (*this); }
Mint& operator /=(const Mint &other){	val = (val * modInverse(other.val)) % MOD; return (*this); }
Mint& operator =(const Mint &other) { 	val = other.val; return (*this); }
Mint operator +(const Mint &other) const {	return Mint(*this) += other; }
Mint operator -(const Mint &other) const {	return Mint(*this) -= other; }
Mint operator *(const Mint &other) const {	return Mint(*this) *= other; }
Mint operator /(const Mint &other) const {	return Mint(*this) /= other; }
bool operator ==(const Mint &other) const {   return val == other.val; }
Mint operator ++() { ++val; if(val == MOD) val = 0; return (*this); }
Mint operator ++(int) { val++; if(val == MOD) val = 0; return Mint(val-1); }
Mint operator --() { --val; if(val == -1) val = MOD-1; return (*this); }
Mint operator --(int) { val--; if(val == -1) val = MOD-1; return Mint(val+1); }
// ^ has very low precedence, careful!!
template<typename T>
Mint& operator ^=(const T &other){   val = mod_exp(val, other); return (*this); }
template<typename T>
Mint operator ^(const T &other) const {  return Mint(*this) ^= other; }
Mint& operator ^=(const Mint &other){   val = mod_exp(val, other.val); return (*this); }
Mint operator ^(const Mint &other) const {  return Mint(*this) ^= other; }
template<typename T>
explicit operator T() {	return (T)val; }
template<typename T>
friend Mint operator +(T other, const Mint &M){	return Mint(other) + M; }
template<typename T>
friend Mint operator -(T other, const Mint &M){	return Mint(other) - M; }
template<typename T>
friend Mint operator *(T other, const Mint &M){	return Mint(other) * M; }
template<typename T>
friend Mint operator /(T other, const Mint &M){	return Mint(other) / M; }
template<typename T>
friend Mint operator ^(T other, const Mint &M){	return Mint(other) ^ M; }
friend std::ostream &operator << (std::ostream &output, const Mint &M){  return output << M.val; }
friend std::istream &operator >> (std::istream &input, Mint &M) { input >> M.val;	M.val %= MOD;	return input;}};




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

#define int ll 
struct SCC {
    int V = 0;
    vector<vector<int>> adj;
    vector<int> tour_index, low_link;
    int tour;
 
    vector<int> stack;
    vector<bool> in_stack;
 
    vector<vector<int>> components;
    vector<int> which_component;
 
    SCC(int v = 0) {
        init(v);
    }
 
    SCC(const vector<vector<int>> &_adj) {
        init(_adj);
    }
 
    void init(int v) {
        V = v;
        adj.assign(V, {});
    }
 
    void init(const vector<vector<int>> &_adj) {
        adj = _adj;
        V = int(adj.size());
    }
 
    void add_edge(int a, int b) {
        adj[a].push_back(b);
    }
 
    // Tarjan's algorithm.
    void dfs(int node) {
        tour_index[node] = tour++;
        low_link[node] = tour_index[node];
        stack.push_back(node);
        in_stack[node] = true;
 
        for (int neighbor : adj[node])
            if (tour_index[neighbor] < 0) {
                // neighbor is part of our subtree.
                dfs(neighbor);
                low_link[node] = min(low_link[node], low_link[neighbor]);
            } else if (in_stack[neighbor]) {
                // neighbor is a candidate for low_link.
                low_link[node] = min(low_link[node], tour_index[neighbor]);
            }
 
        if (low_link[node] == tour_index[node]) {
            // node is the highest node in an SCC, which includes everything on the stack up to it.
            components.emplace_back();
            vector<int> &component = components.back();
            int x;
 
            do {
                assert(!stack.empty());
                x = stack.back();
                stack.pop_back();
                in_stack[x] = false;
                which_component[x] = int(components.size()) - 1;
                component.push_back(x);
            } while (x != node);
        }
    }
 
    void build() {
        tour_index.assign(V, -1);
        low_link.resize(V);
        which_component.assign(V, -1);
 
        stack.clear();
        stack.reserve(V);
        in_stack.assign(V, false);
        tour = 0;
 
        // Note that Tarjan's algorithm provides the SCCs in reverse topological order.
        components = {};
 
        for (int i = 0; i < V; i++)
            if (tour_index[i] < 0)
                dfs(i);
    }
};
void solve(){
    int n,m;
    cin >> n >> m;
    vvi adj(n);
    vpr edges(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        edges[i]  = make_pair(a,b);
    }
    SCC scc(adj);
    scc.build();
    // for (int i = 0; i < n; i++)
    // {
    //     vi vis(n,0);
    //     queue<int> q;
    //     q.push(i);
    //     int tot = 0;
    //     vis[i] = 1;
    //     while(!q.empty()){
    //         int v = q.front();
    //         q.pop();
    //         for(auto u : adj[v]){
    //             if(vis[u]) continue;
    //             q.push(u);
    //             vis[u] = 1;
    //         }
    //     }
    //     for (int i = 0; i < n; i++)
    //     {
    //         tot += vis[i];
    //     }
    //     ans = max(ans , tot);
        
    // }
    vi in_degree(n);
    vvi adj_cond(n);
    for(auto x : edges){
        if(scc.which_component[x.second] == scc.which_component[x.first]) continue;
        in_degree[scc.which_component[x.second]]++;
        adj_cond[scc.which_component[x.first]].pb(scc.which_component[x.second]);
    }
    
    int fin = -1;
    debug(scc.components)
    function<void(int, vi&)> dfs = [&](int v , vi &ans){
        int val = scc.components[v].size(),score  = 0;
        for(auto u : adj_cond[v]){
            dfs(u,ans);
            score = max(score,ans[u]);
        }
        ans[v] = val + score;
        fin = max(fin , ans[v]);
    };
    for (int i = 0; i < n; i++)
    {
        vi ans(n,0);
        int s = scc.which_component[i];
        dfs(s,ans);
    }
    
    cout << fin;
}
#undef int 
int main(){
    FAST
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}