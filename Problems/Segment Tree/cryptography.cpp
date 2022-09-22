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
#define REP(i,n) for(int i = 0; i < (n); i++)
int r;

struct Matrix {
	int a[2][2] = {{0,0},{0,0}};
	Matrix operator *(const Matrix& other) {
		Matrix product;
        
		REP(i,2)REP(j,2)REP(k,2) {
			product.a[i][k] += (a[i][j] * other.a[j][k]) ;
            product.a[i][k]%=r;
		}
		return product;
	}
};
struct segtree{
    int size;
    vector<Matrix> sums;
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        sums.resize(2*size);
    }
    void build(vector<Matrix> &a,int x , int lx , int rx){
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
        sums[x]=sums[2*x+1]*sums[2*x+2];
    }
    void build(vector<Matrix> &a){
        build(a,0,0,size);
    }
    
    Matrix sum(int l , int r, int x , int lx , int rx){
        Matrix a;
        a.a[0][0]=1;
        a.a[1][1]=1;
        if(l>=rx || lx>=r) return a;
        if(l<=lx && r>=rx) return sums[x];
         
            int m = (lx+rx)/2;
            Matrix s1=sum(l,r,2*x+1,lx,m);
            Matrix s2=sum(l,r,2*x+2,m,rx);
            return s1*s2;
        
    }
    Matrix sum(int l , int r){
        return sum(l,r,0,0,size);
    }
};
void solve(){
    int n,m;
    cin>>r>>n>>m;
    segtree st;
    st.init(n);
    vector<Matrix> b(n);
    for(auto &x : b){
        cin>>x.a[0][0]>>x.a[0][1]>>x.a[1][0]>>x.a[1][1];
    }
    st.build(b);
    while (m--)
    {
         
        int l,r;
        cin>>l>>r;
        --l;
        Matrix m=st.sum(l,r);
        cout<<m.a[0][0]<<" "<<m.a[0][1]<<nline;
        cout<<m.a[1][0]<<" "<<m.a[1][1]<<nline;
        cout<<nline;
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