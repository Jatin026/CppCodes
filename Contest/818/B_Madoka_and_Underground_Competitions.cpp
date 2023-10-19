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
    int n,k,r,c;
    cin>>n>>k>>r>>c;
    vector<vector<char>> v(n,vector<char> (n,'.'));
       for (int l = -n/k; l <= n/k; l++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(r+c+l*k==i+j) v[i-1][j-1]='X';
            }
        }
 
         
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if(v[i][j]=='X'){
                for (int l = i; l < n; l+=k)
                {
                    v[l][j]='X';
                }
                for (int l = i; l >=0; l-=k)
                {
                        v[l][j]='X';
                }
                break;
                
            }
            else{
                for (int m = 0; m < n; m++)
                {
                        if(v[m][j]=='X'){
                        for (int l = m; l < n; l+=k)
                        {
                            v[l][j]='X';
                        }
                        for (int l = m; l >=0; l-=k)
                        {
                            v[l][j]='X';
                        }
                        break;
                        
                    }
                }
                break;
                
            }
        }
        
        
    }
    
    
    
    
    // if(v[r-1][c-1]=='X'){
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<v[i][j] ;
        }
        cout<<nline;
    }
        
    // }
    // else{

    // }
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