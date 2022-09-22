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
const int N = 1e7+6;
const int M = 3e5+7;
vector<bool> isPrime(N,1);
vi Primes;
vi divi(M,1);
void solve(){
    int n;
    cin>>n;
    vi v(2*n),ans;
    map<int,int> m;
    for(auto &x : v){
        cin>>x;
        m[x]++;
    } 
    sort(all(v));
    reverse(all(v));
    debug(isPrime[v[0]])
 
    for (int i = 0; i < 2*n; i++)
    {
  
        if(m[v[i]]>0){
            if(isPrime[v[i]]){

                auto ind = lb(all(Primes),v[i]);
                int j = ind-Primes.begin()+1;
                m[j]--;
                ans.pb(j);
                m[v[i]]--;
                debug(j)
              
            }
            else{
                    if(m[v[i]/divi[v[i]]]>0 ){
                        ans.pb(v[i]);
                        m[v[i]]--;
                        m[v[i]/divi[v[i]]]--;
                    }
                }
        }
        debug(ans)
    }
 
    for(auto x : ans){
        cout<<x<<' ';
    }
}
int main(){
    FAST
    for (int i = 2; i < M; i++)
    {
        for (int j = 2*i; j < M; j+=i)
        {
            if(divi[j]==1){
                divi[j]=INT_MAX;
                divi[j]=min(i,divi[j]);
            }
        }    
    } 
    

    for (int i = 2; i <= N; i++) {
        if(isPrime[i]){
            Primes.pb(i);
        }
    if (isPrime[i] && (long long)i * i <= N) {
        for (int j = i * i; j <= N; j += i)
            isPrime[j] = false;
    }
}  
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}