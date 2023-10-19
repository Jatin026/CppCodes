#include<bits/stdc++.h>

#define M1 1000000007
#define M2 998244353
#define PI 3.1415926535897932384626433832795
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define FI first
#define SE second
#define EPS 1e-9
#define testdebug(tc) cerr << "TEST CASE: " << tc << "--------------------" << endl

#ifndef ONLINE_JUDGE
#define debug(x) cerr << "Line No. " << _LINE_ << ": " #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef bool bl;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bl> vbl;
typedef vector<pair<ll, ll> > vpll;
typedef pair<ll, ll> pll;
typedef vector<vector<ll> > vvll;
typedef vector<pair<ll, vector<ll> > > vpllvll;
typedef map<ll, ll> mll;
typedef map<ll, vector<ll> > mllvll;
typedef map<ll, pair<ll, ll> > mllpll;
typedef set<ll> sll;
typedef multiset<ll> msll;
typedef deque<ll> dll;
typedef stack<ll> stll;
typedef queue<ll> qll;

// LOOPS------------------------------------------------------------------------------------------------------------------------
#define repg(i, a, b, c) for(ll i = a; i < b; i += c)
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rrep(i, a, b) for(ll i = a; i > b; i--)
#define rrepg(i, a, b, c) for(ll i = a; i > b; i -= c)
#define itr(x, cont) for(auto x : cont)
//------------------------------------------------------------------------------------------------------------------------------

// DEBUG------------------------------------------------------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(queue <T> q);
template <class T> void _print(deque <T> q);
template <class T> void _print(stack <T> s);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.FI); cerr << ","; _print(p.SE); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(queue <T> q) {cerr << "[ "; while (!q.empty()) {_print(q.top()); cerr << " "; q.pop();} cerr << "]";}
template <class T> void _print(deque <T> q) {cerr << "[ "; while (!q.empty()) {_print(q.top()); cerr << " "; q.pop_front();} cerr << "]";}
template <class T> void _print(stack <T> s) {cerr << "[ "; while (!s.empty()) {_print(s.top()); cerr << " "; s.pop();} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// -----------------------------------------------------------------------------------------------------------------------------

// BASIC-------------------------------------------------------------------------------------------------------------------------

ll bin_exp(ll a, ll b, ll mod){ll ans = 1;while(b > 0){if(b & 1){ans = (ans * a) % mod;}a = (a * a) % mod;b >>= 1;}return ans;}
ll bin_exp(ll a, ll b){ll ans = 1;while(b > 0){if(b & 1){ans *= a;}a *= a;b >>= 1;}return ans;}
ll ceild(ll x, ll y){if(y < 0) y *= -1, x *= -1; else if(y == 0) cout << "DIVZERO \n", exit(0);  return x / y + (x % y > 0);}
ll mod(ll a, ll b){if(a >= 0) return a % b;else return b + a % b;}
ll mod2(ll a, ll b){if(mod(a, b) == 0) return b;return mod(a, b);}
ll gcd(ll a, ll b){if(a > b) swap(a, b); if(a == 0) return b; return gcd(b % a, a);}

// RANDOM -------------------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------------------

vll fact(1e6 + 10);
vll invnum(1e6 + 10);
vll invfact(1e6 + 10);

// ll ncr(ll n, ll r){
// 	if(n >= r){
// 		ll ans = (((fact[n] * invfact[n - r]) % M1) * invfact[r])
// 	}
// }
void presolve(){
	fact[0] = 1;
	fact[1] = 1;
	rep(i, 2, 1e6 + 10){
		fact[i] = fact[i - 1] * i;
		fact[i] %= M1;
	}

}

void solve(){
	ll n;
	cin >> n;

	vector<ll> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	vector<ll> vc = v;

	vector<ll> b(n);
	vector<bool> vis(n, false);
	for(int i = 0; i < min(32ll, n); i++){
		ll cur = 0;
		ll ind = -1;
		for(int j = 0; j < n; j++){
			if(vis[j]){
				continue;
			}
			if(cur < v[j]){
				ind = j;
				cur = v[j];
			}
		}
		vis[ind] = true; 
		b[i] = vc[ind];

		for(int j = 0; j < n; j++){
			v[j] = (vc[j] | cur);
		}
	}

	ll cur = 0;
	for(int i = 32; i < n; i++){
		while(vis[cur]) cur++;
		b[i] = vc[cur];
	}

	for(int i = 0; i < n; i++){
		cout << b[i] << " ";
	}
	cout << "\n";



}

int main(){

    auto start = chrono :: high_resolution_clock :: now();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    cin >> t;
    int tc = 1;

    presolve();

    while(t--){
        testdebug(tc);
        //cout << "Case #" << tc << ": ";
        solve();

        tc++;
    }

    auto stop = chrono ::  high_resolution_clock :: now();

    #ifndef ONLINE_JUDGE
    auto duration = chrono :: duration_cast <chrono :: milliseconds> (stop - start);
    cerr << "Time exe: "<< duration.count() <<"ms"<< endl;
    #endif

    return 0;
}