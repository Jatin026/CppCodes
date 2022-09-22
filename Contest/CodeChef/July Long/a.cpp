#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(s) s.begin(),s.end()
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define binarystring(n,x) bitset<n> (x).to_string()
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
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
ll ceil(ll x,ll y){
    return (x+y-1)/y;
}
void solve(){
    int n;
    cin>>n;
    vi v(n+1);
    for(auto &x : v){
        cin>>x;
    }
    vector<tuple<int,int,int>> ans;
    for (int a = 0; a <= min(v[0],n); a++)
    {
        bool flag=true;
        for (int i = 1; i <= n; i*=2)
        {
            {
                if(v[i]!=(((a)^(i))  + ((v[0]-a)^(i)) + i )){
                    flag=false;
                    break;
            }
            }
        }
        if(flag && v[0]-a<=n){

            auto x = make_tuple(a,0,v[0]-a);
            ans.pb(x);
            cout<<get<0>(x)<<" "<<get<1>(x)<<" "<<get<2>(x)<<nline;
            return;
            }
        if(v[0]>=a+1){
    flag=true;
    for (int i = 1; i <= n; i*=2)
    {
    {
        if(v[i]!=(((a)^(i)) +(1^i) + ((v[0]-a-1)^(i)))){
            flag=false;
            break;
        }
    }
    }
        if(flag && v[0]-a-1<=n){
            auto x = make_tuple(a,1,v[0]-a-1);
            ans.pb(x);
            cout<<get<0>(x)<<" "<<get<1>(x)<<" "<<get<2>(x)<<nline;
            return;
            
    }
        }
                if(v[0]>=a+n){
    flag=true;
    for (int i = 1; i <= n; i*=2)
    {
    {
        if(v[i]!=(((a)^(i)) +(n^i) + ((v[0]-a-n)^(i)))){
            flag=false;
            break;
        }
    }
    }
        if(flag && v[0]-a-n<=n){

            auto x = make_tuple(a,n,v[0]-a-n);
            ans.pb(x);
            cout<<get<0>(x)<<" "<<get<1>(x)<<" "<<get<2>(x)<<nline;
            return;
    }
        }
    }
  
    
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