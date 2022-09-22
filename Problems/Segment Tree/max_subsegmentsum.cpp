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
struct segtree{
    int size;
    vll sums,pref,suff,ans;
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        sums.assign(2*size,0);
        pref.assign(2*size,0);
        suff.assign(2*size,0);
        ans.assign(2*size,0);
    }
    void build(vector<int> &a,int x , int lx , int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                sums[x]=a[lx];
                pref[x]=max(pref[x],(1ll)*a[lx]);
                suff[x]=max(suff[x],(1ll)*a[lx]);
                ans[x]=max(ans[x],(1ll)*a[lx]);

            }
            return;
        }
        else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            sums[x]=sums[2*x+1]+sums[2*x+2];
            pref[x]=max(sums[2*x+1]+pref[2*x+2],pref[2*x+1]);
            suff[x]=max(suff[2*x+2],sums[2*x+2]+suff[2*x+1]);
            ans[x]=max(ans[2*x+2],ans[2*x+1]);
            ans[x]=max(ans[x],suff[2*x+1]+pref[2*x+2]);
        }
    
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void set(int i , int v , int x , int lx, int rx){
        if(rx-lx==1){
            sums[x]=v;
            pref[x]=max(0,v);
            suff[x]=max(0, v);
            ans[x]= max(0,v);
            debug(x)
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];
        
      
        pref[x]=max(sums[2*x+1]+pref[2*x+2],pref[2*x+1]);
        suff[x]=max(suff[2*x+2],sums[2*x+2]+suff[2*x+1]);
        ans[x]=max(ans[2*x+2],ans[2*x+1]);
        ans[x]=max(ans[x],suff[2*x+1]+pref[2*x+2]);
    }
    void set(int i , int v){
        set(i,v,0,0,size);
    }
     
    ll maxSubsegment(int l , int r ,int x, int lx , int rx){
        int m = (lx+rx)/2;
        if(l>=rx || lx>=r) return 0;
        if(l<=lx && r>=rx) return ans[x];
        ll seg1=maxSubsegment(l,r,2*x+1,lx,m);
        ll seg2 = maxSubsegment(l,r,2*x+2,m,rx);
        ll val = max(max(seg2,seg1),suff[2*x+1]+pref[2*x+2]);
        return val;
    }
    ll maxSubsegment(){
        return maxSubsegment(0,size,0,0,size);
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    segtree st;
    st.init(n);
    vi b(n);
    for(auto &x : b){
        cin>>x;
    }
    st.build(b);
    cout<<st.maxSubsegment()<<nline; 
    while (m--)
    {
        int i,v;
        cin>>i>>v;
        st.set(i,v);
        cout<<max(st.maxSubsegment(),0ll)<<nline; 
        debug(st.ans);
    }
    
}
int main(){
    FAST
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}