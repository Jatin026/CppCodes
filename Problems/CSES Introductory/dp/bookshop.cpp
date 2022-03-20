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

const int M = 1e9+7;
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
ll BinExpItr(ll a , ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}

const int N=1e3+3;
const int W = 1e5+2;
int dp[N][W];
int cnt(int n, int x,int price[], int page[]){
    if(n==0 ||  x <= 0) return 0;
    if(dp[n][x]!=-1) return dp[n][x];
    int ans=(cnt(n-1,x,price,page));
    if(price[n]>x) return dp[n][x]=ans;
    else return dp[n][x]=(max(ans,(page[n]+(cnt(n-1,x-price[n],price,page)))));
}
void solve(){
    int n,x;
    cin>>n>>x;
    int price[n+1],page[n+1];
    page[0]=0;
    price[0]=0;
    
    for (int i = 1 ; i <= n ; i++)
    {
        cin>>price[i];
    }
    for (int i = 1; i <= n ; i++)
    {
        cin>>page[i];
    }
    cout<<cnt(n,x,price,page);
}
int main(){
    FAST
    mem1(dp);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}