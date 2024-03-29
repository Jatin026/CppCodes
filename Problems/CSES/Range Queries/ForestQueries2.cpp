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
    int sizex , sizey;
    int lenx ,leny ;
    vvi sums;
    segtree(int l , int r){
        lenx = l;
        leny = r;
    }
    void init(int n, int m){
        sizex=1;sizey=1;
        while(sizex<n){
            sizex*=2;
        }
        while(sizey<m){
            sizey*=2;
        }
        sums.assign(2*sizex,vi(2*sizey,0));
    }
    void build_y(vvi &a , int x , int y , int ly , int ry  ,  int rx , int lx){
        if(ry-ly==1){
            if(rx-lx==1 && lx<lenx && ly<leny) sums[x][y]=a[lx][ly];
            if(rx-lx!=1){ 
                debug(x)
                debug(rx-lx)
                sums[x][y]=sums[2*x+1][y]+sums[2*x+2][y];
            }
            return;
        }
        int mid = (ly+ry)/2;
        build_y(a,x,2*y+1,ly,mid,rx,lx);
        build_y(a,x,2*y+2,mid,ry,rx,lx);
        sums[x][y]=sums[x][2*y+1]+sums[x][2*y+2];
        
    }
    void build_x(vvi &a,int x , int lx , int rx ){
        if(rx-lx==1){
            build_y(a,x,0,0,sizey , rx , lx);
            return;
        }
        else{
            int m = (lx+rx)/2;
            build_x(a,2*x+1,lx,m);
            build_x(a,2*x+2,m,rx);
            build_y(a,x,0,0,sizey ,  rx , lx);
        }

    }
    
    void build(vvi &a){
        build_x(a,0,0,sizex);
    }
    void set_y(int xx , int yy , int v ,int x , int y , int ly , int ry , int rx , int lx){
        if(ry-ly==1){
            if(rx-lx == 1) sums[x][y]=v;
            else sums[x][y]=sums[2*x+1][y]+sums[2*x+2][y];
            return;
        }
        int m = (ly + ry)/2;
        if(m>yy){
            set_y(xx,yy,v,x,2*y+1,ly,m, rx , lx);
        }
        else set_y(xx , yy, v, x, 2*y+2, m , ry , rx , lx);
        sums[x][y]=sums[x][2*y+1]+sums[x][2*y+2];
    }
    void set_x(int xx , int yy , int v , int x , int lx, int rx){
        if(rx-lx==1){
            set_y(xx,yy,v,x, 0 , 0 , sizey ,rx , lx);
            return;
        }
        int m = (lx+rx)/2;
        if(xx<m){
            set_x(xx,yy,v,2*x+1,lx,m);
        }
        else{
            set_x(xx,yy,v,2*x+2,m,rx);
        }
        set_y(xx,yy,v,x, 0 , 0 , sizey , rx , lx);
    }
    void set(int x , int y , int v){
        set_x(x,y,v,0,0,sizex);
    }
    ll sum_y(int x , int y1 , int y2 , int y , int ly , int ry){
        if(y1>=ry || ly>=y2) return 0;
        if(y1<=ly && y2>=ry) return sums[x][y];
        int m = (ly+ry)/2;
        ll s1 = sum_y(x , y1 ,y2,2*y+1,ly,m);
        ll s2 = sum_y(x,  y1, y2,2*y+2,m,ry);
        return s1+s2;
    }
    ll sum_x(int x1 , int y1 , int x2 , int y2, int x , int lx , int rx){
        if(x1>=rx || lx>=x2) return 0;
        if(x1<=lx && x2>=rx){
            return sum_y(x,y1,y2,0,0,sizey);
        }
        int m = (lx+rx)/2;
        ll s1 = sum_x(x1,y1,x2,y2,2*x+1,lx,m);
        ll s2 = sum_x(x1,y1,x2,y2,2*x+2,m,rx);
         
        
        return s1+s2;
        
    }
    ll sum(int x1 , int y1 , int x2 , int y2){
        return sum_x(x1,y1,x2,y2,0,0,sizex);
    }
};
void solve(){
    int n,m; cin>>n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    vvi a(n,vi(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(v[i][j]=='*') a[i][j]=1;
            else a[i][j]=0;
        }
        
    }
    segtree st(n,n); st.init(n,n);
    st.build(a);
    while (m--)
    {
        int type=2 ; cin>> type;
        if(type==2){
            int x1,y1,x2,y2; cin >> x1>>y1>>x2>>y2;
            --x1;--y1;
             
            cout<<st.sum(x1,y1,x2,y2)<<nline;
        }
        else{
            int x , y, v ; cin>>x>>y;
            --x; --y;
            a[x][y]=(a[x][y]^1);
     
            st.set(x,y,a[x][y]);
           
        }
    }
 
    debug(st.sums)
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