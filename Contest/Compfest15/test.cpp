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
 
#define pr             pair<int,int>
#define vi             vector<int>
#define vll            vector<ll>
#define vvi            vector<vi>
#define vpr            vector<pr> 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define nline '\n'
using namespace std;
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
const int N = 1e5;
// ofstream out("easy_4_in.txt");
void solve(){
    int n = rand(N,N) , q = rand(1,N);
    bool weighted = 1;
    cout << n <<nline;
    vector<array<int,3>> edges(n-1);
    for(int i = 1; i < n ; i++){
        int u = rand(0,i-1);
        edges[i-1][0] = 1 + u;
        edges[i-1][1] = i + 1;
        if(weighted){
            int w = rand(1,1e9);
            edges[i-1][2] = w;
        }
    }
    vector<int> perm(n);
    for(int i = 0 ; i < n ; i++){
        perm[i] = i+1;
    }
    shuffle(all(perm) , rng);
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[i+1] = perm[i];
    }
    for(auto &x : edges){
        x[0] = mp[x[0]];
        x[1] = mp[x[1]];
    }
    for(auto x : edges){
        cout << x[0] << " " << x[1];
        if(weighted) cout << " " << x[2] << " ";
        cout << nline;
    }
    cout << q << nline;
    for(int i = 0 ;  i < q ; i++){
        int a = rand(1,n) , b = rand(1,1e9);
        cout << a << " " << b << nline;
    }
}
int main(){
    FAST
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

