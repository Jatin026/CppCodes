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
    int n,q;
    cin>>n>>q;
    vvi  v(n+1,vi (32,-1));
    vvi queries(n+1);
    for (int i = 0; i < q; i++)
    {
        int y,j,x;
        cin>>y>>j>>x;
        if(y==j){
            for (int l = 0; l < 32; l++)
        {
            if(!(x&(1<<l))){
                v[y][l]=0;
                v[j][l]=0;
            }
            else{
                v[y][l]=1;
                v[j][l]=1;
            }
        }
             
        }
        else{
            for (int l = 0; l < 32; l++)
            {
                if(!(x&(1<<l))){
                    v[y][l]=0;
                    v[j][l]=0;
                }
                else{
                    if(v[y][l]==-1) v[y][l]=2;
                    if(v[j][l]==-1) v[j][l]=2;
                }
            }

            queries[y].pb(j);
            queries[j].pb(y);
        }
    }
  
 
 
    for (int i = 1; i <= n; i++)
    {
        for(auto x : queries[i]){
            for (int j = 31; j > -1; j--)
            {
                if(v[x][j]==0 && v[i][j]==2){
                    v[i][j]=1;
                }
            }
            
        }
        for (int j = 0; j < 32; j++)
        {
            if(v[i][j]==2) v[i][j]=0;
        }
        
        
        
    }
    debug(v)
    for (int i = 1; i <= n; i++)
    {
        int val=0;
        for (int j = 0; j < 32; j++)
        {
            
            if(v[i][j]==1) val+=(1<<j);
        }
        cout<<val<<" ";
        
    }
    cout<<nline;
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