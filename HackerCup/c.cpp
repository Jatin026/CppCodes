#include<bits/stdc++.h>
 
 #pragma comment(linker, "/STACK:268435456");
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
 
ifstream in("Input.txt");
ofstream out("Output2.txt");
void Case(){
    static int c=1;
    out<<"Case #"<<c<<": ";
    c++;
}
struct segtree{
    int size;
    vvi sums;
   
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
      
        sums.resize(2*size,vi(4,0));
    }
    void build(vector<int> &a,int x , int lx , int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                sums[x][a[lx]]=1;
                for (int i = 0; i < 4; i++)
            {
                if(i!=a[lx]) sums[x][i]=0;
            }
            
            }
            return;
        }
        else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
        }
        for (int i = 0; i < 4; i++)
        {
            sums[x][i]=sums[2*x+1][i]+sums[2*x+2][i];
        }
        
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void set(int i , int v , int x , int lx, int rx){
        if(rx-lx==1){
            sums[x][v]=1;
            for (int i = 0; i < 4; i++)
            {
                if(i!=v) sums[x][i]=0;
            }
             
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        for (int i = 0; i < 4; i++)
        {
            sums[x][i]=sums[2*x+1][i]+sums[2*x+2][i];
        }
    }
    void set(int i , int v){
        set(i,v,0,0,size);
    }
    vi sum(int l , int r, int x , int lx , int rx){
        vi y(4,0);
        if(l>=rx || lx>=r) return y;
        if(l<=lx && r>=rx){
             
            return sums[x];
        }
         
        int m = (lx+rx)/2;
        vi s1=sum(l,r,2*x+1,lx,m);
        vi s2=sum(l,r,2*x+2,m,rx);
       
        for (int i = 0; i < 4; i++)
        {
                s1[i]=s1[i]+s2[i];
        }
        return s1;
    }
    vi sum(int l , int r){
        return sum(l,r,0,0,size);
    }
};
void solve(){ 
    int n,m;in>>n>>m;
    vi c(n); for(auto &x : c) in>>x;
    segtree st;
    st.init(n);
    st.build(c);
    ll ans=0;
    while (m--)
    {
        int x,y,z; in>>x>>y>>z;
        --x;
        st.set(x,y);
        vi a = st.sum(0,z), b = st.sum(z,n);
        int s1=0,s2=0;
        for (int i = 0; i < 4; i++)
        {
            s1+=i*a[i]; s2+=i*b[i];    
        }
        int ops=0;
        if(s1==s2) continue;
        else if(s1>s2){
            int dif=s1-s2;
            if(dif >= min(a[3],b[1])*4){
                dif-=min(a[3],b[1])*4;
                ops+=min(a[3],b[1]);
                int o = min(a[3],b[1]);
                a[3]-=o;b[1]-=o;
            }
            if(dif==0){
                 ans+=ops;
                 continue;
            }
            if(dif>=min(a[3],b[2])*2){
                dif-=min(a[3],b[2])*2;
                ops+=min(a[3],b[2]);
                int o = min(a[3],b[2]);
                a[3]-=o;b[2]-=o;
            }
            if(dif==0){
                 ans+=ops;
                 continue;
            }
            if(dif>=min(a[2],b[1])*2){
                dif-=min(a[2],b[1])*2;
                ops+=min(a[2],b[1]);
                int o = min(a[2],b[1]);
                a[2]-=o;b[1]-=o;
            }
            if(dif==0){
                 ans+=ops;
                 continue;
            }
            else ans+=(-1);
        }
        else {
            swap(s1,s2);
            swap(a,b);
            int dif=s1-s2;
            if(dif >= min(a[3],b[1])*4){
                dif-=min(a[3],b[1])*4;
                ops+=min(a[3],b[1]);
                int o = min(a[3],b[1]);
                a[3]-=o;b[1]-=o;
            }
            if(dif==0){
                 ans+=ops;
                 continue;
            }
            if(dif>=min(a[3],b[2])*2){
                dif-=min(a[3],b[2])*2;
                ops+=min(a[3],b[2]);
                int o = min(a[3],b[2]);
                a[3]-=o;b[2]-=o;
            }
            if(dif==0){
                 ans+=ops;
                 continue;
            }
            if(dif>=min(a[2],b[1])*2){
                dif-=min(a[2],b[1])*2;
                ops+=min(a[2],b[1]);
                int o = min(a[2],b[1]);
                a[2]-=o;b[1]-=o;
            }
            if(dif==0){
                 ans+=ops;
                 continue;
            }
            else ans+=(-1);
        }
    }
    Case();
    out<<ans<<nline;
}
int main(){
    int t=1;
    in>>t;
    while(t--){
        solve();
    }
    return 0;
}