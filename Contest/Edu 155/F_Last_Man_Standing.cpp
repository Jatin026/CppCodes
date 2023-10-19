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

/*
const int MOD = 1e9 + 7;
*/
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

ll read_int() {
    ll x;
    char ch;
    int sgn = 1;
    while (!isdigit(ch = next_char())) {
        if (ch == '-') { sgn *= -1; }
    }
    x = ch - '0';
    while (isdigit(ch = next_char())) { x = x * 10 + (ch - '0'); }
    return x * sgn;
}
}  // namespace Input
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

void write_int(ll x) {
    static char num_buf[100];
    if (x < 0) {
        write_char('-');
        x *= -1;
    }
    int len = 0;
    for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
    write_char((char)('0' + x));
    while (len) { write_char(num_buf[--len]); }
    write_char(' ');
}

// auto-flush output when program exits
void init_output() { assert(atexit(flush_out) == 0); }
} 


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
    ll idx , first_max , second_max;
    node(){
        idx = -1; first_max = 0 ; second_max = 0;
    }
    node(int idx ,int first_max) : idx(idx) , first_max(first_max), second_max(-1e9) {}
    node(int idx ,int first_max , int second_max) : idx(idx) , first_max(first_max), second_max(second_max){}
    void clear(){
        idx = -1; first_max =0; second_max =0;
    }
    void print(){
        cout << "idx : " << idx << ", "  << "first_max :" << first_max << ", " << "second_max : " << second_max << nline;
    }
};
node max(const node &a , const node &b){
    if(a.idx == b.idx){
        return node(a.idx,a.first_max , max(a.second_max , b.second_max));
    }
    node res;
    if(a.first_max > b.first_max){
        res.first_max = a.first_max;
        res.idx = a.idx;
        res.second_max = max(b.first_max , a.second_max);
    }
    else{
        res.first_max = b.first_max;
        res.idx = b.idx;
        res.second_max = max(a.first_max , b.second_max);
    }
    return res;
}
const int N = 2e5 , K = 17;
node st[K+1][N + 10];
void clean(int n){
    for(int i = 0; i <= n + 3; i++){
        for(int j = 0; j <= K ; j++){
            st[j][i].clear();
        }
    }
}
vector<array<int,3>> ele(N);
node ans(int l , int r){
    if(r > N){
        r = N + 1;
    }
    int lg = __lg(r - l);
    return max(st[lg][l] , st[lg][r - (1<<lg)]);
}
void solve(){
    int n = Input::read_int();
    // cin >> n;
    clean(N);
    int maxi_ai = -1;
  
    for(int i = 0; i < n ; i++)  ele[i][1] = Input::read_int();
    for(int i = 0; i < n ; i++)  ele[i][0] = Input::read_int();
    for(int i = 0; i < n ; i++)  ele[i][2]  = i ;
 
    for(int i = 0; i < n; i++){
        st[0][ele[i][0]] = max(st[0][ele[i][0]] , node(ele[i][2] , ele[i][1]));
        maxi_ai = max(maxi_ai , ele[i][0]);
    }
    node def = node();
    for(int jump = 1; jump <= K ; jump++){
        for(int i = 0; i <= maxi_ai ; i++){
            st[jump][i] = max(st[jump-1][i] , (i + (1 << (jump - 1))  <= maxi_ai ? st[jump-1][i + (1<<(jump-1))] : def));
        }
    }
 
    vll final_ans(n);
    for(int x = 1; x <= maxi_ai; x++){
        ll first_max = 0 , second_max = 0 ,idx = -1;
        for(ll c = 1 ; c <= (maxi_ai+x-1)/x; c++){
            auto maxi = ans((c-1)*x+1 , c*x + 1);
            if(first_max < maxi.first_max*c){
                second_max = max(maxi.second_max*c , first_max);
                first_max = maxi.first_max*c;
                idx = maxi.idx;
                
            }
            else{
                second_max = max(maxi.first_max*c , second_max);
            }
        }
        if(first_max - second_max && idx  != -1 && final_ans[idx] < first_max - second_max) {

  
            final_ans[idx] = max(first_max - second_max , final_ans[idx]);
    
        }
    }
    for(auto x : final_ans) Output::write_int(x);
    Output::write_char('\n');
    Output::init_output();
}
int main(){
    FAST
    int t= Input::read_int();
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}