#include<bits/stdc++.h>
#include<chrono>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>   
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
 
 
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
int to_str(int i){
    int l = 0;
    while(i > 0){
        l++;
        i/=10;
    }
    return l;
}
vector<array<int,3>> pre[4][4][4];
void solve(){
    ll a , b , c , k;
    cin >> a >> b >> c >> k;
    ll v = max(a,b); v = max(v,c);
    if(c < max(a,b)){
        cout << -1 << nline;
        return;
    }
    if(v <= 3){
        if((ll)pre[a][b][c].size() >= k ){
            auto p = pre[a][b][c][k-1];
            cout << p[0] <<" + " <<p[1] <<" = "<<p[2]<<nline;
        }
        else{
            cout << -1 << nline;
        }
    }
    else{
        ll mini , maxi = 0 ;
        ll pow = 1;
        for (int i = 0; i < b-1; i++)
        {
            pow *= 10;
        }
        mini = pow;
        pow = 1;
        for (int i = 0; i < b; i++)
        {
            maxi += pow*9;
            pow *= 10;
        }
        auto check = [&](ll i , ll mid) -> bool {
            ll k = i + mid;
            auto m = to_str(k);
            return (m  >= c);
        };
        auto check2 = [&](ll i , ll mid) -> bool {
            ll k = i + mid;
            auto m = to_str(k);
            if(m  > c) return 0;
            else return 1;
        };
        pow = 1;
        for (int i = 0; i < a; i++)
        {
            pow *= 10;
        }
        for (int i = 1; i < pow; i++)
        {
            int f = to_str(i);
            if(f  < a) continue;
            ll l = mini , r = maxi , mid , ans = -1  ;
            while(l <= r){
                mid = (l+r)/2;
                if(check(i,mid)){
                    r = mid - 1;
                    ans = mid;
                }
                else l = mid + 1;
            }   
            if(ans == -1) break;
            l = ans; r = maxi; ll ans2 = -1;
            while(l <= r){
                mid = (l+r)/2;
                if(check2(i,mid)){
                    l = mid + 1;
                    ans2 = mid;
                }
                else r = mid - 1;
            }   
            if(ans2 == -1) continue;
            if(k > ans2 - ans + 1) k -= (ans2 - ans + 1);
            else{
                cout << i  <<" + " << ans+k-1 <<" = "<< (i+ans+k-1) <<nline;
                return;
            }
            if(f  > a) break;
        }
        cout << -1 << nline;
    }
}
int main(){
    FAST
    int t=1;
    for (int i = 1; i < 1000; i++)
    {
        for (int j = 1; j < 1000; j++)
        {
            int k  = i+j;
            int a = to_str(i) , b = to_str(j) , c =to_str(k);
            if(c <= 3){
                pre[a][b][c].emplace_back(array<int,3> {i,j,k});
            }   
            else break;
        } 
    }
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}