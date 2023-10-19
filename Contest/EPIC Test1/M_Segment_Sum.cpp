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
struct node{
    int cnt_odd , cnt_even;
    ll sum_odd , sum_even ;
    node() : cnt_odd(0), cnt_even(0), sum_odd(0), sum_even(0) {}
    void print(){
        cout << "Cnt of Odd : " << cnt_odd << " Cnt of Even : " << cnt_even << "\nSum of Odd : " << sum_odd << " Sum of Even : " << sum_even << nline;
    }
};
struct segtree{
    int size;
    vll operations;
    vector<node> sums;
    ll NO_OPERATIONS = LLONG_MAX;
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        sums.assign(2*size,node());
        operations.assign(2*size,NO_OPERATIONS);
    }
    node modify_Op(node a , ll b , ll len){
        if(b == NO_OPERATIONS){
            return a;
        }
        else{
            if(b&1){
                swap(a.sum_even,a.sum_odd);swap(a.cnt_even,a.cnt_odd);
            }
            if(a.cnt_even)
                a.sum_even += b*a.cnt_even;
            if(a.cnt_odd)
                a.sum_odd  += b*a.cnt_odd;
            return a;
        }
    }
    void apply_mod_op(node &a , ll b , ll len){
        a=modify_Op(a,b,len);
    }
    void up_ops(ll &a , ll b){
        if(b == NO_OPERATIONS) return ;
        if(a == NO_OPERATIONS) a = b;
        else a += b;
    }
    node calc_Op(node a , node b){
        a.cnt_even += b.cnt_even;
        a.cnt_odd += b.cnt_odd;
        a.sum_even += b.sum_even;
        a.sum_odd += b.sum_odd;
        return a;
    }
    void propagate(int x , int lx ,int rx){
        if(rx - lx == 1) return;
        int m = (lx + rx )/2;
 
        apply_mod_op(sums[2*x+1], operations[x]  , m -lx);
        apply_mod_op(sums[2*x+2] , operations[x] , rx -m );
        up_ops(operations[2*x+2] , operations[x]);
        up_ops(operations[2*x+1] , operations[x]);

        operations[x]=NO_OPERATIONS;
 
    }
    void set(int i , int v , int x , int lx, int rx){
        propagate(x,lx,rx);
        if(rx-lx==1){
            node a;
            if(v&1){
                a.cnt_odd++;
                a.sum_odd += v;
            }
            else{
                a.cnt_even++;
                a.sum_even+= v;
            }
            sums[x] = a;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=calc_Op(sums[2*x+1],sums[2*x+2]);
        apply_mod_op(sums[x], operations[x],rx-lx);
    }
    void set(int i , int v){
        set(i,v,0,0,size);
    }
    /*
        modify for range sum
    */
    void modify (int l , int r ,   int x , int lx , int rx){
        propagate(x , lx , rx );
        if(lx>=r || l>=rx) return ;
        if(lx >= l && rx <= r){
            up_ops(operations[x] , 1) ;
            apply_mod_op(sums[x] ,  1 , rx-lx) ;
            return;
        }
        int m  = (lx+rx)/2;
        modify(l,r ,2*x+1,lx,m);modify(l,r ,2*x+2,m,rx);
        // sums[x].print();
        sums[x]=calc_Op(sums[2*x+1], sums[2*x+2] );
        // sums[2*x+1].print();
        // cout << x << nline;
        // sums[2*x+2].print();
        // cout << x << nline;
        apply_mod_op(sums[x], operations[x],rx-lx);
        // sums[x].print();
        // cout << x << nline;
    }
    void modify (int l ,int r  ){
        modify(l , r   , 0 , 0 , size);
    }
    node calc(int l ,int r , int x , int lx ,int rx){
        propagate(x,lx,rx);
        if(lx>=r || rx<=l) return node();
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
    ll calc (int l , int r , bool type){
        auto val = calc(l,r , 0 , 0 ,size);
        if(type) return val.sum_odd;
        else return val.sum_even;
    }     
};
 
void solve(){
    int n , q;
    cin >> n >> q;
    vll v(n);
    segtree  st;
    st.init(n);
    for(auto &x : v) cin >> x;
    for (int i = 0; i < n; i++)
    {
        st.set(i,v[i]);
    }
    
    for (int i = 0; i < q; i++)
    {
        int type , l , r , va;
        cin >> type ;
        --type;
        if(!type){
            int idx;
            cin >> idx >> va;
            --idx;
            st.set(idx,va);
        }
        else if(type == 1){
            cin >> l >> r;
            --l;
            st.modify(l,r);
        }
        else {
            cin >> l >> r;
            --l;
            cout << st.calc(l,r,type&1) << nline;
        }
        debug(i)
        // st.sums[0].print();
         
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