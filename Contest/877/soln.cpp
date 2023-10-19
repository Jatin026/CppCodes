#include<bits/stdc++.h>
#include<chrono>
// #include <ext/pb_ds/assoc_container.hpp>  
// #include <ext/pb_ds/tree_policy.hpp>   
// using namespace __gnu_pbds;
using namespace std;
 
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// template <typename T>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
//  
 
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
 
#define pr             pair<int,int>
#define vi             vector<int>
#define vll            vector<ll>
#define vvi            vector<vi>
#define vpr            vector<pr> 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define nline '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
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
 
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vvi cnt(n+1,vi(5));
    vector<vll> val(n,vll(5));
    vector<vll> pref(n+1,vll(5));
    for (int i = 0; i < n; i++)
    {
        cnt[i+1] = cnt[i];
        cnt[i+1][s[i] - 'A']++;
    }
    vll conv(5);
    int p = 1;
    for(auto &x : conv){
        x = p;
        p *= 10;
    }
    // for(auto x : conv) cout << x << " ";
    vector<char> suff(n+1,'A');
    char curr = 'A';
    for(int i = n-1 ; i > -1 ; i--){
        if(curr > s[i]){
            val[i][s[i] - 'A'] = (-conv[s[i] - 'A']);
        }
        else val[i][s[i] - 'A'] = (conv[s[i] - 'A']);
        curr = max(curr , s[i]);
        suff[i] = curr;
    }
    for (int i = 0; i < n; i++)
    {
        pref[i+1] = pref[i];
        for (int j = 0; j < 5; j++)
        {
            pref[i+1][j] += val[i][j];
        }
    }
    // debug(pref)
    ll ans = 0;
    for(auto x : pref[n]) ans += x;
    for (int i = 1; i <= n; i++)
    {
        ll now = 0;
        for(auto x : pref[n]) now += x;
        for(auto x : pref[i]) now -= x;
        // ll less = 0;
        // debug(now)
        for (int j = 0; j < 5; j++)
        {
            ll temp = 0;
            if(suff[i] > char(j+'A')) temp -= conv[j];
            else temp += conv[j]; 
            for(int k = j ; k < 5; k++){
                temp += pref[i-1][k];
            }
            for (int k = 0; k < j; k++)
            {
                temp -= 1ll*(cnt[i-1][k])*conv[k];
            }
            ans = max(ans , temp + now);
            // less += cnt[i][j];
        }
        // debug(ans)
    }
    cout << ans << nline;
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