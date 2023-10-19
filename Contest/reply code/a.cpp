#include<bits/stdc++.h>
#include<stdio.h>
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
#define ff first 
#define ss second 
ifstream in("input.txt");
ofstream out("swarm.txt");
void solve(){
    int n , m ,k;
    cin >> m >> n >> k;
    vpr snake(k);
    for(auto &x : snake) cin >> x.first;
    for (int i = 0; i < k; i++)
    {
        snake[i].second = i+1;
    }
    vector<vector<string>> val(n,vector<string> (m));
    for(auto &x : val){
        for(auto &y : x) cin >> y;
    }
    ll tot_sum = 0;
    vector<array<int,3>> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(val[i][j] != "*"){
                tot_sum += stoi(val[i][j]);
                start.emplace_back(array<int,3> {stoi(val[i][j]),i,j});
            }
        }
    }
    auto cmp = [&](array<int,3> a , array<int,3> b) -> bool {
        return (a[0] > b[0]);
    };
    
    int move = 0 , inf = 1e9;
    sort(all(start),cmp);
    auto possible = [&](int i , int j) -> bool {
        if(i < 0) i += n;
        if(j < 0) j += m;
        if(i >= n) i -= n;
        if(j >= m) j -= m;
        assert((i>=0 && i < n));
        assert((j>=0 && j < m));
        if(val[i][j] == "*" || val[i][j] == "@") return 0;
        else return 1;
    };
    auto value = [&](int i , int j) -> int {
        if(i < 0) i += n;
        if(j < 0) j += m;
        if(i >= n) i -= n;
        if(j >= m) j -= m;
        assert((i>=0 && i < n));
        assert((j>=0 && j < m));
        return stoi(val[i][j]);
    };
    auto cmp2 = [&](pr a , pr b) -> bool {
        return (a.first > b.first);
    };
    
    vector<char> dir = {'U','L','R','D'};
    vector<pr> dist  = {{-1,0},{0,-1},{0,1},{1,0}};
    vector<vector<char>> ans(k+1);
    ll score = 0;
     
    function<void(int , int , int)> dfs = [&] (int i ,int j , int len) -> void {
        if(i < 0) i += n;
        if(j < 0) j += m;
        if(i >= n) i -= n;
        if(j >= m) j -= m;
        score += value(i,j);
        val[i][j] = "@";
        if(len == 1) return;
        int maxi = -inf;
        for (int ind = 0; ind < 4; ind++)
        {
            if(possible(dist[ind].ff+i,dist[ind].ss+j)) maxi = max(maxi , value(dist[ind].ff+i,dist[ind].ss+j));
        }
        if(maxi == -inf) return ;
        
        for (int ind = 0; ind < 4; ind++)
        {
            if(possible(dist[ind].ff+i,dist[ind].ss+j) && maxi == value(dist[ind].ff+i,dist[ind].ss+j)){
                ans[move].pb(dir[ind]);
                dfs(dist[ind].ff+i,dist[ind].ss+j,len-1);
                return;
            }  
        }
        return; 
    };

    sort(all(snake),cmp2);
   
    int ind = 0;
    map<int,pr> start_node;
    for (int i = 0; i < k; i++)
    {
        move = snake[i].second;
        while(ind < start.size() && !possible(start[ind][1],start[ind][2])){
           ind++;
           
        }
        if(ind  == start.size()) break;
    
        dfs(start[ind][1],start[ind][2],snake[i].first);
        start_node[move] = make_pair(start[ind][1] , start[ind][2]);
        ind++;
    }
    
    string answer = "";
    for (int i = 1; i <= n; i++)
    {
        if(start_node.count(i)){
            //out << start_node[i].ss << " " << start_node[i].ff << " ";
            answer += to_string(start_node[i].ss) + " " + to_string(start_node[i].ff) + " ";
            int length = ans[i].size();
       
            for (int j = 0; j < length-1; j++)
            {
                answer += (ans[i][j]) ;
                answer += " ";
                //out << ans[i][j]  << ' ';
            }
            answer += (ans[i][length-1]);
            //out << ans[i][length-1];
        }
        answer += "\n";
        //out << nline;
    }
    cout << answer;
    // cout << score;
     
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