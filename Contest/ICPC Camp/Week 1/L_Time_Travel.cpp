#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast,unroll-loops")

// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
using namespace std;
// # define ll int
// # define ld long double
# define pb emplace_back
// # define pll pair<long long,long long>
# define vll vector<int>
// # define vld vector<long double>
// # define vpll vector<pair<long long,long long>>
typedef long long ll;
const int mod = 1e9+7;
const int N=501;
vll g[N];
bitset<N> ans[N][N];
int i,j,l;
/*
*/
const int MOD = 1e9 + 7;
const int BUF_SZ = 1 << 17;

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

void dfs(int r,int p,int par,bitset<N> &b){
    b[r]=1;
    if(par<r)ans[par][r]&=b;
    for(auto it:g[r]){
        if(it!=p){
            dfs(it,r,par,b);
        }
    }
    b[r]=0;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll n = Input::read_int(),k = Input::read_int();
    // cin>>n>>k;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(l=1;l<=n;l++){
                ans[i][j][l]=1;
            }
        }
    }
    while(k--){
        for(i=0;i<=n;i++) g[i].clear();
        for(i=0;i<n-1;i++){
            ll x = Input::read_int(),y = Input::read_int();
            // cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        bitset<N> b=0;
        for(i=1;i<=n;i++){
            b=0;
            dfs(i,i,i,b);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            
            if(i==j) Output::write_char('1');
            else if(i<j)Output::write_int(ans[i][j].count());
            else Output::write_int(ans[j][i].count());
            Output::write_char(' ');
        }
        Output::write_char('\n');
    }
    Output::init_output();
    return 0;
}