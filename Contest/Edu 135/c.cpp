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
    vi a(n),b(n);map<int,int> cntB;
    for(auto &x : a) cin>>x;
    for(auto &x : b) {
        cin>>x;
        cntB[x]++;
    }
    int cnt=0;
    vi ax,bx;
    sort(all(a));sort(all(b));
    int l=n-1;
    for (int r = n-1; r > -1; r--)
    {
        if(l==-1) continue; 
        while (l>-1 && b[l]>a[r])   
        {
            --l;
        }
        if(l==-1) continue; 
        if(a[r]==b[l]){
            a[r]=0;
            b[l]=0;
            --l;
        }
    }
    sort(all(a));sort(all(b));
    l=b.size()-1;
    for (int r = ax.size()-1; r > -1; r--)
    {
        if(ax[r]>9){
            string s = to_string(ax[r]);
            ax[r]=s.size();
            ++cnt;
        }
        if(bx[r]>9){
            string s = to_string(bx[r]);
            bx[r]=s.size();
            ++cnt;
        }
    }
    sort(all(ax));sort(all(bx));
    l=bx.size()-1;
    for (int r = ax.size()-1; r > -1; r--)
    {
        while (l>-1 && bx[l]>ax[r])   
        {
            --l;
        }
        if(l==-1) continue; 
        if(ax[r]==bx[l]){
            ax[r]=0;
            bx[l]=0;
            --l;
        }
    }
    
    
    sort(all(ax));sort(all(bx));
    
    debug(ax)
    for (int r = ax.size()-1; r > -1; r--)
    {
        if(ax[r]>1){
            string s = to_string(a[r]);
            a[r]=s.size();
            ++cnt;
        }
        if(bx[r]>1){
            string s = to_string(b[r]);
            b[r]=s.size();
            ++cnt;
        }
    }
    cout<<cnt<<nline;
 
   
    
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