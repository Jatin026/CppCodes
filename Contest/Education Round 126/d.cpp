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
    vll po(17,0);
    vll prime={2,3,5,7,11,13};
    for (int i = 0; i < n; i++)
    {
        if(s[i]>'1'){
        for (auto x : prime){
            ll xi=x;
            int ele=s[i]-'0';
            int m=1;
            while((ele)/BinExpItr(x,m) > 0){
                po[xi]+=(ele)/BinExpItr(x,m);
                m++;
            }
        }
        }
    }   
    int l=0;
    debug(po[2])
    for (int i = 15; i > 1; i--)
    {
        auto it = find(all(prime),i);
        if(it!=prime.end() && po[i]>0 ){
            for (int j = 0; j < po[i]; j++)
            {
                cout<<i;
            }
            debug(po[i])
            debug(i)
            debug("\n")
            int l=0;
            for(auto x : prime){
                ll xi=x;
                int m=1;
                while(i/BinExpItr(x,m)>0){
                    l+=(i/BinExpItr(x,m));
                    m++;
                }
                debug(l)
                debug(po[xi])
                debug("\n")
                po[xi]-=po[i]*l;
                l=0;
            }
        }
        
    }
    
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