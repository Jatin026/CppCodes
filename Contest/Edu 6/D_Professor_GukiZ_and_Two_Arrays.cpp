#include<bits/stdc++.h>
#include<chrono>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
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
// unordered_map<ll,pair<int,int>> a_ind , b_ind;

void solve(){
    int n , m;
    cin >> n;
    ll sum_a = 0,sum_b = 0;
    vi a(n);
    for(auto &x : a) cin >> x , sum_a += x;
    cin >> m;
    vi b(m);
    for(auto &x : b) cin >> x ,  sum_b += x;
    vll  y;
    // x.reserve(1e6);
    y.reserve(1e6);
 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            y.pb(b[i]+b[j]);
            // b_ind[b[i]+b[j]] = {i+1,j+1};
        }
        // b_ind[b[i]] = {i+1,0};
        // y.pb(b[i]);
    }
    sort(all(y));
    // x.resize(unique(all(x)) - begin(x));
    y.resize(unique(all(y)) - begin(y));


    auto check = [&](ll diff) -> bool {
        if(y.empty()) return 0;
        for(int i  =0 ; i < n ;i++){
            for(int j = 0; j < i ; j++){
                ll l_a  = a[i]+a[j];
                auto it = lb(all(y) , (2*l_a + sum_b-sum_a - diff )/2);
                ll guess_y = 1e10;
                if(it != y.end()){
                    guess_y = (*it);
                    if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= diff) return 1;
                }
                if(it != y.begin()){
                    // --it;
                    guess_y = (*prev(it));
                    if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= diff) return 1;
                }
                if(it != y.end()){
                    // --it;
                    guess_y = (*next(it));
                    if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= diff) return 1;
                }
                it = lb(all(y) , (diff - sum_a + sum_b + 2*l_a)/2);
                if(it != y.end()){
                    guess_y = (*it);
                    if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= diff) {
                        return 1;
                    }
                }
                if(it != y.begin()){
                    // --it;
                    guess_y = (*prev(it));
                    if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= diff) return 1;
                }
                if(it != y.end()){
                    // --it;
                    guess_y = (*next(it));
                    if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= diff) return 1;
                }
                guess_y = y.front();
                if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= diff) {
                    return 1;
                }
                guess_y = y.back();
                if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= diff) {
                    return 1;
                }
            }
        }
        return 0;
    };
    ll l = 0 , r = 1e14 , mid , ans = 1e13;
    while(l <= r){
        mid = (l+r)/2;
        if(check(mid)){
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    debug(ans)
    pair<ll,pair<int,int>> dif{1e14,{-1,-1}};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(abs(sum_a - 2*a[i] + 2*b[j] - sum_b) <= ans){
                dif = min(dif ,  {(ll)abs(sum_a - 2*a[i] + 2*b[j] - sum_b),pair<int,int> {i+1,j+1}});
            }
        }
    }
    if(dif.first >= abs(sum_a-sum_b) && ans >= abs(sum_a-sum_b)){
        cout << abs(sum_a-sum_b) << nline;
        cout << 0;
        return;
    }
    if(dif.first < 1e12){
        cout << dif.first << nline;
        cout << 1 << nline;
        cout << dif.second.first << " " << dif.second.second;
        return;
    }
    ll which_a , which_b;
    for(int i  =0 ; i < n ;i++){
            for(int j = 0; j < i ; j++){
                ll l_a  = a[i]+a[j];
            auto it = lb(all(y) , (-ans + sum_b - sum_a + 2*l_a )/2);
            ll guess_y = 1e10;
            if(it != y.end()){
                guess_y = (*it);
                if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= ans) {
                    which_a = l_a;
                    which_b = guess_y;
                    break;
                }
                guess_y = (*next(it));
                if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= ans) {
                    which_a = l_a;
                    which_b = guess_y;
                    break;
                }
            }
            if(it != y.begin()){
                // --it;
                guess_y = (*prev(it));
                if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= ans) {
                    which_a = l_a;
                    which_b = guess_y;
                    break;
                }
            }
            it = lb(all(y) , (ans - sum_a + sum_b + 2*l_a)/2);
            if(it != y.end()){
                guess_y = (*it);
                if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= ans) {
                    which_a = l_a;
                    which_b = guess_y;
                    break;
                }
                guess_y = (*next(it));
                if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= ans) {
                    which_a = l_a;
                    which_b = guess_y;
                    break;
                }
            }
            if(it != y.begin()){
                // --it;
                guess_y = (*prev(it));
                if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= ans) {
                    which_a = l_a;
                    which_b = guess_y;
                    break;
                }
            }
            guess_y = y.front();
            if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= ans) {
                    which_a = l_a;
                    which_b = guess_y;
                    break;
            }
            guess_y = y.back();
            if(abs(sum_a - sum_b - 2*l_a + 2*guess_y) <= ans) {
                    which_a = l_a;
                    which_b = guess_y;
                    break;
            }
        }
    }
    cout << ans << nline;
    cout << 2 << nline;
    pair<int,int> a_ind , b_ind;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ;  j < i ; j++){
            if(a[i] + a[j] == which_a){
                a_ind = {i+1,j+1};
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for(int j = 0 ;  j < i ; j++){
            if(b[i] + b[j] == which_b){
                b_ind = {i+1,j+1};
            }
        }
    }
    cout << a_ind.first << " " << b_ind.first  << nline;
    cout <<   a_ind.second  << " " <<  b_ind.second<< nline;
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