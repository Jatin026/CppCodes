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
struct FenwickTreeMax {
    vector<int> bit;
    int n;
    const int INF = (int)1e9;

    FenwickTreeMax(int n) {
        this->n = n;
        bit.assign(n, -INF);
    }

    FenwickTreeMax(vector<int> a) : FenwickTreeMax(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmax(int r) {
        int ret = -INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
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
//void _print(Mint t) {cerr << t;}
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
// template <class T, class V> void _print(array <T, V> v) {cerr << '['; for (auto i : v) {_print(i); cerr << ' ';} cerr << ']';}
// const int inf = 1e9;
void solve(){
    int n;
    cin >> n;
    vpr range;
    map<int,int> comp;
    for (int i = 0; i < n; i++)
    {
        int a , b;
        cin >> a >> b;
        comp[a]++;comp[b]++;
        range.emplace_back(a,b);
    }
    int ind = 1;
    for(auto &x : comp) x.second = ind++;
    for(auto &x : range){
        x.first = comp[x.first];
        x.second = comp[x.second];
    }
    auto intersect = [&](pr a , pr b) -> bool {
        if(max(b.first,a.first) > min(a.second,b.second)) return 0;
        return 1;
    };
    auto cmp = [&](pr a , pr b) -> bool {
        return (a.second < b.second);
    };
    vector<int> dp(n);
    sort(all(range),cmp);
    vector<FenwickTreeMax> pre;
    // vi val(2*n+10,-1);
    FenwickTreeMax ft(2*n+3);
    for (int i = 0; i < n; i++)
    {
        ft.update(range[i].second,i);
        pre.pb(ft); 
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i-1];
        for (int j = 0; j < i; j++)
        {
            if(intersect(range[i],range[j])){
                if(j == 0){
                    dp[i] = max(dp[i] , 2 );
                }
                else{
                    int val = min(range[j].first,range[i].first) ;
                    int ind  = pre[j-1].getmax(val-1);
                    if(ind  == -ft.INF) dp[i] = max(dp[i] , 2 );
                    else dp[i]  = max(dp[i],  2 + dp[ind]);
                }
            }
        }
        debug(dp)
        ans = max(ans , dp[i]);
    }
    cout << n -  ans << nline;
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