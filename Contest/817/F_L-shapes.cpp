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
int c=0;
set<pr> d;
void dfs(int x1,int y1  , int n,int m,vector<string> &s,vvi &vis){
    if(x1<0 || y1<0 || x1>=n || y1>=m || c>3) return;
    vis[x1][y1]=1;
    c++;
    d.insert({x1,y1});
    for (int dx = -1; dx < 2; dx++)
    {
        for (int dy =-1; dy < 2; dy++)
        {
            if(x1+dx>=0 && x1+dx<n && y1+dy>=0 && y1+dy<m && !vis[x1+dx][y1+dy]){
                if(s[x1+dx][y1+dy]!='.' ){
                   dfs(x1+dx,y1+dy,n,m,s,vis);
                }
            }
        }
        
    }
    
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    for(auto &x : s){
        cin>>x;
    }
    if(n==1 || m==1){
        cout<<"NO\n";
        return;
    }
    vvi vis(n,vi(m,0));
     
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] && s[i][j]=='*'){
                dfs(i,j,n,m,s,vis);
                if(c!=3){
                    cout<<"NO\n";
                    return;
                }
                else{
                
                    set<int> s;
                    set<int> sy;
                    for(auto x : d){
                        s.insert(x.first);
                        sy.insert(x.second);
                         
                    }
                   
                    if(!(s.size()==2 && sy.size()==2)){
                        debug(d)
                        cout<<"NO\n";
                        return;
                    }
                    
                }
            }
            c=0;
            d.clear();
        }
        
    }
    // c=0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         c=0;
    //         for (int k = 0; k < 3; k++)
    //         {
    //             if(j+k<m && s[i][j+k]=='*') c++;
    //         }
    //         if(c==3){
    //             cout<<"NO\n";
    //             return;
    //         }
    //         c=0;
    //         for (int k = 0; k < 3; k++)
    //         {
    //             if(i+k<n && s[i+k][j]=='*') c++;
    //         }
    //         if(c==3){
    //             cout<<"NO\n";
    //             return;
    //         }
             
    //     }
        
    // }
    
    cout<<"YES\n";

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