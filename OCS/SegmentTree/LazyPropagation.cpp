#include<bits/stdc++.h>
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
    vector<Mint> operations;
    vector<Mint> sums;
    ll NO_OPERATIONS = LLONG_MAX;
    ll Neutral_Element= 0; 
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        sums.assign(2*size,1);
        operations.assign(2*size,0);
    }
    Mint modify_Op( Mint a , Mint b , Mint len){
        if(b ==  NO_OPERATIONS) return a;
        if(a ==  NO_OPERATIONS) return BinExpItr((ll)b,(ll)len);
        return a*BinExpItr((ll)b,(ll)len);
    }
    void apply_mod_op(Mint &a , Mint b , Mint len){
        a=modify_Op(a,b,len);
    }
    Mint calc_Op(Mint a , Mint b){
        return a+b ;
    }
    void propagate(int x , int lx ,int rx){
        if(rx - lx == 1) return;
        int m = (lx + rx )/2;

        apply_mod_op(sums[2*x+1], operations[x]  , m -lx);
        apply_mod_op(sums[2*x+2] , operations[x] , rx -m );
        apply_mod_op(operations[2*x+2] , operations[x] , 1 );
        apply_mod_op(operations[2*x+1] , operations[x] , 1  );
        operations[x]=NO_OPERATIONS;

    }
    void modify (int l , int r , int v, int x , int lx , int rx){
        propagate(x , lx , rx );
        if(lx>=r || l>=rx) return ;
        if(lx >= l && rx <= r){
            apply_mod_op(operations[x] , v , 1 ) ;
            apply_mod_op(sums[x] ,  v , rx-lx) ;
            return;
        }
        int m  = (lx+rx)/2;
        modify(l,r,v,2*x+1,lx,m);modify(l,r,v,2*x+2,m,rx);
        sums[x]=calc_Op(sums[2*x+1], sums[2*x+2] );
        apply_mod_op(sums[x], operations[x],rx-lx);
    }
    void modify (int l ,int r , int v){
        modify(l , r , v , 0 , 0 , size);
    }
    Mint calc(int l ,int r , int x , int lx ,int rx){
        propagate(x,lx,rx);
        if(lx>=r || rx<=l) return Neutral_Element;
        if(lx>=l && rx<=r){
            return sums[x];
        }
        int m = (lx+rx)/2;
        auto m1 = calc(l,r,2*x+1, lx , m);
        auto m2 = calc(l,r, 2*x+2 , m , rx);
        auto res = calc_Op(m1,m2);
        apply_mod_op(res, operations[x], min(r,rx) -  max(lx ,l));
        return res;
    }
    Mint calc (int l , int r ){
        return calc(l,r , 0 , 0 ,size);
    }
    void build(vector<ll> &a,int x , int lx , int rx){
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
        sums[x]=calc_Op(sums[2*x+1],sums[2*x+2]);
    }
    // void add(int l , int r , int v , int x , int lx , int rx){
    //     if(lx>=r || l>=rx) return ;
    //     if(lx>=l && rx<=r){
    //         operations[x]+=v;
    //         mins[x]+=v;
    //         return;
    //     }
    //     int m =(lx+rx)/2;
    //     add(l,r,v,2*x+1,lx,m);
    //     add(l,r,v,2*x+2,m,rx);
    //     mins[x]=std::min(mins[2*x+1],mins[2*x+2])+operations[x];
    // }
    // void add(int l ,int r , int v){
    //     add(l,r,v,0,0,size);
    // }
    // ll min(int l ,int r , int x , int lx ,int rx){
    //     if(lx>=r || l>=rx) return LLONG_MAX;
    //     if(lx>=l && rx<=r){
    //         return mins[x];
    //     }
    //     int m =(lx+rx)/2;
    //     ll m1= min(l,r,2*x+1,lx,m);
    //     ll m2 =min(l,r,2*x+2,m,rx);
    //     return std::min(m1,m2)+operations[x];

    // }
    // ll min(int l ,int r){
    //     return min(l,r,0,0,size);
    // }
    void build(vector<ll> &a){
        build(a,0,0,size);
    }
    
    
     
};
 

void solve(){
    int n,m;cin>>n>>m;
    segtree st;
    st.init(n);
    while (m--)
    {
        int type;cin>>type;
        if(type == 1){
            int l,r,v;
            cin>>l>>r>>v;
            st.modify(l,r,v);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<st.calc(l,r)<<nline;
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