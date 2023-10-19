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
struct ans{
    ll H;
    ll cl;
    ll cr;
    ll ah;
};
ll h;
const ll INF = 1e18;
void solve(){
    int n ;
    cin >> n >> h;
    vi v(n);
    for(auto &x : v) cin >> x;
    ans W;
    W.ah = INF;
    W.cl= INF;
    W.cr= -1*INF;
    W.H = h;
    vector<vector<ll>> dp(n,vector<ll> (n,INF));
    auto join = [&](ans X , ans Y) -> ans {
        ans Z;
        int ah = X.ah + Y.ah ;
        int l = X.cr;
        int r = Y.cl;
        int H = X.H ;
        if ( X.H < Y.H )
        {
            l += Y.H - X.H ;
            H = Y.H;
            if (  min ( h , Y.H ) - X.H > 0 ) ah += min ( h , Y.H ) - X.H ;
        }
        else if ( Y.H < X.H )
        {
            r -= X.H - Y.H ;
            H = X.H; 
            if (  min ( h , X.H ) - Y.H > 0 ) ah += min ( h, X.H ) - Y.H ;
        }
        if ( (r - l ) % 2 == 0 )
        {
            int d = r - l - 2;
            d/= 2;
            r -= d;
            l += d;
            H += d+1;
            Z.H = H;
            Z.cl = l+1;
            Z.cr = r-1;
            if ( max(Y.H , X.H ) < h )
            {
                ah += d + d + 1;
                if ( H > h )
                {
                    ah -= 1;
                    ah -= 2*( H - 1 - h);
                } 
            }
            Z.ah = ah;
            return Z;
        }
        else 
        {
            int d = r - l -2 + 1;
            d/= 2;
            r -= d;
            l += d;
            H += d+1;
            Z.H = H;
            Z.cl = l;
            Z.cr = r;
            if ( max(Y.H , X.H ) < h )
            {
                ah += d + d + 1;
                if ( H > h )
                {
                    ah -= 1;
                    ah -= 2*( H - 1 - h);
                } 
            }
            Z.ah = ah;
            return Z;
        }


        
    };
    auto select = [&](ans X , ans Y) -> ans {
        if ( X.ah < Y.ah ) return X;
        if ( Y.ah < X.ah ) return Y;
        ans Z ;
        Z.ah = X.ah;
        Z.H = X.H;
        Z.cl = min ( X.cl , Y.cl);
        Z.cr = max ( X.cr , Y.cr);
        return Z; 
    };  
    auto create = [&](int L) -> ans {
        ans X;
        X.H = 0;
        X.cl = v[L] ;
        X.cr = v[L] ;
        X.ah =  0 ;
        return X;
    }; 
    for (int L = n-1; L > -1; L--)
    {
            for (int R = L; R < n; R++)
            {
                debug(L) debug(R)
                if(L == R ) {
                    // dp[L][R] = create(L);
                    dp[L][R] = h;

                }
                else{
                    for (int K = L; K < R; K++)
                    {
                        // dp[L][R] = select(dp[L][R] , join(dp[L][K],dp[K+1][R]) );
                         
                        if((v[R]-v[L]-1)/2 <= h) dp[L][R] = min(dp[L][R] , dp[L][K] + dp[K+1][R] + (v[R]-v[L]-1)/2 - h);
                        else dp[L][R] = min(dp[L][R] , dp[L][K] + dp[K+1][R]  );

                    }
                    
                }
            }
            
        }
        cout << dp[0][n-1];
        
 
    
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