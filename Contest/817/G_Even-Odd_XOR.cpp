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
    int a=1e5,b=1e6;
    int n;
    cin>>n;
    if(n>=9){
        if(n%8==0){
            for (int i = 0; i < (n/8)*8; i++)
            {
                if(i%2==0){
                    cout<<a++<<" ";
                }
                else cout<<b++<<" ";
            }
            cout<<nline;
        }
        if(n%8==1){
            for (int i = 0; i < ((n/8)-1)*8; i++)
            {
                if(i%2==0){
                    cout<<a++<<" ";
                }
                else cout<<b++<<" ";
            }
            cout<<"8 2 3 7 4 0 5 6 9\n";
        }
        else if(n%8==2){
            for (int i = 0; i < ((n/8)-1)*8; i++)
            {
                if(i%2==0){
                    cout<<a++<<" ";
                }
                else cout<<b++<<" ";
            }
            cout<<"1 4 0 8 2 16 3 32 124 64\n";
        }
        else if(n%8==3){
            for (int i = 0; i < ((n/8))*8; i++)
            {
                if(i%2==0){
                    cout<<a++<<" ";
                }
                else cout<<b++<<" ";
            }
            cout<<"2 1 3 \n";
        }
        else if(n%8==4){
            for (int i = 0; i < ((n/8))*8; i++)
            {
                if(i%2==0){
                    cout<<a++<<" ";
                }
                else cout<<b++<<" ";
            }
            cout<<"2 1 3 0 \n";
        }
        else if(n%8==5){
            for (int i = 0; i < ((n/8))*8; i++)
            {
                if(i%2==0){
                    cout<<a++<<" ";
                }
                else cout<<b++<<" ";
            }
            cout<<"2 0 4 5 3 \n";
        }
        else if(n%8==6){
            for (int i = 0; i < ((n/8))*8; i++)
            {
                if(i%2==0){
                    cout<<a++<<" ";
                }
                else cout<<b++<<" ";
            }
            cout<<"4 1 2 12 3 8 \n";
        }
        else if(n%8==7){
            for (int i = 0; i < ((n/8))*8; i++)
            {
                if(i%2==0){
                    cout<<a++<<" ";
                }
                else cout<<b++<<" ";
            }
            cout<<"1 2 3 4 5 6 7\n";
        }
    }
    else{
        if(n%8==0){
            for (int i = 0; i < (n/8)*8; i++)
            {
                if(i%2==0){
                    cout<<a++<<" ";
                }
                else cout<<b++<<" ";
            }
            cout<<nline;
        }
        else if(n%8==3){
             
            cout<<"2 1 3 \n";
        }
        else if(n%8==4){
             
            cout<<"2 1 3 0 \n";
        }
        else if(n%8==5){
             
            cout<<"2 0 4 5 3 \n";
        }
        else if(n%8==6){
             
            cout<<"4 1 2 12 3 8 \n";
        }
        else if(n%8==7){
             
            cout<<"1 2 3 4 5 6 7\n";
        }
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