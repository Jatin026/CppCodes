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
#define print(ca,x) cout<<"Case #"<<ca<<": "<<x
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
    string s;
    cin>>s;
    int n =s.size();
    vector<char> v,l;
    int ind;
    for (int i = n-1; i >-1; i--)
    {
       if(s[i]==s[n-1]){
           ind=i;
           l.pb(s[i]);
       }  
       else break;
    }
    for (int i = 0; i < ind; i++)
    {
        if(s[i]<=s[i+1]){
            v.pb(s[i]);
            v.pb(s[i]);
        }
        else v.pb(s[i]);
    }
    
    string a="",b="";
    for(auto x :v){
        a+=x;
    }
    for(auto x : l){
        a+=x;
    }
    vi m;
    for (int i = 0; i < ind; i++)
    {
        bool flag=false;
        for (int k = i+1; k < ind ; k++)
        {
            if(s[k]>s[i]) flag=true;
        }
        if(flag){
            m.pb(s[i]);
            m.pb(s[i]);
        }
        else m.pb(s[i]);
    }
    for(auto x :m){
        b+=x;
    }
    for(auto x : l){
        b+=x;
    }
    print(ca,b);
    cout<<nline;
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