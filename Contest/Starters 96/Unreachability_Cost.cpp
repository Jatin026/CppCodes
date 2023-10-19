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
 struct SCC {
    int V = 0;
    vector<vector<int>> adj;
    vector<int> tour_index, low_link;
    int tour;
 
    vector<int> stack;
    vector<bool> in_stack;
 
    vector<vector<int>> components;
    vector<int> which_component;
 
    SCC(int v = 0) {
        init(v);
    }
 
    SCC(const vector<vector<int>> &_adj) {
        init(_adj);
    }
 
    void init(int v) {
        V = v;
        adj.assign(V, {});
    }
 
    void init(const vector<vector<int>> &_adj) {
        adj = _adj;
        V = int(adj.size());
    }
 
    void add_edge(int a, int b) {
        adj[a].push_back(b);
    }
 
    // Tarjan's algorithm.
    void dfs(int node) {
        tour_index[node] = tour++;
        low_link[node] = tour_index[node];
        stack.push_back(node);
        in_stack[node] = true;
 
        for (int neighbor : adj[node])
            if (tour_index[neighbor] < 0) {
                // neighbor is part of our subtree.
                dfs(neighbor);
                low_link[node] = min(low_link[node], low_link[neighbor]);
            } else if (in_stack[neighbor]) {
                // neighbor is a candidate for low_link.
                low_link[node] = min(low_link[node], tour_index[neighbor]);
            }
 
        if (low_link[node] == tour_index[node]) {
            // node is the highest node in an SCC, which includes everything on the stack up to it.
            components.emplace_back();
            vector<int> &component = components.back();
            int x;
 
            do {
                assert(!stack.empty());
                x = stack.back();
                stack.pop_back();
                in_stack[x] = false;
                which_component[x] = int(components.size()) - 1;
                component.push_back(x);
            } while (x != node);
        }
    }
 
    void build() {
        tour_index.assign(V, -1);
        low_link.resize(V);
        which_component.assign(V, -1);
 
        stack.clear();
        stack.reserve(V);
        in_stack.assign(V, false);
        tour = 0;
 
        // Note that Tarjan's algorithm provides the SCCs in reverse topological order.
        components = {};
 
        for (int i = 0; i < V; i++)
            if (tour_index[i] < 0)
                dfs(i);
    }
};
void solve(){
    int n , m;
    cin >> n >> m;
    SCC scc;
    scc.init(n);
    for (int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        --a;--b;
        scc.add_edge(a,b);
    }
    scc.build();
    vi cnt(n);
    debug(scc.which_component)
    for (int i = 0; i < n; i++)
    {
        debug(scc.which_component[i])
        cnt[scc.which_component[i]]++;
    }
    sort(rbegin(cnt),rend(cnt));
    vll sum_ele(n+1) , sq_sum(n+1);
    for (int i = 0; i < n; i++)
    {
        sum_ele[i+1] = sum_ele[i];
        sq_sum[i+1] = sq_sum[i];
        sum_ele[i+1] += cnt[i];
        sq_sum[i+1] += (sum_ele[i])*(cnt[i]);
    }
    debug(cnt)
    auto check = [&](ll x , ll cost) -> bool {
        auto it = lb(all(sum_ele) , x);
        int prev = it-begin(sum_ele) - 1;
        ll tot = sq_sum[prev] + (x - sum_ele[prev])*(sum_ele[prev]);
        return (tot  <= cost);
    };
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll k;
        cin >> k;
        int l = 0 , r = sum_ele[n] , mid , ans = 0;
        while(l <= r){
            mid = (l+r)/2;
            if(check(mid,k)){
                l = mid + 1;
                ans = mid;
            }
            else r = mid - 1;
        } 
        cout << ans << nline;
    }
    
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