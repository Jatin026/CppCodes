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
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
void solve(int ca){
    int ma=INT_MAX,mb=INT_MAX,mc=INT_MAX,md=INT_MAX;
    for(int i =0 ; i < 3 ; i ++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        ma=min(a,ma);
        mb=min(b,mb);
        mc=min(c,mc);
        md=min(d,md);
    }
    vpr v;
    v.pb({ma,1});
    v.pb({mb,2});
    v.pb({mc,3});
    v.pb({md,4});
    sort(all(v));
    reverse(all(v));
    if(ma+mb+mc+md<1e6) print(ca,"IMPOSSIBLE")<<nline;
    else {
        int sum=ma+mb+mc+md-1e6;
        for(auto &x : v){
            if(x.first>=sum){
                x.first=(x.first-sum);
                break;
            }
            else{
                sum-=x.first;
                x.first=0;
            }
        }
        sort(all(v),sortbysec);
        print(ca,v[0].first);
        cout<<" "<<v[1].first<<" "<<v[2].first<<" "<<v[3].first<<nline;
        
}
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