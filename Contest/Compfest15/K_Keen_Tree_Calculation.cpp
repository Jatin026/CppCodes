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
// #define pr             pair<int,int>
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
ll maxi_ans = -1;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
vector<Line> garbage_lines;
vector<ll> valq;
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = 1e18;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
        Line l_temp;
        l_temp.k = k; l_temp.m = m; l_temp.p = 0;
		auto z = insert(l_temp), y = z++, x = y;
		while (!empty() && isect(y, z)) {
            l_temp.k = z->k; l_temp.m = z->m; l_temp.p = 0;
            garbage_lines.push_back(l_temp);
            // garbage_lines.push_back({z->k,z->m,0});
            z = erase(z);
        }
		if (!empty() && x != begin() && isect(--x, y)) {
            // Line l_temp;
            l_temp.k = y->k; l_temp.m = y->m; l_temp.p = 0;
            garbage_lines.push_back(l_temp);
            // garbage_lines.push_back({y->k,y->m,0});
            isect(x, y = erase(y));
        }
		while (!empty() && (y = x) != begin() && (--x)->p >= y->p){
            l_temp.k = y->k; l_temp.m = y->m; l_temp.p = 0;
            garbage_lines.push_back(l_temp);
            // garbage_lines.push_back({y->k,y->m,0});
			isect(x, erase(y));
        }
	}
	void query(ll x) {
        if(empty()) {
            return ;
        }
		assert(!empty());
		auto it = lower_bound(x);
        auto it2 = it;
        if(it == end()) return;
        assert(it != end());
        valq.pb((it->k) * x + (it->m));
        if(it != begin()) {
            assert(it != begin());
            valq.pb((prev(it) ->k) * x + (prev(it) ->m));
        }
        if(next(it2) != end()) {
            assert(next(it2) != end());
            valq.pb((next(it2)->k) * x + (next(it2)->m));
        }
	}
};
const int N = 1e5 +200;
struct solution{
    LineContainer cht_orginal,garbage_cht;
    vector<Line> v;
    void add(ll k , ll m){
        v.push_back({k,m,0});
    }
    void compute(){
        garbage_lines.clear();
        for(auto x : v) cht_orginal.add(x.k,x.m);
        auto temp  = garbage_lines;
        for(auto x : temp) garbage_cht.add(x.k,x.m);
    }
    ll maxQuery(ll x){
        valq.clear();
        cht_orginal.query(x);
        garbage_cht.query(x);
        sort(rbegin(valq),rend(valq));
        if(valq.empty()) return 0;
        else if(valq.size() < 2) return valq[0];
        valq.resize(2);
        ll tot = 0;
        for(auto x : valq) tot += max(0LL,x);
        return tot;
    }     
} ;
 
vector<ll> sub(N);
vector<vector<pair<ll,ll>>> adj(N) ,  querry(N);
void pre(int v , int par){
    for(auto u : adj[v]){
        if(u.first == par) continue;
        pre(u.first,v);
        sub[v] = max(sub[u.first] + u.second , sub[v]);
    }
}
vector<ll> ans(N);
void calc_dia(int v , int par , ll maxi){
    ll par_w = 0;
    ll f = 0 , s = 0;
    for(auto u : adj[v]){
        if(u.first == par) {
            par_w = u.second;
            continue;
        }
        if(f == u.second + sub[u.first]){
            s = f;
        }
        else if(f > u.second + sub[u.first]) s = max(s , u.second + sub[u.first]);
        else{
            s = f;
            f = u.second + sub[u.first];
        }
    }
    maxi_ans = max(maxi_ans , f + s);
    for(auto u : adj[v]){
        if(u.first == par) continue;
        maxi_ans = max(maxi_ans , maxi + u.second + sub[u.first]);
        calc_dia(u.first , v , max(maxi,(u.second + sub[u.first] == f ? s : f)) + u.second);
    }
}
void calc(int v , int par , ll maxi){
    ll par_w = 0;
    ll f = 0 ,s = 0;
    solution* sol =  new solution;
    for(auto u : adj[v]){
        if(u.first == par) {
            par_w = u.second;
            sol->add(par_w,maxi-par_w);
            continue;
        }
        if(f == u.second + sub[u.first]){
            s = f;
        }
        else if(f > u.second + sub[u.first]) s = max(s , u.second + sub[u.first]);
        else{
            s = f;
            f = u.second + sub[u.first];
        }
        sol->add(u.second,sub[u.first]);
    }
    sol->compute();
    for(auto x : querry[v]){
        int ind = x.second;
        ans[ind] = max(maxi_ans,sol->maxQuery(x.first));
    }
    delete sol;
    for(auto u : adj[v]){
        if(u.first == par) continue;
        calc(u.first , v , max(maxi,(u.second + sub[u.first] == f ? s : f)) + u.second);
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1 ; i < n; i++){
        int u , v , w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    pre(0,0);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int u , w;
        cin >> u >> w;
        --u;
        querry[u].emplace_back(w,i);
    }
    calc_dia(0,0,0);
    calc(0,0,0);
    for(int i = 0; i < q ; i++) cout << ans[i] << "\n";
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