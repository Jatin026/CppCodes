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
 
vvi pre;
const ll inf = 1e18;
#define ff first 
#define ss second 
struct cmp {
    bool operator ()(pair<pr,long long> a , pair<pr,long long > b) const{
        if(pre[a.ff.ff][a.ff.ss] < pre[b.ff.ff][b.ff.ss]) return 1;
        else if(pre[a.ff.ff][a.ff.ss] > pre[b.ff.ff][b.ff.ss]) return 0;
        else{
            return (a.ss < b.ss);
        }
    }
};

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    pre.assign(n,vi(n,0));
    vi val(n);
    for(auto &x : val) cin >> x;
    vector<pair<string,pr>> arr;
    for (int i = 0; i < n; i++)
    {
        string ele = "";
        for (int j = i; j < n; j++)
        {
            ele += s[j];
            arr.emplace_back(make_pair(ele,make_pair(i,j)));
        }
    }
    sort(all(arr));
 
    vvi pre(n,vi(n));
    int ind = 0;
    string prev = "";
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i].ff != prev){
            ind++;
            prev = arr[i].ff;
        }
        pre[arr[i].ss.ff][arr[i].ss.ss] = ind; 
    }

    vector<multiset<pair<pr,ll>,cmp>> cunt(n+1); 
    for (int j = 0; j < n; j++)
    {
        cunt[j+1] = cunt[j];
        vector<pair<pr,ll>> update;
        for (int i = 0; i <= j; i++)
        {   
            if(cunt[i].empty()){
                update.emplace_back(make_pair(make_pair(i,j),val[j-i]));
                continue;
            }
            
            auto it = cunt[i].lb(make_pair(make_pair(i,j),-inf));
               debug(make_pair(i,j))

            if(it  == cunt[i].begin()){
                auto p = (*it).ff;
                debug(p)
                debug(1)
                if(pre[p.ff][p.ss] < pre[i][j]) update.emplace_back(make_pair(make_pair(i,j), (*it).ss + val[j-i])) ;
                else update.emplace_back(make_pair(make_pair(i,j),val[j-i]));
                continue;
            }
            else{
                auto p = *(--it);
                
                debug(p)
                update.emplace_back(make_pair(make_pair(i,j),p.ss+val[j-i]));
            }
        }
      
        for(auto &x : update){
            cunt[j+1].insert(x);
           
        }
         
        ll prev = 0;
        multiset<pair<pr,ll>,cmp> temp = cunt[j+1];
       
        for(auto x : temp){
            if(x.ss <= prev){
                
                cunt[j+1].erase(x);
                
            }
            else{
              
                prev = x.ss;
            }
        }
        debug(nline)
        for(auto x : cunt[j+1]){
            debug(x)
        }
        debug(nline)
    }
    ll ans  = 0;
    for(auto x : cunt[n]){
        ans = max(ans , x.ss);
    }
    cout << ans << nline;
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