#include<bits/stdc++.h>
#include<chrono>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(s) s.begin(),s.end()
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define binarystring(n,x) bitset<n> (x).to_string()
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define MOD            1000000007
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
           // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
           return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const {
           static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
};
#define nline '\n'
 


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
    int n , q;
    cin >> n >> q;
    string s; cin >> s;
    vi vis(26,1);
    for (int i = 0; i < q; i++)
    {
        char a;
        cin >> a;
        vis[a-'a'] = 0;
    }
    vvi pref(26,vi(n+1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            pref[j][i+1] = pref[j][i];
        }
        pref[s[i]-'a'][i+1]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int r = n;
        for (int j = 0; j < 26; j++)
        {
            if(vis[j]){
                r = min(r ,(int) (ub(all(pref[j]),pref[j][i]) - pref[j].begin()) -  1);
            }
        }
      
        ans += r - i;
    }
    cout << ans << nline;
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