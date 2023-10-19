#include<bits/stdc++.h>
#include<chrono>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(s) s.begin(),s.end()
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define binarystring(n,x) bitset<n> (x).to_string()
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
// #define MOD            1000000007
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
           // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
           return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const {
           static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
};
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
 
const int MOD = 1e9 + 7;
const int BUF_SZ = 1 << 15;

inline namespace Input {
char buf[BUF_SZ];
int pos;
int len;
char next_char() {
    if (pos == len) {
        pos = 0;
        len = (int)fread(buf, 1, BUF_SZ, stdin);
        if (!len) { return EOF; }
    }
    return buf[pos++];
}

int read_int() {
    int x;
    char ch;
    int sgn = 1;
    while (!isdigit(ch = next_char())) {
        if (ch == '-') { sgn *= -1; }
    }
    x = ch - '0';
    while (isdigit(ch = next_char())) { x = x * 10 + (ch - '0'); }
    return x * sgn;
}
}  // namespace Input
inline namespace Output {
char buf[BUF_SZ];
int pos;

void flush_out() {
    fwrite(buf, 1, pos, stdout);
    pos = 0;
}

void write_char(char c) {
    if (pos == BUF_SZ) { flush_out(); }
    buf[pos++] = c;
}

void write_int(int x) {
    static char num_buf[100];
    if (x < 0) {
        write_char('-');
        x *= -1;
    }
    int len = 0;
    for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
    write_char((char)('0' + x));
    while (len) { write_char(num_buf[--len]); }
    // write_char('\n');
}

// auto-flush output when program exits
void init_output() { assert(atexit(flush_out) == 0); }
} 

void solve(){
    int n = Input::read_int(), k =  Input::read_int();
    // cin >> n >> k;
    
    vector<pair<int,int>> seg(n);
    vi ele;
    map<int,int> comp;
    // for(auto &x : seg) cin >> x.first >> x.second;
    for(auto &x : seg){
        x.first =  Input::read_int();
        x.second =  Input::read_int();
    }
    vector<int> leftt(4*n);
    for(int i = 0; i < n ; i++){
        leftt[4*i] = 2*seg[i].first;
        leftt[4*i+1] = 2*seg[i].first-1;
        leftt[4*i+2] = 2*seg[i].second;
        leftt[4*i+3] = 2*seg[i].second+1;
    }
    sort(all(leftt));
    leftt.resize(unique(all(leftt))-begin(leftt));
    int ind = 1;
    vi rev(leftt.size()+10);
    // for(auto &x : comp) {
    //     x.second = ind++;
    //     rev[x.second] = x.first/2;
    // }
    for(auto x : leftt){
        rev[ind] = x/2;
        comp[x] = ind++;
    }
    vector<int> pref(ind+2);
    for(auto &x : seg){
        pref[comp[2*x.first]]++;
        pref[comp[2*x.second]+1]--;
    }
    for(int i = 1; i <= ind ; i++){
        pref[i] += pref[i-1];
    }

    vector<pair<int,int>> ans;
    // ans.reserve(1e5);
    int left = -1;
    for(int i = 1 ; i <= ind+1 ; i++){
        if(pref[i] >= k){
            if(left == -1) left = i;
        }
        else{
            if(left != -1){
                ans.emplace_back(left,i-1);
                left = -1;
            }
        }
    }
    Output::write_int(ans.size());
    // cout << ans.size() << nline;
    Output::write_char('\n');
    // for(auto &x : ans) cout << rev[x.first] << " " << rev[x.second]  << nline;
    for(auto &x : ans) {
        Output::write_int(rev[x.first]);
        Output::write_char(' ');
        Output::write_int(rev[x.second]);
        Output::write_char('\n');
    }
    Output::init_output();
}
int main(){
    FAST
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}