#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(s) s.begin(),s.end()
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
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
#define vvi            vector<vi>
#define vpr            vector<pr> 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
using namespace std;

const int M = 1e9+7;
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
            res=(res*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    vi arr(n);
    for (int i = 0; i < n ; i++)
    {
        cin>>arr[i];
    }
    vi temp(all(arr)),temp2(all(arr));
    sort(all(temp));
    string s,k(n,'N'),l(n,'S');
    cin>>s;
    if(is_sorted(all(arr))==0 && (s==k || s==l) ) cout<<"-1\n";
    else{
        if(is_sorted(all(arr))==1) cout<<"0\n";
        else if(s[0]!=s[n-1]) {
            cout<<"1\n";
        }
        else{
            for (int i = 1; i < n; i++)
            {
                if(temp[i]!=arr[i] && s[i]!=s[0]) {
                    sort(arr.begin(),arr.begin()+i+1);
                    sort(temp2.begin()+i,temp2.end());
                    if(is_sorted(all(arr))==1 || is_sorted(all(temp2))==1){
                        cout<<"1\n";
                        return ;
                    } 
                }
            }
        
            cout<<"2\n";
        }
    }

}
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}