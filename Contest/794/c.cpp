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
    vi v(n);
    multiset<int> m;
    for(auto &x : v){
        cin>>x;
        m.insert(x);
    }
    sort(all(v));
    
    vi ans(n+1);
    if(n&1){
        cout<<"NO\n";
        return;
    }
    // int l=0,t=1;
    // for (int i = 0; i < n; i++)
    // {
    //     if(i%2==1){
    //         auto it = m.rbegin();
    //         if(m.size()==0){
    //             cout<<"NO\n";
    //             return;
    //         }
            
    //         ans[i]=*(it);
    //         if(*it==ans[i-1]){
    //             swap(ans[t],ans[i]);
    //             t+=2;
    //         }
    //         auto it2= m.end();
    //         --it2;
    //         m.erase(it2);
            
    //     }
    //     else{ 
    //         auto it =m.find(v[l]);
    //         if(it==m.end()){
    //             cout<<"NO\n";
    //             return;
    //         }
    //         ans[i]=v[l];
    //         l++;
    //         m.erase(it);
    //     }
    // }
    int l=n/2,r=0;
    for (int i = 0; i < n; i++)
    {
        if(i%2==1){
            ans[i]=v[l];
            l++;

        }
        else{ ans[i]=v[r];
        r++;
    }
    }
    ans[n]=v[0];
    for (int i = 0; i < n; i++)
    { 
        if(i>0){
            if(!(ans[i]>ans[i-1] && ans[i]>ans[i+1])){
                if(!(ans[i]<ans[i-1] && ans[i]<ans[i+1])){
                cout<<"NO\n";
                return;
                }
            }
        }
         
    }
    cout<<"YES\n";
    for (int i = 0; i < ans.size()-1; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<nline;
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