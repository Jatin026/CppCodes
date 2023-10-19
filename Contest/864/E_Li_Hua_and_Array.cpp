#include<bits/stdc++.h>
#include<chrono>

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

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
const int BUF_SZ = 1 << 15;

inline namespace Input {
char buf[BUF_SZ];
int pos;
int len;
char next_char() {
	if (pos == len) {
		pos = 0;
		len = (int)fread(buf, 1, BUF_SZ, stdin);
		if (!len) { return EOF; }
	}
	return buf[pos++];
}

int read_int() {
	int x;
	char ch;
	int sgn = 1;
	while (!isdigit(ch = next_char())) {
		if (ch == '-') { sgn *= -1; }
	}
	x = ch - '0';
	while (isdigit(ch = next_char())) { x = x * 10 + (ch - '0'); }
	return x * sgn;
}
}
inline namespace Output {
char buf[BUF_SZ];
int pos;

void flush_out() {
	fwrite(buf, 1, pos, stdout);
	pos = 0;
}

void write_char(char c) {
	if (pos == BUF_SZ) { flush_out(); }
	buf[pos++] = c;
}

void write_int(int x) {
	static char num_buf[100];
	if (x < 0) {
		write_char('-');
		x *= -1;
	}
	int len = 0;
	for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
	write_char((char)('0' + x));
	while (len) { write_char(num_buf[--len]); }
	write_char('\n');
}

// auto-flush output when program exits
void init_output() { assert(atexit(flush_out) == 0); }
}
const int N = 5e6+7;
vector<int> phi(N + 1);
void phi_1_to_n(int n) {
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
struct segtree{
    int size;
    vector<vector<pair<int,int>>> sums;
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        sums.resize(2*size,vpr{0});
    }
    void build(vector<int> &a,int x , int lx , int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                sums[x].clear();
                int temp = a[lx];
                int cnt = 0;
                while(temp != 1){
                    sums[x].emplace_back(temp,cnt++);
                    temp = phi[temp];
                }  
                if(temp == 1) sums[x].emplace_back(1,cnt); 
                reverse(all(sums[x]));
            }
            return;
        }
        else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            sums[x].clear();
            if(sums[2*x+1].empty()) {
                sums[x] = sums[2*x+2];
                return;
            }
            if(sums[2*x+2].empty()) {
                sums[x] = sums[2*x+1]; 
                return;
            }
            int l1 = sums[2*x+1].size() , l2 = sums[2*x+2].size();
            for(int i = 0; i < min(l1,l2) ; i++){
                if(sums[2*x+1][i].first == sums[2*x+2][i].first){
                    sums[x].emplace_back(sums[2*x+1][i].first , sums[2*x+1][i].second + sums[2*x+2][i].second);
                }
                else break;
            }
        }
         
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void set(int i , int v , int x , int lx, int rx ){
        if(rx-lx==1){
            sums[x].pop_back();
            for(auto &x : sums[x]){
                x.second--;
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
        sums[x].clear();
        if(sums[2*x+1].empty()) {
                sums[x] = sums[2*x+2];
                return;
            }
        if(sums[2*x+2].empty()) {
                sums[x] = sums[2*x+1]; 
                return;
        }
        int l1 = sums[2*x+1].size() , l2 = sums[2*x+2].size();
        for(int i = 0; i < min(l1,l2) ; i++){
            if(sums[2*x+1][i].first == sums[2*x+2][i].first){
                sums[x].emplace_back(sums[2*x+1][i].first , sums[2*x+1][i].second + sums[2*x+2][i].second);
            }
            else break;
        }
    }
    void set(int i , int v){
        set(i,v,0,0,size);
    }
    vpr sum(int l , int r, int x , int lx , int rx){
        if(l>=rx || lx>=r) return vpr{0};
        if(l<=lx && r>=rx) return sums[x];
         
            int m = (lx+rx)/2;
            auto s1=sum(l,r,2*x+1,lx,m);
            auto s2=sum(l,r,2*x+2,m,rx);
            if(s1 == vpr{0}) return s2;
            if(s2 == vpr{0}) return s1;
            // debug(s1)
            // debug(s2)
            vpr ans;
            int l1 = s1.size() , l2 = s2.size();
            for(int i = 0; i < min(l1,l2) ; i++){
                if(s1[i].first == s2[i].first){
                    ans.emplace_back(s1[i].first , s1[i].second + s2[i].second);
                }
                else break;
            }
            // debug(ans)
            return ans;
        
    }
    int sum(int l , int r){
        return sum(l,r,0,0,size).back().second;
    }
};
// const int MOD = 1e9 + 7;

void solve(){
    phi_1_to_n(N);
    int n = read_int() , m = read_int();
    
    vi v(n);
    for(auto &x : v) x = read_int();
    set<int> active;
    for(int i = 0 ; i < n ; i++){
        if(v[i] > 1) active.insert(i);
    }
    segtree st;
    st.init(n);
    st.build(v);
 
    while(m--){
        int type = read_int() ,l = read_int() , r = read_int();
        // cin >> type >> l >> r;
        --type; --l ; --r;
        if(!type){
            if(!active.empty()){
                auto it = active.lb(l);
                while(it != active.end() && (*it) <= r){
                    int ind =  (*it) ;
                    st.set(ind,v[ind]);
                    v[ind] = phi[v[ind]];
                    if(v[ind] ==  1) active.erase(ind);
                    it = active.ub(ind);
                }
            }
            
        }   
        else{
            // write_int(st.sum(l,r+1));
            cout << st.sum(l,r+1) << nline;
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