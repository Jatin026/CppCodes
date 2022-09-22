#include <bits/stdc++.h>
using namespace std;
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
// Complete the MinimumDeliveryTime function
int MinimumDeliveryTime(int R, int C, vector <string> grid) {
  int delivery_time = 1e9;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
        int dis=0;
 
        for (int K = 0; K < R; K++)
        {
            for (int L = 0; L < C; L++)
            {
                if(grid[K][L]!='1') dis+=abs(K-i)+abs(L-j); 
            }
        }
        delivery_time=min(dis,delivery_time);
    
    }  
    
  }
  
  return delivery_time;
}

int main() {
  int T;
  // Get the number of test cases
  cin >> T;
  for(int t = 1; t <= T; t++) {
    // Get the dimensions of the grid
    int R, C;
    cin >> R >> C;
    // Get each row of the grid
    vector <string> grid;
    for(int i = 0; i < R; i++) {
      string row;
      cin >> row;
      grid.push_back(row);
    }
    cout << "Case #" << t << ": " << MinimumDeliveryTime(R, C, grid) << "\n";
  }
  return 0;
}
