#include<bits/stdc++.h>
#include<chrono>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>   
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
 
 
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
 
#define pr             pair<int,int>
#define vi             vector<int>
#define vll            vector<ll>
#define vvi            vector<vi>
#define vpr            vector<pr> 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define nline '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
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
const int N = 3005;
const ll INF = 1e17;
void solve(){
    int n;
    cin >> n;
    vi v(3*n);
    ordered_multiset<int> fs  ;
    multiset<int> bs;
    for(auto &x : v){
        cin >> x;
    }
    if(n <= 1000){
        vector<vll> dp(N,vll (N,-INF));
        dp[0][0] = 0;
        for (int i = 0; i < 3*n; i++)
        {
            int x ;
            x = v[i];
            for (int j = 0; j < N - 500; j++)
            {
                dp[i+1][j] = max(dp[i+1][j] , dp[i][j]);
                dp[i+1][j+1] = max(dp[i+1][j+1] , dp[i][j] + (j >= n  ?  -x : x)); 
            }
        }
        cout << dp[3*n][2*n];
        return;
    }


    
    ll ans = 0 , curr = 0;
    for (int i = 0; i < 2*n; i++)
    {
        fs.insert(-v[i]);
    }
    for (int i = 2*n; i < 3*n; i++)
    {
        bs.insert(v[i]);
        curr -= v[i];
    }
    for (int i = 0; i < n; i++)
    {
        curr += -(*fs.find_by_order(i));
    }
    ans = curr;
    for (int i = 2*n-1; i >= n; i--)
    {
        int c = fs.order_of_key(-v[i]);
        fs.erase(fs.find_by_order(fs.order_of_key(-v[i])));
        if(c < n) {
            curr -= v[i];
            curr += -(*fs.find_by_order(n-1));
        }
        
        if((*bs.rbegin()) > v[i]){
            curr += (*bs.rbegin());
            bs.erase((bs.find((*bs.rbegin()))));
            curr -= v[i];
            bs.insert(v[i]);
        }
        ans = max(ans , curr);
    }
    cout << ans;
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

 