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
int ai,aj,bi,bj;
void solve(){
    int N,M;
    cin>>N>>M;
    vector<string> v(N);
    vvi vis(N+1,vi (M+1,0));
    for (int i = 0; i < N; i++)
    {
        cin>>v[i];
        for (int j = 0; j < M; j++)
        {
            if(v[i][j]=='A'){
                ai=i+1;
                aj=j+1;
            }
            else if(v[i][j]=='B'){
                bi=i+1;
                bj=j+1;
            }
        }
        
    }
    int cnt=0;
    queue<pr> q;
    q.push({ai,aj});
 
    vis[ai][aj]=1;
    bool flag=false;
    vector<vpr> route(N+1,vpr(M+1,{-1,-1}));
    while(!q.empty()){
        int n = (q.front()).first;
        int m = (q.front()).second;
        q.pop();
         
        
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if(abs(i)+abs(j)==1 && (n+i)>0 && (n+i)<= N && (m+j)>0 && (m+j)<= M && !vis[n+i][m+j] && v[n+i-1][j+m-1]!='#'){
                    q.push({n+i,m+j});
                    vis[n+i][j+m]=1;
                    route[n+i][j+m]={n,m};
                    pr x= {(n+i),m+j};
                    if(n+i==bi && m+j==bj) {
            flag=true;
            break;
        }
                }
            }
        } 
    }
    if(!flag) cout<<"NO\n";
    else{
        cout<<"YES\n";
        vector<char> ans;
 
        pr p = {-1,-1};
        pr x = {route[bi][bj].first,route[bi][bj].second};
        while(bi!=-1 && bj!=-1){
            if(x.first==bi+1){
                ans.pb('U');
            }
            if(x.first==bi-1){
                ans.pb('D');
            }
            if(x.second==bj+1){
                ans.pb('L');
            }
            if(x.second==bj-1){
                ans.pb('R');
            }

  
            bi=x.first;
            bj=x.second;
            if(bi==-1 && bj==-1) break;
            x=route[bi][bj];
            cnt++;
          
        }
   
        cout<<cnt<<nline;
        reverse(ans.begin(),ans.end());
        for(auto x :  ans){
            cout<<x ;
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