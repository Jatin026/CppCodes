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
const ll INF = 1e18; 
struct segtree{
    int size;
    vll sums;
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        sums.assign(2*size,0);
    }
    void build(vector<int> &a,int x , int lx , int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                sums[x]=a[lx];
            }
            return;
        }
        else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
        }
        sums[x]=min(sums[2*x+1],sums[2*x+2]);
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void set(int i , int v , int x , int lx, int rx){
        if(rx-lx==1){
            sums[x]=v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=min(sums[2*x+1],sums[2*x+2]);
    }
    void set(int i , int v){
        set(i,v,0,0,size);
    }
    ll sum(int l , int r, int x , int lx , int rx){
        if(l>=rx || lx>=r) return INF;
        if(l<=lx && r>=rx) return sums[x];
         
            int m = (lx+rx)/2;
            ll s1=sum(l,r,2*x+1,lx,m);
            ll s2=sum(l,r,2*x+2,m,rx);
            return min(s1,s2);
        
    }
    ll sum(int l , int r){
        return sum(l,r,0,0,size);
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
const int N = 1e5 + 7;
vvi frq(N);
vector<bool> possible(N,1);
void solve(){
    int n;
    cin >> n;
    vi v(n);
    set<int> s;
    for(auto &x : v) cin >> x;
    for (int i = 0; i < n; i++)
    {
        s.insert(v[i]);
        frq[v[i]].pb(i);
    }

    vector<array<int,3>> querries;
    // vi possible ;
    for (int i = 1; i < n+2; i++)
    {
        if(!s.count(i)) possible.pb(i);
        for (int j = 1; j< frq[i].size(); j++)
        {
            if(frq[i][j+1] - frq[i][j] > 1){
                querries.emplace_back(array<int,3> {frq[i][j-1]+1,frq[i][j],i});
            }
        }
        if(!frq[i].empty()){
            querries.emplace_back(array<int,3> {0,frq[i][0],i});
            querries.emplace_back(array<int,3> {frq[i][((int)frq[i].size()-1)]+1,n-1,i});
    }
    }
    sort(all(querries),[](array<int,3> a , array<int,3> b){
        return (a[1] < b[1]);
    });  
    segtree st;st.init(N);
    int r = 0;
    for(auto x : querries){
        while(r <= x[1]){
            st.set(v[r],r+1);
            r++;
        }
        debug(x[0]) debug(x[1]) debug(x[2])
        debug(r)
        ll q = st.sum(1,x[2]+1);debug(q)
        if(q >= x[0]) possible[x[2]] = 0;
        debug(possible[x[0]])
        
    }
    for (int i = 1; i < N; i++)
    {
        if(possible[i]){
            cout << i;
            return;
        }
    }
    
    // cout << possible[0];
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