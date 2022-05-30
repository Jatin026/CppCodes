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
bool equi(string s){
    if(s=="") return 0;
    int cnt=1;
    for (int i = 0; i < s.size()-1; i++)
    {
        if(s[i]==s[i+1]) cnt++;
    }
    
    if(cnt==s.size()) return 1;
    return 0;
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1 ){
        if(s=="W") cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    int ind=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='W'){
           ind=i;
           break;
        }
    }
    string m="";
    for (int i = 0; i < ind; i++)
    {
        m+=s[i];
    }
    if(equi(m)){
        cout<<"NO\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='W'){
            int j=i+1;
            string k="";
            while(j<n && s[j]!='W'){
                k+=s[j];
                j++;    
            }
            if(equi(k)){
                cout<<"NO\n";
                return;
            }
            i=j-1;
        }
    }
    
    if(equi(s) && s[0]!='W'){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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