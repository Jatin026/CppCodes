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
    vll operations;
    vll sums;
    ll NO_OPERATIONS = LLONG_MAX;
    ll Neutral_Element= 0; 
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        sums.assign(2*size,0);
        operations.assign(2*size,0);
    }
    ll modify_Op(ll a , ll b , ll len){
        if(b ==  NO_OPERATIONS) return a;
        return b*len;
    }
    void apply_mod_op(ll &a , ll b , ll len){
        a=modify_Op(a,b,len);
    }
    ll calc_Op(ll a , ll b){
        return a+b ;
    }
    void propagate(int x , int lx ,int rx){
        if(rx - lx == 1) return;
        int m = (lx + rx )/2;
 
        apply_mod_op(sums[2*x+1], operations[x]  , m -lx);
        apply_mod_op(sums[2*x+2] , operations[x] , rx -m );
        apply_mod_op(operations[2*x+2] , operations[x] , 1 );
        apply_mod_op(operations[2*x+1] , operations[x] , 1  );
        operations[x]=NO_OPERATIONS;
 
    }
    void modify (int l , int r , int v, int x , int lx , int rx){
        propagate(x , lx , rx );
        if(lx>=r || l>=rx) return ;
        if(lx >= l && rx <= r){
            apply_mod_op(operations[x] , v , 1 ) ;
            apply_mod_op(sums[x] ,  v , rx-lx) ;
            return;
        }
        int m  = (lx+rx)/2;
        modify(l,r,v,2*x+1,lx,m);modify(l,r,v,2*x+2,m,rx);
        sums[x]=calc_Op(sums[2*x+1], sums[2*x+2] );
        apply_mod_op(sums[x], operations[x],rx-lx);
    }
    void modify (int l ,int r , int v){
        modify(l , r , v , 0 , 0 , size);
    }
    ll calc(int l ,int r , int x , int lx ,int rx){
        propagate(x,lx,rx);
        if(lx>=r || rx<=l) return Neutral_Element;
        if(lx>=l && rx<=r){
            return sums[x];
        }
        int m = (lx+rx)/2;
        auto m1 = calc(l,r,2*x+1, lx , m);
        auto m2 = calc(l,r, 2*x+2 , m , rx);
        auto res = calc_Op(m1,m2);
        apply_mod_op(res, operations[x], min(r,rx) -  max(lx ,l));
        return res;
    }
    ll calc (int l , int r ){
        return calc(l,r , 0 , 0 ,size);
    }
    void build(vector<ll> &a,int x , int lx , int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                sums[x]=a[lx];
            }
            return;
        }
        else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
        }
        sums[x]=calc_Op(sums[2*x+1],sums[2*x+2]);
    }
 
    void build(vector<ll> &a){
        build(a,0,0,size);
    }
    
    
     
};
void solve(){
    int n , q;
    cin >> n >> q;
    vll v(n);
    segtree st;
    st.init(n);
    int ind = 0;
    for(auto &x : v){
        cin >> x;
        st.modify(ind,ind+1,x);
        ind++;
    }
    st.build(v);
    debug(st.calc(0,n))
    while (q--)
    {
        int type;
        cin >> type;
        int i ; cin >> i;
        --i;
        if(type == 1){
            int r , x; cin >>r >> x;
            st.modify(i,r,x);
        }
        else{
            int r = n , mid , l = i , ans = l;
            while(l<=r){
                mid = (l+r)/2;
                if(st.calc(0,n)-2*st.calc(i,mid)>=0){
                    l = mid+1;
                    ans = mid;
                }
                else r = mid - 1;
            }
            ll val = st.calc(0,n)-2*st.calc(i,ans), ans2 = ans;
            if(ans != n){
                if(val >= abs(st.calc(0,n)-2*st.calc(i,ans+1))) {
                    val = abs(st.calc(0,n)-2*st.calc(i,ans+1));
                    ans += 1;
                }
            }
            if(ans2 != 0){
                if(val >= abs(st.calc(0,n)-2*st.calc(i,ans2 - 1))) {
                    val = abs(st.calc(0,n)-2*st.calc(i,ans2 - 1));
                    ans = ans2 - 1;
                }
            }
            // l = i ; r = n; 
            // int ans2 = i;
            // while(l<=r){
            //     mid = (l+r)/2;
            //     if(2*st.calc(i,mid)-st.calc(0,n)<=0){
            //         debug(st.calc(0,n)-2*st.calc(i,mid))
            //         l = mid + 1;
            //         ans2 = mid;
            //     }
            //     else r = mid - 1;
            // }
            // if(val> abs(2*st.calc(i,ans2)-st.calc(0,n))) {
            //     ans = ans2;
            //     val = abs(2*st.calc(i,ans2)-st.calc(0,n));
            // }
            // if(ans2 != n){
            //     if(val > abs(2*st.calc(i,ans2+1)-st.calc(0,n))) ans=ans2+1;
            // }

            cout << ans << nline;
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