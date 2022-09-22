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
    int n,m,k;
    cin>>n>>m>>k;
    vvi dp2(72,vi(71,-1e9));
    for (int i = 0; i < 71; i++)
    {
        dp2[i][0]=0;
    }
    
    for (int j = 1; j <= n; j++)
    {
        vector<vvi> dp(72,vvi (72,vi(40,-1e9)));
        for (int i = 0; i < 71; i++)
        {
            dp[i][0][0]=0; 
        }
        
        for (int i = 1; i <= m; i++)
        {
            int val;
            cin>>val;
            for (int l = 0; l < 71; l++)
            {
                for (int cnt = 0; cnt <= m/2; cnt++)
                {
                    dp[i][l][cnt]=max(dp[i-1][l][cnt],dp[i][l][cnt]);
                }
                
            }
            for (int rem = 0; rem < k; rem++)
            {
                
                for (int cnt = 1; cnt <= m/2; cnt++)
                {
                    dp[i][(rem+val%k)%k][cnt]=max(dp[i-1][rem][cnt-1]+val,dp[i][(rem+val%k)%k][cnt]);
                } 
               
            }
            
            
        }
        for (int l = 0; l < k; l++)
        {
            dp2[j][l]=max(dp2[j-1][l],dp2[j][l]);
        }
        debug(dp[j][9])
        for (int rem = 0; rem < k; rem++)
        {
            int ans=-1e9;
            for (int cnt = 1; cnt <= m/2; cnt++)
            {
                ans=max(ans,dp[m][rem][cnt]);
            }
          
            for (int l = 0; l < k; l++)
            {
                dp2[j][(l+rem)%k]=max(dp2[j-1][l]+ans,dp2[j][(l+rem)%k]);
            }
        }
        
    }
    debug(dp2)
    cout<<dp2[n][0]<<nline;
    
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