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
    vector<vll> dp (n+1,vll (10,INT_MIN));
    dp[0][0]=0;
    for (int i = 1; i <= n; i++)
    {
        vi c1,c2,c3;
        int t;
        cin>>t;
        vi v(t);
        for (int j = 0; j < 10; j++)
        {
            dp[i][j]=dp[i-1][j];
        }
        
        for (int j = 0; j < t; j++)
        {
            int a,d;
            cin>>a>>d;
  
            if(a==1){
                c1.pb(d);
            }
            else if(a==2){
                c2.pb(d);
            }
            else c3.pb(d);
        }
      
        sort(all(c1),greater<int>());sort(all(c2),greater<int>());sort(all(c3),greater<int>()); 
 
        if(c1.size()>=3){
            for (int y = 0; y < 10; y++)
            {
            
                if((y+3)>=10  ){
                    dp[i][(y+3)%10]=max(dp[i][(y+3)%10],dp[i-1][y]+2*c1[0]+c1[1]+c1[2]);
                }
                else{
                    dp[i][(y+3)%10]=max(dp[i][(y+3)%10],dp[i-1][y]+c1[0]+c1[1]+c1[2]);
                }
            
            }
        }
        if(c1.size()>=2){
            for (int y = 0; y < 10; y++)
            {
            
                if((y+2)>=10  ){
                    dp[i][(y+2)%10]=max(dp[i][(y+2)%10],dp[i-1][y]+2*c1[0]+c1[1] );
                }
                else{
                    dp[i][(y+2)%10]=max(dp[i][(y+2)%10],dp[i-1][y]+c1[0]+c1[1] );
                }
            
            }
        } 
        if(c1.size()>=1){
            for (int y = 0; y < 10; y++)
            {
            
                if((y+1)>=10  ){
                    dp[i][(y+1)%10]=max(dp[i][(y+1)%10],dp[i-1][y]+2*c1[0]  );
                }
                else{
                    dp[i][(y+1)%10]=max(dp[i][(y+1)%10],dp[i-1][y]+c1[0]  );
                }
            
            }
        } 
        if(c1.size()>=1 && c2.size()>=1){
            for (int y = 0; y < 10; y++)
            {
                   
                if((y+2)>=10  ){
                    dp[i][(y+2)%10]=max(dp[i][(y+2)%10],dp[i-1][y]+2*max(c1[0],c2[0])+min(c1[0],c2[0]));
                }
                else{
                    dp[i][(y+2)%10]=max(dp[i][(y+2)%10],dp[i-1][y]+c1[0]+ c2[0]);
                }
               
                  }
                  
        }
        if(c2.size()>=1  ){
            for (int y = 0; y < 10; y++)
            {
            
                    if((y+1)>=10  ){
                        dp[i][(y+1)%10]=max(dp[i][(y+1)%10],dp[i-1][y]+2*c2[0]);
                    }
                    else{
                        dp[i][(y+1)%10]=max(dp[i][(y+1)%10],dp[i-1][y] + c2[0]);
                    }
                
            }
        }
        if(  c3.size()>=1){
            for (int y = 0; y < 10; y++)
            {
               
                if((y+1)>=10  ){
                    dp[i][(y+1)%10]=max(dp[i][(y+1)%10],dp[i-1][y]+2*c3[0]);
                }
                else{
                    dp[i][(y+1)%10]=max(dp[i][(y+1)%10],dp[i-1][y]+c3[0]);
                }
            } 

        }
    }
    ll ans=-1;
    for (int i = 0; i < 10; i++)
    {
        ans=max(ans,dp[n][i]);
    }
    cout<<ans;
    debug(dp)
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