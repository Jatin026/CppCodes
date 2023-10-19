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
const int inf = INT_MAX;
#define ll int
struct segtree{
    int sizex , sizey;
    int lenx ,leny ;
    // vector<vll> maxi,mini;
    vector<vector<vll>> val;
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
        // mini.assign(2*sizex,vll(2*sizey,inf));
        // maxi.assign(2*sizex,vll(2*sizey,-inf));
        val.assign(2*sizex , vector<vll> (2*sizey ));
    }
    void build_y(vector<vector<long long>> &a, int x , int y , int ly , int ry  ,  int rx , int lx){
        if(ry-ly==1){
            if(rx-lx==1 && lx<lenx && ly<leny) {
                // maxi[x][y]=a[lx][ly];
                // mini[x][y]=a[lx][ly];
                val[x][y].emplace_back(a[lx][ly]);
            }
            if(rx-lx!=1){ 
                // maxi[x][y] = max(maxi[2*x+1][y],maxi[2*x+2][y]);
                // mini[x][y] = min(mini[2*x+1][y],mini[2*x+2][y]);
                merge(all(val[2*x+1][y]),all(val[2*x+2][y]),back_inserter(val[x][y]));
            }
            return;
        }
        int mid = (ly+ry)/2;
        build_y(a,x,2*y+1,ly,mid,rx,lx);
        build_y(a,x,2*y+2,mid,ry,rx,lx);
        // maxi[x][y] = max(maxi[x][2*y+1],maxi[x][2*y+2]);
        // mini[x][y] = min(mini[x][y*2+1],mini[x][2*y+2]);
        merge(all(val[x][2*y+1]),all(val[x][2*y+2]),back_inserter(val[x][y]));
        
    }
    void build_x(vector<vector<long long>> &a,int x , int lx , int rx ){
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
    
    void build(vector<vector<long long>> &a){
        build_x(a,0,0,sizex);
    }
 
    ll querry_y(int x , int y1 , int y2 , int y , int ly , int ry,ll q){
        if(y1>=ry || ly>=y2) return -inf;
        if(y1<=ly && y2>=ry) {
            auto it = lb(all(val[x][y]),q);
            if(it == val[x][y].begin() && (*it) > q) return -inf;
            if(it == val[x][y].end() || (*it) > q)
                --it;
           
            return (*it);
        }
        int m = (ly+ry)/2;
        ll s1 = querry_y(x , y1 ,y2,2*y+1,ly,m,q);
        ll s2 = querry_y(x,  y1, y2,2*y+2,m,ry,q);
        return max(s1,s2);
    }
    ll querry_x(int x1 , int y1 , int x2 , int y2, int x , int lx , int rx , ll  q){
        if(x1>=rx || lx>=x2) return -inf;
        if(x1<=lx && x2>=rx){
            return querry_y(x,y1,y2,0,0,sizey,q);
        }
        int m = (lx+rx)/2;
        ll s1 = querry_x(x1,y1,x2,y2,2*x+1,lx,m,q);
        ll s2 = querry_x(x1,y1,x2,y2,2*x+2,m,rx,q);
        return max(s1,s2);
        
    }
    ll querry(int x1 , int y1 , int x2 , int y2,ll q){
        return querry_x(x1,y1,x2,y2,0,0,sizex,q);
    }
    
};
#undef ll
void solve(){
    ll n , q;
    cin >> n >> q;
    vll v(n);
    for(auto &x : v){
        cin >> x;
    }
    map<ll,int> compress;
    segtree st(n,n);
    st.init(n,n);
    vector<vll> pre(n,vll(n,-inf));
    for (int i = 0; i < n; i++)
    {
        ll sum = 0;
        for (int j = i; j < n; j++)
        {
            sum+=v[j];
            pre[i][j] = sum;
            compress[sum]++;
        }
    }
    vector<array<ll,3>> querry(q);
    for (int i = 0; i < q; i++)
    {
        ll a , b , u;
        cin >> a >> b >> u;
        querry[i] = {a,b,u};
        compress[u]++;
        
    }
    map<int,ll> rev;
    int ind = 1;
    for(auto &x : compress) x.second = ind++;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            rev[compress[pre[i][j]]] = pre[i][j];
            pre[i][j] = compress[pre[i][j]];
        }
    }

    st.build(pre);
    for (int i = 0; i < 2*st.sizex; i++)
    {
        for (int j = 0; j < 2*st.sizey; j++)
        {
            // st.val[i][j].emplace_back(-inf);
            sort(all(st.val[i][j]));
        }
        
    }
    for (int i = 0; i < q; i++)
    {
        ll a = querry[i][0] , b = querry[i][1] , u = querry[i][2];
        --a;
        u = compress[u];
        ll ans = st.querry(a,a,b,b,u);
        if(ans == -inf) cout << "NONE\n";
        else cout << rev[ans] << nline;
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