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
struct LCA{
    const int K = 18;
    vvi adj;
    vi par , depth;
    vector<vector<int>> bl;
    LCA(int n){
        adj.resize(n);
        par.resize(n);
        depth.resize(n , 0);
        bl.resize(K , vector<int> (n , 0));
    }
    void add_edge(int a , int b){
        adj[a].pb(b);
        adj[b].pb(a);
    }
    void dfs(int v , int p){
        par[v] = p;
        for(auto u : adj[v]){
            if(u == p) continue;
            depth[u] = 1 + depth[v];
            dfs(u,v);
        }
    }
    void calc(){
        dfs(0,0);
        int n = par.size();
        for(int i = 0; i < n ; i++){
            bl[0][i] = par[i];
        }
        for(int i =1; i < K; i++){
            for(int j = 0; j < n ; j++){
                bl[i][j] = bl[i-1][bl[i-1][j]];
            }
        }
    }
    int jump(int v, int k){
        for(int i = 0; i < K; i++){
            if((1<<i)&k) v = bl[i][v];
        }
        return v;
    }
    int find_LCA(int u , int v){
        if(depth[u] < depth[v]) swap(u,v);
        u = jump(u , depth[u] - depth[v]);
        if(u == v) return u;
        for(int i = K - 1; i > -1 ; i--){
            if(bl[i][u] != bl[i][v]){
                u = bl[i][u];
                v = bl[i][v];
            }
        }
        return par[u];
    }
};
struct segtree{
    int size;
    vi sums;
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        sums.assign(2*size,-1e9);
    }
    void build(vector<int> &a,int x , int lx , int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                sums[x]=a[lx];
            }
            return;
        }
        else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
        }
        sums[x]=std::max(sums[2*x+1],sums[2*x+2]);
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void set(int i , int v , int x , int lx, int rx){
        if(rx-lx==1){
            sums[x]=v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=std::max(sums[2*x+1],sums[2*x+2]);
    }
    void set(int i , int v){
        set(i,v,0,0,size);
    }
    int max(int l , int r, int x , int lx , int rx){
        if(l>=rx || lx>=r) return -1e9;
        if(l<=lx && r>=rx) return sums[x];
         
            int m = (lx+rx)/2;
            ll s1=max(l,r,2*x+1,lx,m);
            ll s2=max(l,r,2*x+2,m,rx);
            return std::max(s1,s2);
        
    }
    int max(int l , int r){
        return max(l,r,0,0,size);
    }
};
struct HLD{
    vector<segtree> st;
    vi ord;
    int timer = 0;
    vvi adj;
    vi par , which , sub, loc_seg;
    HLD(int n){
        adj.resize(n);
        par.resize(n);
        ord.resize(n);
        which.resize(n , -1);
        sub.resize(n , 1);
        loc_seg.resize(n , -1);
    }
    void add_edge(int a , int b){
        adj[a].pb(b);
        adj[b].pb(a);
    }
    void pre(int v , int p){
        par[v] = p;
        for(auto u : adj[v]){
            if(u == p) continue;
            pre(u,v);
            sub[v] += sub[u];
        }
    }
    void calc(vector<int> &val){
        pre(0,0);
        dfs(0,0,-1);
        vi cnt(par.size());
        for(int i =0; i < par.size(); i++){
            if(which[i] != -1)
                cnt[which[i]]++;
        }
        for(int i = 0; i < par.size() ; i++){
            if(cnt[i] > 1){
                loc_seg[i] = st.size();
                segtree new_st;
                new_st.init(cnt[i]);
                st.push_back(new_st);
            }
        }
        for(int i = 0; i < par.size() ; i++){
            if(which[i] != -1){
                debug(val[i])
                debug(i)
                st[loc_seg[which[i]]].set(ord[i] - ord[which[i]],val[i]);
            }
        }

    }
    void dfs(int v , int p , int leader){
        int heavy = -1;
        ord[v] = timer++;
        if(leader != -1) which[v] = leader;
        for(auto u : adj[v]){
            if(u == p) continue;
            if(sub[u] >= sub[v]/2) heavy = u;
        }
        if(heavy != -1){
            if(leader == -1){
                which[v] = v;
                dfs(heavy,v,v);
            }
            else{
                dfs(heavy , v , leader);
            }
        }
        for(auto u : adj[v]){
            if(u == p || u == heavy) continue;
            dfs(u,v,-1);
        }
    }
    void update(int s , int x , vi &val){
        val[s] = x;
        if(which[s] != -1){
            int loc = loc_seg[which[s]];
            st[loc].set(ord[s] - ord[which[s]] , x);
        }
    }
    int query(int a, int b , const vi &val){
        int ans = -1e9;
        int curr = a;
 
        while(curr != b){
            if(which[curr] == -1){
                ans = max(ans , val[curr]);
                curr = par[curr];
            }
            else{
                
                if(ord[b] < ord[which[curr]]){
                    ans = max(ans , st[loc_seg[which[curr]]].max(0 , ord[curr] - ord[which[curr]] + 1));
     
                    curr = par[which[curr]];
                }
                else{
                    ans = max(ans , st[loc_seg[which[curr]]].max(ord[b] - ord[which[curr]] + 1 , ord[curr] - ord[which[curr]] + 1));
              
                    break;
                }
            }
        }
        return ans;
    }
};
void solve(){
    int n , q;
    cin >> n >> q;
    vi val(n);
    for(auto &x : val) cin >> x;
    LCA lca(n);
    HLD hld(n);
    for(int i = 0; i < n -1; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        lca.add_edge(a,b);
        hld.add_edge(a,b);
    }
    lca.calc();
    hld.calc(val);
    while(q--){
        int type;
        cin  >> type;
        --type;
        if(type){
            int a , b;
            cin >> a >> b;
            --a; -- b;
            int l = lca.find_LCA(a,b);
            int left = hld.query(a,l,val) , right = hld.query(b,l,val);
            cout << max(val[l] , max(left,right)) << " ";
        }
        else{
            int s , x;
            cin >> s >> x;
            --s;
            hld.update(s,x,val);
        }
 
    }
}
int main(){
    FAST
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
