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
const int N = 6e4 + 10;
const int inf = 1e9;
void solve(){
    int n , r;
    cin >> n >> r;
    vpr pos , neg;
    for (int i = 0; i < n; i++)
    {
        int a , b;
        cin >> a >> b;
        if(b >= 0){
            pos.emplace_back(a,b);
        }
        else{
            neg.emplace_back(a,b);
        }
    }
    int ans = 0;
    sort(all(pos));
    for(auto x : pos){
        if(x.first > r){
            break;
        }
        ans++;
        r += x.second;
    }
    auto cmp = [&](pr a , pr b) -> bool {
        return (max(a.first,-a.second) + a.second > max(b.first,-b.second) + b.second);
    };
    sort(all(neg),cmp);
    vector<int> dp(N,-inf);
    dp[r] = 0;
    debug(neg)
    vector<vector<bool>> par(neg.size(), vector<bool> (N));
    for (int i = 0; i < neg.size(); i++)
    {
        vector<int> new_dp(dp);
        for (int wt = 0; wt < N; wt++)
        {
            
            if(neg[i].first <= wt && wt + neg[i].second >= 0 && dp[wt] > -1 && new_dp[wt + neg[i].second] < 1 + dp[wt]) {
                new_dp[wt + neg[i].second] = 1 + dp[wt];
                par[i][wt + neg[i].second] = 1;
            }
        }
        swap(new_dp,dp);
    }
   
    
    int g = 0;
    for (int i = 0; i < N; i++)
    {
        if(dp[i]){
            vpr temp;
            int wt = i;
            int ind = (int)neg.size() - 1;
            while(ind != -1){
                if(par[ind][wt]){
                    wt -= neg[ind].second;
                    temp.pb(neg[ind]);
                }
                --ind;
            }
            wt = i;
            int cnt = temp.size();
           
            vi vis(temp.size());
            while(cnt){
                bool flag = true;
                for (int j = 0; j < temp.size(); j++)
                {
                    if(!vis[j] && wt - temp[j].second >= temp[j].first){
                        vis[j] = 1;
                        wt -= temp[j].second;
                        flag = false;
                        break;
                    }
                     
                }
                if(flag) break;
                --cnt;
            }
            // debug(cnt)
            if(cnt  == 0){
                g = max(g , ans + (int)temp.size());
            }
        }
    }
    cout << g;
         
   
    // cout << g;
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