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
int T = 0 , oT;
void construct_basis(int x , vi &basis){
    for (int i = 30; i > -1; i--)
    {
        if(x&(1<<i)){
            if(!basis[i]){
                basis[i] = x;
                return;
            }
            x ^= basis[i];
        }
    }
    
}
const int l = 19;
void dfs(int v , int pr ,vvi &adj , vi &d , vi &f , vi &in , vi &out , vi &val , vvi &basis , vvi &up){
    in[v] = T++;
    construct_basis(val[v],basis[v]);
     
    d.emplace_back(v);
    up[v][0] = pr;
   
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for(auto u : adj[v]){
        if(u == pr) continue;
        dfs(u,v,adj,d,f,in,out,val,basis,up);
         
        for (int i = 30; i > -1; i--)
        {
            construct_basis(basis[u][i] , basis[v]);   
        }
    }
    f.emplace_back(v);
    out[v] = oT++;
}

void solve(){
    int n;
    cin >> n;
    oT = 0;
    vi val(n);
    for(auto &x : val) cin >> x;
    vvi adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;--b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    vi in(n) , out(n) , f , d;
    vvi basis(n,vi(31,0)) , suff(n+1,vi(31,0)) , pref(n+1,vi(31,0)) , up(n,vi(l+1,0));
    dfs(0,0,adj,d,f,in,out,val,basis,up);
 
    for (int i = 0; i < n; i++)
    {
        pref[i+1] = pref[i];
        suff[n-i-1] = suff[n-i]; 
        construct_basis(val[d[i]] , pref[i+1]);
        construct_basis(val[f[n-i-1]] , suff[n-i-1]);
    }
    auto maximum_value = [&](vi &basis) -> int {
        int val = 0;
        for (int i = 30; i > -1; i--)
        {
            if(val&(1<<i)) continue;
            if(basis[i]){
                val ^= basis[i];
            }
        }
        return val;
    };
    auto reach = [&](int node , int dist) -> int {
        for (int i = l; i > -1; i--)
        {
            if((1<<i)<=dist){
                node = up[node][i];
                dist -= (1<<i);
            }
        }
        return node;
    };
    auto find_lowest = [&](int root , int c) -> int {
        int l = 0 , r  = (1<<18) , mid , ans = root;
        while(l<=r){
            mid = (l+r)/2;
            int v  = reach(root,mid);
            if(in[v] > in[c]){
                l = mid + 1;
                ans = v;
            }
            else r = mid - 1;
        }
        return ans;
    };
    
    debug(f)
    debug(out); 
    debug(in)
    debug(d)
 
    int q;
    cin >> q;
    while(q--){
        int r,c;
        cin >> r >> c;
        --r;--c;
        
        if(r  == c){
            cout << maximum_value(basis[0]) << nline;
        }
        else if(in[r] >= in[c] && out[r] <= out[c]){
            int v = find_lowest(r,c);
            assert(v<n);
            debug(v)
            vi merge = pref[in[v]];
            debug(maximum_value(merge))
            for (int i = 30; i > -1; i--)
            {
                construct_basis(suff[out[v]+1][i] , merge);
            }
            cout << maximum_value(merge) << nline;
        }   
        else{
            cout << maximum_value(basis[c]) << nline;
        }
    }

}
int main(){
    FAST
    int t=1;
    cin>>t;
    while(t--){
        T = 0;
        solve();
    }
    return 0;
}