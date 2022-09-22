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
int MAX_N =(int)2e5+7;
int LOG = 20;
// vector<int> children[MAX_N];
// int up[MAX_N][LOG]; // up[v][j] is 2^j-th ancestor of v
// int depth[MAX_N];

void dfs(int a , vvi &children , vvi &up , vi &depth,vi &vis) {
    vis[a]=1;
	for(int b : children[a]) {
        if(vis[b]) continue;
		depth[b] = depth[a] + 1;
		up[b][0] = a; // a is parent of b
		for(int j = 1; j < LOG; j++) {
			up[b][j] = up[up[b][j-1]][j-1];
		}
		dfs(b , children , up ,depth,vis);
	}
}

int get_lca(int a, int b , vvi &children , vvi &up , vi &depth) { // O(log(N))
	if(depth[a] < depth[b]) {
		swap(a, b);
	}
	// 1) Get same depth.
	int k = depth[a] - depth[b];
	for(int j = LOG - 1; j >= 0; j--) {
		if(k & (1 << j)) {
			a = up[a][j]; // parent of a
		}
	}
	// 2) if b was ancestor of a then now a==b
	if(a == b) {
		return a;
	}
	// 3) move both a and b with powers of two
	for(int j = LOG - 1; j >= 0; j--) {
		if(up[a][j] != up[b][j]) {
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}
void solve(){
    int n;
    cin>>n;
    vvi children(n+1) , up(n+1,vi (LOG)),up2(n+1,vi (LOG));
    vi depth(n+1),vis(n+1,0);
    for (int i = 1; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        children[a].pb(b);
        children[b].pb(a);
    }
    dfs(1, children , up ,depth,vis);
    
    int q;
    cin>>q;

    while (q--)
    {
        int m;
        cin>>m;
        vi querry(m);
        for(auto &x : querry){
            cin>>x;
        }
        bool flag=true;
      
        int cnt=0,x,x1,y1,ind=querry.size();
        sort(querry.begin(), querry.end(), [&](const int x, const int y) {
            return (depth[x] > depth[y]);
        });
        for (int i = 1; i < querry.size(); i++)
        {
            x = get_lca(querry[i],querry[i-1], children , up ,depth);
            x1=querry[i];
            y1=querry[i-1];
            if(x1== x) flag=true;
            else{
                ind=i;
                break;
            }
        }
        for (int i = ind; i < querry.size(); i++)
        {
            int u = querry[i];
            if(get_lca(u,x,children,up,depth)==x){
                if(get_lca(u,x1,children,up,depth)==u) continue;
                if(get_lca(u,y1,children,up,depth)==u) continue;
            }
            debug(u)
            flag=false;
            break;
            
        }
        
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
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