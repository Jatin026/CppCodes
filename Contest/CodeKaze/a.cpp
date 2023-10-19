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
// template <class T, class V> void _print(map <T, V> v) {cerr << '['; for (auto i : v) {_print(i); cerr << ' ';} cerr << ']';}
 
struct segtreea{
    int size;
    vll operations;
    vll sums;
    ll NO_OPERATIONS = LLONG_MAX;
    ll Neutral_Element= 0; 
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        sums.assign(2*size,0);
        operations.assign(2*size,0);
    }
    ll modify_Op(ll a , ll b , ll len){
        if(b ==  NO_OPERATIONS) return a;
        if(a == NO_OPERATIONS) return b*(len&1);
        return a^(b*(len&1));
    }
    void apply_mod_op(ll &a , ll b , ll len){
        a=modify_Op(a,b,len);
    }
    ll calc_Op(ll a , ll b){
        return a&b ;
    }
    void propagate(int x , int lx ,int rx){
        if(rx - lx == 1) return;
        int m = (lx + rx )/2;
 
        apply_mod_op(sums[2*x+1], operations[x]  , m -lx);
        apply_mod_op(sums[2*x+2] , operations[x] , rx -m );
        apply_mod_op(operations[2*x+2] , operations[x] , 1 );
        apply_mod_op(operations[2*x+1] , operations[x] , 1  );
        operations[x]=NO_OPERATIONS;
 
    }
    void modify (int l , int r , int v, int x , int lx , int rx){
        propagate(x , lx , rx );
        if(lx>=r || l>=rx) return ;
        if(lx >= l && rx <= r){
            apply_mod_op(operations[x] , v , 1 ) ;
            apply_mod_op(sums[x] ,  v , rx-lx) ;
            return;
        }
        int m  = (lx+rx)/2;
        modify(l,r,v,2*x+1,lx,m);modify(l,r,v,2*x+2,m,rx);
        sums[x]=calc_Op(sums[2*x+1], sums[2*x+2] );
        apply_mod_op(sums[x], operations[x],rx-lx);
    }
    void modify (int l ,int r , int v){
        modify(l , r , v , 0 , 0 , size);
    }
    ll calc(int l ,int r , int x , int lx ,int rx){
        propagate(x,lx,rx);
        if(lx>=r || rx<=l) return NO_OPERATIONS;
        if(lx>=l && rx<=r){
            return sums[x];
        }
        int m = (lx+rx)/2;
        auto m1 = calc(l,r,2*x+1, lx , m);
        auto m2 = calc(l,r, 2*x+2 , m , rx);
        auto res = calc_Op(m1,m2);
        apply_mod_op(res, operations[x], min(r,rx) -  max(lx ,l));
        return res;
    }
    ll calc (int l , int r ){
        return calc(l,r , 0 , 0 ,size);
    }
    void build(vector<ll> &a,int x , int lx , int rx){
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
        sums[x]=calc_Op(sums[2*x+1],sums[2*x+2]);
    }
   
    
     
};
struct segtreeb{
    int size;
    vll operations;
    vll sums;
    ll NO_OPERATIONS = LLONG_MAX;
    ll Neutral_Element= 0; 
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        sums.assign(2*size,0);
        operations.assign(2*size,0);
    }
    ll modify_Op(ll a , ll b , ll len){
        if(b ==  NO_OPERATIONS) return a;
        if(a == NO_OPERATIONS) return b*(len&1);
        return a^(b*(len&1));
    }
    void apply_mod_op(ll &a , ll b , ll len){
        a=modify_Op(a,b,len);
    }
    ll calc_Op(ll a , ll b){
        return a^b ;
    }
    void propagate(int x , int lx ,int rx){
        if(rx - lx == 1) return;
        int m = (lx + rx )/2;
 
        apply_mod_op(sums[2*x+1], operations[x]  , m -lx);
        apply_mod_op(sums[2*x+2] , operations[x] , rx -m );
        apply_mod_op(operations[2*x+2] , operations[x] , 1 );
        apply_mod_op(operations[2*x+1] , operations[x] , 1  );
        operations[x]=NO_OPERATIONS;
 
    }
    void modify (int l , int r , int v, int x , int lx , int rx){
        propagate(x , lx , rx );
        if(lx>=r || l>=rx) return ;
        if(lx >= l && rx <= r){
            apply_mod_op(operations[x] , v , 1 ) ;
            apply_mod_op(sums[x] ,  v , rx-lx) ;
            return;
        }
        int m  = (lx+rx)/2;
        modify(l,r,v,2*x+1,lx,m);modify(l,r,v,2*x+2,m,rx);
        sums[x]=calc_Op(sums[2*x+1], sums[2*x+2] );
        apply_mod_op(sums[x], operations[x],rx-lx);
    }
    void modify (int l ,int r , int v){
        modify(l , r , v , 0 , 0 , size);
    }
    ll calc(int l ,int r , int x , int lx ,int rx){
        propagate(x,lx,rx);
        if(lx>=r || rx<=l) return Neutral_Element;
        if(lx>=l && rx<=r){
            return sums[x];
        }
        int m = (lx+rx)/2;
        auto m1 = calc(l,r,2*x+1, lx , m);
        auto m2 = calc(l,r, 2*x+2 , m , rx);
        auto res = calc_Op(m1,m2);
        apply_mod_op(res, operations[x], min(r,rx) -  max(lx ,l));
        return res;
    }
    ll calc (int l , int r ){
        return calc(l,r , 0 , 0 ,size);
    }
    void build(vector<ll> &a,int x , int lx , int rx){
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
        sums[x]=calc_Op(sums[2*x+1],sums[2*x+2]);
    }
   
    
     
};
void solve(){
    int n , q;
    cin >> n >> q;
    vi a(n);
    vvi queries(q,vi(3));
    for(auto &x : a) cin >> x;
    for (int i = 0; i < q; i++)
    {
        for(auto &x : queries[i]) cin >> x;
    }
    segtreea s ; segtreeb f;
    s.init(n);f.init(n);
    for (int i = 0; i < n; i++)
    {
        s.modify(i,i+1,a[i]);f.modify(i,i+1,a[i]);
    }
    
    vector<int> ans(q);
    for (int k = 0; k < q; k++)
    {
        auto x = queries[k];
         
        s.modify(x[0],x[1]+1,x[2]);
        f.modify(x[0],x[1]+1,x[2]);
        ans[k] = s.calc(x[0],x[1]+1) + f.calc(x[0],x[1]+1);
    }
    
    for(auto x: ans) cout << x << " ";
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