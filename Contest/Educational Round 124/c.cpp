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
void solve(){
    int n,b1=-1;
    cin>>n;
    ll sum=INT_MAX;
    vll a(n),b(n);
    for( auto &x: a){
        cin>>x;
    }
    for( auto &x: b){
        cin>>x;
    }
    ll cnt1=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(cnt1>abs(-a[0]+b[i])){
            cnt1=abs(b[i]-a[0]);
            b1=i;
        }     
    }
     
    
    ll cnt2=INT_MAX,a1;
 
        for (int i = 0; i < n; i++)
    {
        if(cnt2>abs(-b[0]+a[i])){
            cnt2=abs(b[0]-a[i]);
            a1=i;
        }
        
    }
  
     
    ll cnt3=INT_MAX,b2;
     
        for (int i = n-1; i >-1 ; --i)
    {
        if(cnt3>abs(-a[n-1]+b[i])){
            cnt3=abs(b[i]-a[n-1]);
            b2=i;
        }
        
    }
         
  
     
    ll cnt4=INT_MAX,a2;
    
        for (int i = 0  ; i < n; i++)
    {
        if(cnt4>abs(-a[i]+b[n-1])){
            cnt4=abs(b[n-1]-a[i]);
            a2=i;
        }
        
    }
         
   
    sum=min(sum,cnt1+cnt2+cnt3+cnt4);
    sum=min(sum,abs(a[0]-b[0])+abs(b[n-1]-a[n-1]));
    sum=min(sum,cnt1+cnt2+abs(b[n-1]-a[n-1]));
    sum=min(sum,cnt3+cnt4+abs(b[0]-a[0]));
    sum=min(sum,cnt2+cnt3+abs(a[0]-b[n-1]));
    sum=min(sum,cnt1+cnt3+abs(b[0]-a[n-1])+abs(b[n-1]-a[0]));
    sum=min(sum,cnt1+cnt4+abs(b[0]-a[n-1]));
    sum=min(sum,abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));
    cout<<sum<<nline;
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