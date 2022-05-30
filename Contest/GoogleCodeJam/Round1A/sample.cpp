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
struct range{
    long double a,b;
    public:
        range(){
        }
        range(lld a , lld b){
            this->a=a;
            this->b=b;
        }
};
range intersection(long double a , long double b, long double c , long double d){
    range obj;
    obj.b=min(max(a,b),max(c,d));
    obj.a=max(min(a,b),min(c,d));
    return obj;
}
void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    vi v(n);
    for(auto & x: v){
        cin>>x;
    }
    sort(all(v));
    ll ans=0;
    for (int i = 0; i < n-1; i++)
    {
        int l1=i+1 ,r1=n-1;
        int ans1=INT_MAX,ans2=-1;
        while(l1<=r1){
            int mid=(l1+r1)/2;
            if(v[i]+v[mid]>=l){
                r1=mid-1;
                ans1=mid;
            }
            else l1=mid+1;
        }
        int l2=i+1,r2=n-1;
        while(l2<=r2){
            int mid = (l2+r2)/2;
            if(v[i]+v[mid]<=r){
                l2=mid+1;
                ans2=mid;
            }
            else r2=mid-1;
        } 
        
        if(ans2>=ans1 && ans2>=i+1 && ans1<=n-1){
            range obj=intersection(i+1,ans2,ans1,n-1);
            ans+=(obj.b-obj.a+1);
        }
    }
    cout<<ans<<nline;
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