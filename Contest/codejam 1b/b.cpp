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
#define print(ca,x) cout<<"Case #"<<ca<<": "<<x<<nline
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
void solve(int ca){
    int n,p;
    cin>>n>>p;
    int arr[n][p];
    ll ans=LONG_LONG_MAX;
    for (int i = 0; i < n; i++)
    {
        int maxi=-1;
        for (int j = 0; j < p; j++)
        {
            cin>>arr[i][j];
            maxi=max(arr[i][j],maxi);
        }
 
    }
    for (int x = 0; x < (1<<n); x++)
    {
        string recipe = binarystring(12,x);
        reverse(all(recipe));
        int ind=0;
        ll c=0;
        ll maxi=0;
        for (int l = 0; l < n; l++)
        {
        
        vi v(p);
        for (int i = 0; i < p; i++)
        {
            v[i]=arr[l][i];
        }
        sort(all(v));
      
        if(recipe[ind]=='1'){
        for (int i = 0; i < p; i++)
        {
            c+=abs(maxi -v[i]);
            maxi =v[i];
        }
        }
        else{
        for (int i = p-1; i >-1; i--)
        {
            c+=abs(maxi-v[i]);
            maxi=v[i];
        }
        }
            ind++;
        }
        ans=min(ans,c);
    }
    
    print(ca,ans);
     
     
    
}
int main(){
    FAST
    int t=1;
    cin>>t;
    int ca=1;
    while(t--){
        solve(ca);
        ca++;
    }
    return 0;
}