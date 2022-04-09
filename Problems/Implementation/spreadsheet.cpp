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
    string s;
    cin>>s;
    int cu=0,ru=0;
    bool flagu=false;
    for (int i = 2; i < s.size(); i++)
    {
        if(s[0]=='R' && s[i]=='C' && s[i-1]<'A' ) flagu=true;
        else{
            if(flagu && s[i]=='C'){
                flagu=false;
                break;
            }
        }
    }
    
    if(flagu ){
        auto it = find(all(s),'C');
        int ind = it-s.begin();
        int r;
        stringstream ri(s.substr(1,ind-1));
        ri>>r;
        //int r= stoll(s.substr(1,ind-1));
        int c;
        stringstream ci(s.substr(ind+1));
        ci>>c;
        vi v;
        debug(c)
      
        while(c>0){
            if(c%26!=0) {
                v.pb(c%26);
                c/=26;
            }
            else {v.pb(26);
                c/=26;
                c--;
            }
            
        }
        debug(r)
        debug(ind)
        reverse(all(v));
        for ( auto &x : v){
            cout<<char(x+64);
        }
        cout<<r<<nline;
    }
    else{
        int ind=0;
        for (int i = 0; i < s.size() ; i++)
        {
            if(s[i]<'A'){
                ind=i;
                break;
            }
        }

        int r;
        stringstream ri(s.substr(ind));
        ri>>r;
        string a=s.substr(0,ind);
        reverse(all(a));
        ll c=0;
        ll prod=1;
        for (int i = 0; i < a.size(); i++)
        {
            c+=(a[i]-64)*prod;
            prod*=26;
        }
        cout<<"R"<<r<<"C"<<c<<nline;
        
    }
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