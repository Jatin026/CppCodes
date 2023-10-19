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

struct LCA {
    int n;
    vector<vector<int>> adj;

    int block_size, block_cnt;
    vector<int> first_visit;
    vector<int> euler_tour;
    vector<int> height;
    vector<int> log_2;
    vector<vector<int>> st;
    vector<vector<vector<int>>> blocks;
    vector<int> block_mask;

    void dfs(int v, int p, int h) {
        first_visit[v] = euler_tour.size();
        euler_tour.push_back(v);
        height[v] = h;

        for (int u : adj[v]) {
            if (u == p)
                continue;
            dfs(u, v, h + 1);
            euler_tour.push_back(v);
        }
    }

    int min_by_h(int i, int j) {
        return height[euler_tour[i]] < height[euler_tour[j]] ? i : j;
    }

    LCA(vvi &v ,int root) {
        // get euler tour & indices of first occurences
        adj  = v;
        n = v.size();
        first_visit.assign(n, -1);
        height.assign(n, 0);
        euler_tour.reserve(2 * n);
       
        dfs(root, -1, 0);

        // precompute all log values
        int m = euler_tour.size();
        log_2.reserve(m + 1);
        log_2.push_back(-1);
        for (int i = 1; i <= m; i++)
            log_2.push_back(log_2[i / 2] + 1);

        block_size = max(1, log_2[m] / 2);
        block_cnt = (m + block_size - 1) / block_size;

        // precompute minimum of each block and build sparse table
        st.assign(block_cnt, vector<int>(log_2[block_cnt] + 1));
        for (int i = 0, j = 0, b = 0; i < m; i++, j++) {
            if (j == block_size)
                j = 0, b++;
            if (j == 0 || min_by_h(i, st[b][0]) == i)
                st[b][0] = i;
        }
        for (int l = 1; l <= log_2[block_cnt]; l++) {
            for (int i = 0; i < block_cnt; i++) {
                int ni = i + (1 << (l - 1));
                if (ni >= block_cnt)
                    st[i][l] = st[i][l-1];
                else
                    st[i][l] = min_by_h(st[i][l-1], st[ni][l-1]);
            }
        }

        // precompute mask for each block
        block_mask.assign(block_cnt, 0);
        for (int i = 0, j = 0, b = 0; i < m; i++, j++) {
            if (j == block_size)
                j = 0, b++;
            if (j > 0 && (i >= m || min_by_h(i - 1, i) == i - 1))
                block_mask[b] += 1 << (j - 1);
        }

        // precompute RMQ for each unique block
        int possibilities = 1 << (block_size - 1);
        blocks.resize(possibilities);
        for (int b = 0; b < block_cnt; b++) {
            int mask = block_mask[b];
            if (!blocks[mask].empty())
                continue;
            blocks[mask].assign(block_size, vector<int>(block_size));
            for (int l = 0; l < block_size; l++) {
                blocks[mask][l][l] = l;
                for (int r = l + 1; r < block_size; r++) {
                    blocks[mask][l][r] = blocks[mask][l][r - 1];
                    if (b * block_size + r < m)
                        blocks[mask][l][r] = min_by_h(b * block_size + blocks[mask][l][r], 
                                b * block_size + r) - b * block_size;
                }
            }
        }
    }

    int lca_in_block(int b, int l, int r) {
        return blocks[block_mask[b]][l][r] + b * block_size;
    }

    int lca(int v, int u) {
        int l = first_visit[v];
        int r = first_visit[u];
        if (l > r)
            swap(l, r);
        int bl = l / block_size;
        int br = r / block_size;
        if (bl == br)
            return euler_tour[lca_in_block(bl, l % block_size, r % block_size)];
        int ans1 = lca_in_block(bl, l % block_size, block_size - 1);
        int ans2 = lca_in_block(br, 0, r % block_size);
        int ans = min_by_h(ans1, ans2);
        if (bl + 1 < br) {
            int l = log_2[br - bl - 1];
            int ans3 = st[bl+1][l];
            int ans4 = st[br - (1 << l)][l];
            ans = min_by_h(ans, min_by_h(ans3, ans4));
        }
        return euler_tour[ans];
    }
};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  // FOR RANDOM NUMBER GENERATION
ll random(int min,int max){return rng()%(max-min + 1) + min;}


void solve(){
    int n , root ;
    cin >> n >> root;
    vi col(n);
    --root;
    col[0] = root;
    for (int i = 0; i < n-1; i++)
    {
        cin >> col[i+1];
        --col[i+1];
    }
    vvi adj(n);
    for (int i = 0; i < n-1; i++)
    {
        int a , b ;
        cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);    
    }
    int ans = n+1;
    LCA lca(adj,root);
    vi vis(n,0);
    vi d(n,n);
    d[root] = 0;
    queue<int> q;
    q.push(root);
    vis[root] = 1;
   
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : adj[v]){
            if(vis[u]) continue;
            if(d[u] >= ans || d[v] > d[u]) continue;
            q.push(u);
            vis[u] = 1;
            d[u] = min(d[u] , 1 + d[v]);
        }
    }
     debug(d)
    fill(all(vis),0);
    for (int i = 1; i < n; i++)
    {
        int s = col[i];
        vi passed{s};
        d[s] = 0;
        q.push(s);
        vis[s] = 1;
        while(!q.empty()){
            int v = q.front();
            passed.emplace_back(v);
            q.pop();
            for(auto u : adj[v]){
                if(vis[u] || d[u]>=ans) continue;
                if(d[v] + 1 >= d[u] ) {
                    ans = min(ans,d[u] + 1 + d[v]);
                }
                q.push(u);
                vis[u] = 1;
                // ans = min(ans,d[u] + 1 + d[v]);
                d[u] = min(d[u] , 1 + d[v]);
            }
        }
        debug(d)
        for(auto x : passed){
            vis[x] = 0;
        }
        cout << ans << " ";
    }
    cout << nline;
}
int main(){
    FAST
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}