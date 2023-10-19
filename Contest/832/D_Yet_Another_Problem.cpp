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

struct segtree{
    int size;
    vvi ele;
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        ele.resize(2*size);
    }
    void build(vector<int> &a,int x , int lx , int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                ele[x].pb(a[lx]);
            }
            return;
        }
        else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
        }
        ele[x].insert(ele[x].end(),all(ele[2*x+1]));
        ele[x].insert(ele[x].end(),all(ele[2*x+2]));
        sort(all(ele[x]));
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    bool find(int l , int r, int x , int lx , int rx,int v){
        debug(x)
        if(l>=rx || lx>=r) return 0;
        if(l<=lx && r>=rx) {
            auto it = lb(all(ele[x]),v);
            if(it!=ele[x].end()){
                 
                return ((*it) == v);
            }
            else return 0;
        }
         
            int m = (lx+rx)/2;
            bool s1=find(l,r,2*x+1,lx,m,v);
            bool s2=find(l,r,2*x+2,m,rx,v);
            return (s1|s2);
        
    }
    bool find(int l , int r, int v){
        return find(l,r,0,0,size,v);
    }
};
/*
Subtask: Find range in which we have to search.
As I know if l is odd then r has to be even.
1 4 6 8
*/
void solve(){
    int n,q;
    cin >> n >> q;
    vi v(n);
    vi prefX(n+1,0),cnt0(n+1,0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        prefX[i+1]=(prefX[i]^v[i]);
        cnt0[i+1]=cnt0[i]+(v[i] == 0);
    }
    segtree odd , even;
    vi prefOdd,prefEven;
    for (int i = 0; i <= n; i++)
    {
        if(i%2==0){
            prefEven.pb(prefX[i]);
        }
        else prefOdd.pb(prefX[i]);
    }
    odd.init(prefOdd.size());
    even.init(prefEven.size());
    odd.build(prefOdd);
    even.build(prefEven);
  
  
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        if((prefX[r]^(prefX[l-1])) !=0) cout << -1 << nline;
        else{
            if(cnt0[r]-cnt0[l-1] == r-l+1) cout << 0 << nline;
            else if((r-l+1)&1 || cnt0[l]-cnt0[l-1] == 1 || cnt0[r]-cnt0[r-1] == 1) cout << 1 << nline;
            else{
                bool flag = false;
                // for (int i = l; i <= r; i+=2)
                // {
                //     if((prefX[i]^prefX[l-1]) == 0){
                //         debug((prefX[i]^prefX[l-1]) )
                //         debug(q)
                //         cout << 2 << nline;
                //         flag= true;
                //         break;
                //     }
                // }
                // if(!flag){
                //     for (int i = r; i >=l ; i-=2)
                //     {
                //         if((prefX[i-1]^prefX[r]) == 0){
                //             cout << 2 << nline;
                //             flag=true;
                //             break;
                //         }
                //     }
                // }
                if(l&1){

                    int a = (l/2);
                    int b = (r/2);
                    debug(a) debug(b)
                    debug(prefX[l-1])
                    flag = odd.find(a,b,prefX[l-1]);
                }
                else{
                    int a = (l)/2;
                    int b = (r)/2;
                    debug(a) debug(b)
                    flag = even.find(a,b,prefX[l-1]);
                }
                if(!flag) cout << -1 << nline;
                else cout << 2 << nline;
            }
        }
    }
    
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