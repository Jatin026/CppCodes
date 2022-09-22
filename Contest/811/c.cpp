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
    string t;
    cin>>t;
    int n;
    cin>>n;
 
    vector<string> v(n);
    for(auto &x : v){
        cin>>x;
    }
    vpr ans;
    int l = t.size() ;
   
    vvi pre(l);
    vi x(n,0);
    map<int,int> m;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool flag=true;
            if(i+v[j].size()<=l){
                for (int k = 0; k < v[j].size() ; k++)
                {
                    if(t[i+k]!=v[j][k]) flag=false;
                    
                }
                if(flag){
                    for (int k = 0; k < v[j].size() ; k++)
                {
                    if(t[i+k]==v[j][k]){
                        if(m[j+1]==v[j].size()){
                            x[j]++;
                            m[j+1]=0;
                        }
                        m[j+1]++;
                        pre[i+k].pb(j+1+x[j]*n);
                    }
                    
                }
                }
            }

        }
        
    }
    for (int i = 0; i < l; i++)
    {
        if(pre[i].size()==0){
            cout<<-1<<nline;
            return;
        }
    }
    
    debug(pre)
    int start=-1,sec;
    for (int i = 0; i < l; i++)
    {
        if(start!=-1){
            i=start+sec-1;
            if(i>=l) break;
        }
        vpr y;
        for(int j = 0 ; j < pre[i].size(); j++){
            int cnt=0;
            int k=i;
            while(k<l && find(all(pre[k]),pre[i][j])!=pre[k].end() ){
         
                cnt++;
                k++;
            }
            debug(pre[i][j])
            if(pre[i][j]%n!=0) y.pb({cnt,pre[i][j]%n});
            else y.pb({cnt, n});
        }
        debug(y)
        sort(all(y));
        sec=v[y[y.size()-1].second-1].size();
        start=i+1-(sec-y[y.size()-1].first);
        debug(start)
        debug(sec)
        pr p = {start,y[y.size()-1].second};
        swap(p.first,p.second);
        ans.pb(p);
    
    }
    sort(all(ans));
    cout<<ans.size()<<nline;
    for(auto x : ans){
        cout<<x.first<<" "<<x.second<<nline;
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