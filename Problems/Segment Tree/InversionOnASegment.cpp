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
vector<vll> sums(4e5+10,vll(45,0));
struct segtree{
    int size;
    vll ans;
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        ans.assign(2*size,0);
    }
    void build(vector<int> &a,int x , int lx , int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                sums[x][a[lx]]=1;
                for (int i = 0; i < 41; i++)
            {
                if(i!=a[lx]) sums[x][i]=0;
            }
            ans[x]=0;
            }
            return;
        }
        else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
        }
        ll sum=0;
        for (int i = 0; i < 41; i++)
        {
            sum+=sums[2*x+1][i];
        }
        ans[x]=0;
        for (int i = 0; i < 41; i++)
        {
            sum-=sums[2*x+1][i];
            ans[x]+=(sum)*(sums[2*x+2][i]);
        }
        for (int i = 0; i < 41; i++)
        {
            sums[x][i]=(sums[2*x+1][i]+sums[2*x+2][i]);
        }
        ans[x]+=ans[2*x+1]+ans[2*x+2];
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void set(int i , int v , int x , int lx, int rx){
        if(rx-lx==1){
            sums[x][v]=1;
            for (int i = 0; i < 41; i++)
            {
                if(i!=v) sums[x][i]=0;
            }
            ans[x]=0;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        ll sum=0;
        ans[x]=0;
        for (int i = 0; i < 41; i++)
        {
            sum+=sums[2*x+1][i];
        }
        for (int i = 0; i < 41; i++)
        {
            sum-=sums[2*x+1][i];
            ans[x]+=(sum)*(sums[2*x+2][i]);
        }
        ans[x]+=ans[2*x+1]+ans[2*x+2];
        for (int i = 0; i < 41; i++)
        {
            sums[x][i]=(sums[2*x+1][i]+sums[2*x+2][i]);
        }
    }
    void set(int i , int v){
        set(i,v,0,0,size);
    }
    pair<ll,vll> sum(int l , int r, int x , int lx , int rx){
        vll y(45,0);
        if(l>=rx || lx>=r) return {0,y};
        if(l<=lx && r>=rx){
            debug(x)
            debug(ans[x])
            debug(sums[x])
            return {ans[x],sums[x]};
        }
         
            int m = (lx+rx)/2;
            pair<ll,vll> s1=sum(l,r,2*x+1,lx,m);
            pair<ll,vll> s2=sum(l,r,2*x+2,m,rx);
            ll sum=0;
          
            vll a = s1.second ;
            vll b=  s2.second;
            for (int i = 0; i < 41; i++)
        {
            sum+=a[i];
        }
        ll val=0;
        for (int i = 0; i < 41; i++)
        {
            sum-=a[i];
            val+=(sum)*(b[i]);
        }
            for (int i = 0; i < 41; i++)
            {
                a[i]=(a[i]+b[i]);
            }
              val+=s1.first+s2.first;
            return {val,a};
    }
    pair<ll,vll> sum(int l , int r){
        return sum(l,r,0,0,size);
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
    while (m--)
    {
        int a;
        cin>>a;
        if(a==2){
            int i,v;
            cin>>i>>v;
            --i;
            st.set(i,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            --l;
            pair<ll,vll> x = st.sum(l,r);
            debug(x.second)
            cout<<x.first<<nline;
        }
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