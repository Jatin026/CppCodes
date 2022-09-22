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
void solve(){
    int n,m;
    cin>>n>>m;
    vi v(n);
    multiset<int> ms;
    for(auto &x : v){
        cin>>x;
        ms.insert(x);
    }
    vpr ind;
    string s(m,'B');
    for (int i = 0; i < n; i++)
    {
        ind.pb({v[i]-1,i});
        ind.pb({m-v[i],i});
    }
    sort(all(ind));
    vi vis(1000,0);
    // for (int i = 0; i < m; i++)
    // {
    //     if(i<=m/2){
    //     if(ms.find(i+1)!=ms.end() && s[i]=='B'){
    //         s[i]='A';
    //         ms.erase(ms.find(i+1));
    //     }
    //     else if (ms.find(m-i)!=ms.end() && s[m-i-1]=='B'){
    //         s[m-i-1]='A';
    //         ms.erase(ms.find(m-i));
    //     }
    //     }
    //     else{
    //         if (ms.find(m-i)!=ms.end() && s[m-i-1]=='B'){
    //         s[m-i-1]='A';
    //         ms.erase(ms.find(m-i));
           
    //     }
    //     else if(ms.find(i+1)!=ms.end() && s[i]=='B'){
    //         s[i]='A';
    //         ms.erase(ms.find(i+1));
    //     }
    //     }
    //     debug(s)
    // }
    
    // debug(ind)
    for (int i = 0; i < ind.size(); i++)
    {
        if(!vis[ind[i].second] && s[ind[i].first]=='B'){
            s[ind[i].first]='A';
            vis[ind[i].second]=1;
        }
    }
    
    cout<<s<<nline;
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