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
void solve(){
    int n,cnt=0,c1=0,c0=0;
    cin>>n;
    vi v(n);
    set<int> s;
    for(auto &x : v){
        cin>>x;
        if(x==0) cnt++;
        else if(x>0) c1++;
        else c0++;
        s.insert(x);
    }
    if(n==3){
        if(v[0]+v[1]+v[2]==v[0] || v[0]+v[1]+v[2]==v[1] || v[0]+v[1]+v[2]==v[2]) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    if(s.size()>4 || c1>2 || c0>2){
        cout<<"NO\n";
        return;
    }
   
    if(cnt==0){
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    if(find(all(v),v[i]+v[j]+v[k])==v.end()){
                        cout<<"NO\n";
                        return;
                    }  
                }
                
            }
            
        }
        
         cout<<"YES\n";
       
    } 
    else if(s.size()==1 && cnt>0 ) cout<<"YES\n";
    else if(s.size()==2 &&   cnt>=1){
        if(c0==1 || c1==1 ) cout<<"YES\n";
        else cout<<"NO\n";
    }
 
    else if(s.size()==3 && abs(*(s.begin()))==(*(s.rbegin())) && c0==1 && c1==1 && cnt>=1 ) cout<<"YES\n";
     
    else cout<<"NO\n";
      
    
    
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