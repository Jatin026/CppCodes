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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> val(n);
    for(auto &x : val){
        cin>>x;
    }
    vll dp(n+10,-1e13);
    string str(n+10,'z');
    vector<string> v(n+10,str);
    v[0]="";
    dp[0]=0;
    for (int i = 1; i <= n; i++)
    {
        string comp="";
        for (int j = i; j > 0; j--)
        {
            if(dp[i]<=dp[j]){
                if(dp[i]==dp[j]) v[i]=min(v[i],v[j]);
                else v[i]=v[j];
                dp[i]=max(dp[i],dp[j]);
                debug(dp[i])
            }
            if(dp[i]<0){
                v[i]="";
                dp[i]=0;
            }
            comp+=s[j-1];
            reverse(all(comp)); 
            
            if(comp>v[i-comp.size()] && val[comp.size()-1]+dp[i-comp.size()]==dp[i]){
                v[i]=min(comp,v[i]);
              
            }
            else if(comp>v[i-comp.size()] && val[comp.size()-1]+dp[i-comp.size()]>dp[i]){
                v[i]=comp;
                dp[i]=dp[i-comp.size()]+val[comp.size()-1] ;
            }
          
            if(dp[i]<=val[comp.size()-1] ){
                if(dp[i]==val[comp.size()-1]) v[i]=min(v[i],comp);
                else v[i]=comp;
                dp[i]=max(dp[i],val[comp.size()-1]);
            }
            reverse(all(comp));
            debug(dp[i])
            debug(v[i])
        }
       
    }
    cout<<dp[n]<<nline;
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