#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;
 
#define ff first
#define ss second
#define mod0 998244353
#define mod1 1000000007
#define mod2 998244353
#define mpi 3.1415926535897932384626433832795
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define countbitsll(x) __builtin_popcountll(x)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define testdebug(tc) cerr << "TEST CASE: " << tc << "----------" << endl
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << "Line No. " << __LINE__ << ": " #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
#ifndef ONLINE_JUDGE
#define griddebug(x) for(auto y : x){for(auto z : y){cerr << z << " ";} cerr << endl;} 
#else
#define griddebug(x)
#endif 

 
typedef long long int ll;
typedef long double ld;
typedef bool bl;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, vector<ll>>> vpllvll;
typedef map<ll, ll> mll;
typedef map<ll, vector<ll>> mllvll;
typedef map<ll, pair<ll, ll>> mllpll;
typedef set<ll> sll;
typedef multiset<ll> msll;
typedef deque<ll> dll;
typedef stack<ll> stll;
typedef queue<ll> qll;
typedef vector<bool> vbl;
//typedef uint64_t u64;
//typedef __uint128_t u128;
 
 
 
// LOOPS------------------------------------------------------------------------------------------------------------------------
#define repg(i, a, b, c) for(ll i = a; i < b; i += c)
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rrep(i, a, b) for(ll i = a; i > b; i--)
#define rrepg(i, a, b, c) for(ll i = a; i > b; i -= c)
//------------------------------------------------------------------------------------------------------------------------------
 
 
ll extgcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1;
    while (b) {
        ll q = a / b;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b, a - q * b);
    }
    return a;
}
ll modinv(ll a, ll m){
    ll x, y;
    ll g = extgcd(a, m, x, y);
    if(g != 1){
        return -1;
    }
    else{
        x = (x + m) % m;
        return x;
    }
}
// to solve diophantine, pass abs(a), abs(b) to extgcd
 
const int mod = mod1;
 
struct mint {
    ll x;
    mint() : x(0) {}
    mint(ll y) {
        if(y>=0&&y<mod) x=y;
        else {
			x=y%mod;
        	if(x<0) x+=mod;
		}
    }
    mint operator-() {return mint(-x+mod);}
    mint operator ~() const {ll a,b; extgcd(x,mod,a,b); return a;}
    mint& operator+=(const mint& a) {if((x+=a.x)>=mod) x-=mod; return *this;}
    mint& operator-=(const mint& a) {if((x-=a.x)<0) x+=mod; return *this;}
    mint& operator*=(const mint& a) {x=(x*a.x)%mod; return *this;}
    mint& operator/=(const mint& a) {this->operator*=(~a);return *this;}
    mint operator ++() { ++x; if(x == mod) x = 0; return (*this); }
	mint operator ++(int) { x++; if(x == mod) x = 0; return mint(x-1); }
	mint operator --() { --x; if(x == -1) x = mod-1; return (*this); }
	mint operator --(int) { x--; if(x == -1) x = mod-1; return mint(x+1); }
    mint pow(ll b) const {
        mint res(1);
        mint a(*this);
        while(b) {
            if(b&1) res*=a;
            a*=a;
            b>>=1;
        }
        return res;
    }
    mint operator +(const mint& a) const { return mint(*this) += a;}
    mint operator -(const mint& a) const { return mint(*this) -= a;}
    mint operator *(const mint& a) const { return mint(*this) *= a;}
    mint operator /(const mint& a) const { return mint(*this) /= a;}
    bool operator <(const mint& a) const { return x < a.x;}
    bool operator <=(const mint& a) const { return x <= a.x;}
    bool operator >(const mint& a) const { return x > a.x;}
    bool operator >=(const mint& a) const { return x >= a.x;}
    bool operator ==(const mint& a) const { return x == a.x;}
    bool operator !=(const mint& a) const { return x != a.x;}
    
    friend istream& operator >>(istream& is, mint p) { return is >> p.x; }
    friend ostream& operator <<(ostream& os, mint p){ return os << p.x; }
};
// DEBUG------------------------------------------------------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(mint t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(queue <T> q);
template <class T> void _print(deque <T> q);
template <class T> void _print(stack <T> s);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(queue <T> q) {cerr << "[ "; while (!q.empty()) {_print(q.front()); cerr << " "; q.pop();} cerr << "]";}
template <class T> void _print(deque <T> q) {cerr << "[ "; while (!q.empty()) {_print(q.front()); cerr << " "; q.pop_front();} cerr << "]";}
template <class T> void _print(stack <T> s) {cerr << "[ "; while (!s.empty()) {_print(s.top()); cerr << " "; s.pop();} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// -----------------------------------------------------------------------------------------------------------------------------
 
// MATH-------------------------------------------------------------------------------------------------------------------------
 
ll bin_exp(ll a, ll b, ll mod){a %= mod; ll ans = 1;while(b > 0){if(b & 1){ans = (ans * a) % mod;}a = (a * a) % mod;b >>= 1;}return ans;}
ll bin_exp(ll a, ll b){ll ans = 1;while(b > 0){if(b & 1){ans *= a;}a *= a;b >>= 1;}return ans;}
//u64 bin_exp(u64 a, u64 b, u64 mod){a %= mod; u64 ans = 1; while(b > 0){if(b & 1){ans = (u128)ans * a % mod;} a = (u128)a * a % mod; b >>= 1;} return ans;}
// ll ceild(ll x, ll y){if((x < 0 && y > 0) || (x > 0 && y < 0)) return x / y;return (x + y - 1) / y;}
// ll mod(ll a, ll b){if(a > 0) return a % b;else return b + a % b;}
// ll mod2(ll a, ll b){if(mod(a, b) == 0) return b;return mod(a, b);}
ll gcd(ll a, ll b){while(b){a %= b; swap(a, b);} return a;}
 
 
 
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  // FOR RANDOM NUMBER GENERATION
 
// -----------------------------------------------------------------------------------------------------------------------------
/*
NumberTheory
DSU
Trees
Combi
Strings
Graph
*/
 
// -----------------------------------------------------------------------------------------------------------------------------
// Segment Tree Stuffs
 
// ll sgtn;
// pll sgt[4000000 + 10];
 
// pll combine(pll f, pll s){
//     if(f.ss > s.ss){
//         return f;
//     }
//     return s;
//     // include whatever the combination statement should be
// }
// void build(vpll &a, ll v, ll tl, ll tr){
//     if(tl == tr){
//         sgt[v] = a[tl];
//     }
//     else{
//         ll tm = (tl + tr) / 2;
//         build(a, 2*v, tl, tm);
//         build(a, 2*v+1, tm+1, tr);
 
//         // node upd
//         sgt[v] = combine(sgt[2*v], sgt[2*v+1]);
//     }   
// }
 
// pll query(ll v, ll tl, ll tr, ll l, ll r){
    
//     if(l > r){
//         return {-1, -1};
//     }
//     if(l == tl && r == tr){
//         return sgt[v];
//     }
//     ll tm = (tl + tr) / 2;
//     pll ans = combine(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));

//     return ans;
// }
 
// void update(ll v, int tl, int tr, ll pos, ll x){
//     if(tl == tr){
//         sgt[v] = x;
//     }
//     int tm = (tl + tr) / 2;
//     if(pos <= tm){
//         update(2*v, tl, tm, pos, x);
//     }
//     else{
//         update(2*v+1, tm + 1, tr, pos, x);
//     }
 
//     sgt[v] = combine(sgt[2*v], sgt[2*v+1]); 
// }
 
/*
to reduce memory
if at ind v => children indices are: (v + 1) && (v + 2 * (mid - l + 1))
=> achieves sgt of size 2*n
*/
 
// ll dfs(ll node, ll parent, vector<vpll> &adj){
//     ll fans = 0;
//     for(auto x : adj[node]){
//         if(x.ff == parent){
//             continue;
//         }
 
//         fans = max(fans, dfs(x.ff, node, adj) + x.ss);
//     }
//     return fans;
// }
vector<mint> fact, invfact;
void comb(ll n){
  fact.resize(n+1, 1);
  invfact.resize(n+1, 1);

  rep(i, 1, n+1){
    fact[i]=fact[i-1]*i;
  }
  invfact[n]= ~fact[n];
  rrep(i, n-1, -1){
    invfact[i]=invfact[i+1]*(i+1);
  } 
}
mint ncr(ll n, ll r){
  if(n<0||r<0||n<r) return (mint)0;
  mint fans = fact[n]*invfact[n-r]*invfact[r];
  return fans;
}



void solve(){
  ll n, q;
  cin >> n >> q;
  vll v(n);
  rep(i, 0, n){
    cin >> v[i];
  }
  sort(all(v));

  while(q--){
    ll k;
    cin >> k;
    ll kc = k;

    msll ms;
    rep(i, 0, n){
      ms.insert(v[i]);
    }



    if(k % 2 == n % 2){

      ll cur = kc;
      rep(i, 0, min(n, k)){
        ll val1 = v[i];

        ms.erase(ms.find(val1));
        
        val1 += cur;

        cur -= 1;

        ms.insert(val1);
      }

      k -= min(n, k);
    }
    else{
      ll cur = kc;
      rep(i, 0, min(n-1, k)){
        ll val1 = v[i];

        ms.erase(ms.find(val1));
        
        val1 += cur;

        cur -= 1;

        ms.insert(val1);
      }

      k -= min(n-1, k);
    }

    
    ll beg = *ms.begin();
    bool fr = true;
    ll ch = 0;
    for(auto x : ms){
      if(fr){
        fr = false;
        continue;
      }
      ch += x - beg;
    }

    ll ans;
    if(k / 2 <= ch){
      ans = beg;
    }
    else{
      ans = beg - ((k/2 - ch) + n-1) / n;
    }

    cout << ans << ' ';
  }
}



int main(){

	auto start = chrono :: high_resolution_clock :: now();
 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  	
  cout.tie(NULL);
 

	ll t = 1;
	//cin >> t;

	int tc = 1;
	    
	while(t--){
	   
	   
	  //cout << "Case " << tc << ": ";
	  solve();
	  tc++;
	}

	auto stop = chrono ::  high_resolution_clock :: now();

 
	return 0;
}