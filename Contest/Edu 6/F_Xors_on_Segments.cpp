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
const int N = 5e4+10;
int val[N];
const int M = 1e6 + 10;
struct node{
    array<int,2> next;
    node (){
        fill(all(next),-1);
    }
};
int idx = 0;
node trie[M][4];
const int K = 20;
void add(int x , int b){
    int curr = 0;
    for(int i = K - 1; i > -1; i--){
        int bit = 0;
        if((1<<i)&x) bit = 1;
        assert(curr != -1);
        if(trie[curr][b].next[bit] == -1){
            trie[curr][b].next[bit] = ++idx;
        }
        curr = trie[curr][b].next[bit];
    }
}
const int MM = 1023;
int answer(int x , int b , int tie){
    int ans = 0, curr = 0;
    bool broken = false;
    for(int i = K - 1; i > -1; i--){
        int bit = 1;
        if((1<<i)&x) bit = 0;
        debug(ans)
        if(trie[curr][b].next[bit] == -1){
            bit ^= 1;
        }
        else {
            if(!broken){
                if(tie){
                    if(bit){
                        bit = 0;
                    }
                    else{
                        broken = true;
                        ans |= (1<<i);
                    }
                }
                else{
                    if(!bit){
                        bit = 0;
                    }
                    else{
                        broken = true;
                        ans |= (1<<i);
                    }
                }
            }
            else ans |= (1<<i);
        }
        curr = trie[curr][b].next[bit];
        if(curr == -1) return -1e9;
    } 
    if(!broken) return -1e9;
    return ans;
}
struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return (r -  l  + 1) <
               (other.r - other.l + 1);
    }
};
void solve(){
    int n , q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    vector<Query> query(q);
    for(int  i = 0; i < q; i++){
        cin >> query[i].l >> query[i].r;
        query[i].idx = i;
    }
    sort(all(query));
    vi fin(q);
    int cnt = 0;
     
    map<pair<int,int> , int> pre;
    for(auto x : query){
        int l  = x.l, r = x.r;
        // cin >> l >> r;
        --l; --r;
        bool flag = false;
        const int NN = (1<<20) - 1;
        if(cnt < 1000){
        for(auto x : pre){
            if((x.first.first) >= l && x.first.second <= r && (x.second == NN) ){
                flag = 1;
                break;
            }
        }
        if(pre.count({l,r})){
            fin[x.idx] = pre[{l,r}] ;
        }
        else if(flag){
               fin[x.idx] = NN;
        }
        else{

        idx = 0;
        int ans = 0;
        array<int,4> maxi{-1,-1,-1,-1};
        array<int,4> mini{(int)1e9,(int)1e9,(int)1e9,(int)1e9};
        for(int i = l ; i <= r; i++){
            add(val[i] , (val[i]%4));
            maxi[val[i]%4] = max(val[i],maxi[val[i]%4]);
            mini[val[i]%4] = min(val[i],mini[val[i]%4]);
        }
        for(int i = l ; i <= r; i++){
            ans = max(ans , val[i]);
            if(val[i]%4 == 0){
                ans = max(ans , maxi[0]);
                ans = max(ans , maxi[2] + 1);
                if(mini[2] < val[i]) ans = max(ans , val[i] + 1);
                ans = max(ans , answer(val[i] + 1, 1, 1));
                ans = max(ans , answer(val[i] , 3 , 1));
            }
            else if(val[i]%4 == 1){
                ans = max(ans , answer(val[i] - 1, 0,0));
                ans = max(ans , answer(val[i] , 2 ,0));
            }
            else if(val[i]%4 == 2){
                if(maxi[0] != -1) ans = max(ans , maxi[0] + 1);
                ans = max(ans , answer(val[i] , 1 , 1));
                ans = max(ans , answer(val[i] + 1 , 3, 1));
            }
            else{
                ans = max(ans , answer(val[i] , 0  , 0));
                ans = max(ans , answer(val[i] - 1, 2  , 0));
            } 
            if(ans == (1<<20) - 1) break;     
        }
        debug(((1<<20) - 1))
        pre[{l,r}] = ans;
        // cout << ans << nline;
        fin[x.idx] = ans;
        for(int i = 0; i <= idx ; i++){
            for(int  j =  0 ; j < 4 ; j++){
                fill(all(trie[i][j].next),-1);
            }
        }
        }
        if(fin[x.idx] == MM) cnt++;
        }
        else fin[x.idx] = MM;
    }
    for(auto x : fin) cout << x << nline;
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