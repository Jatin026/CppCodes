 #include <bits/stdc++.h>
 #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC target("arch=skylake")
 #define ll long long
 #define pb push_back
 #define ppb pop_back
 #define endl '\n'
 int const mod = 1000000007;
 #define vl vector<long long>
 using namespace std;
 ll i, j, k;
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
 
 void write_int(ll x) {
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
 /*
 */
 void solve() {
   ll n = Input::read_int(),k = Input::read_int(),t = Input::read_int();
//    cin>>n>>k>>t;
   ll b[n];
   for(i=0;i<n;i++)b[i] = Input::read_int();
   pair<ll, ll> dp[n]={{0,0}};
   multiset<pair<ll, ll>> mini,add;
   mini.insert({-b[0],1});add.insert({b[0],1});
   dp[0]={0,1};
   for(i=1;i<n;i++){
  dp[i]=min(make_pair(b[i]+((*mini.begin()).first)+i*t+t,((*mini.begin()).second+1)),make_pair(-b[i]+((*add.begin()).first)+i*t+t,((*add.begin()).second+1)));
   mini.insert({dp[i].first-b[i]-i*t,dp[i].second});
   add.insert({dp[i].first+b[i]-i*t,dp[i].second});
   if(i>=k){
      mini.erase(mini.find(make_pair(dp[i-k].first-b[i-k]-(i-k)*t,dp[i-k].second)));
      add.erase(add.find(make_pair(dp[i-k].first+b[i-k]-(i-k)*t,dp[i-k].second)));  
    }
  }
  Output::write_int(dp[n-1].first); Output::write_char(' '); Output::write_int(dp[n-1].second);Output::write_char('\n');
//   cout<<dp[n-1].first<<" "<<dp[n-1].second<<"\n";
  ll curr=n-1;
  int cnt = 0;
   for(i=n-2;i>=0;i--){
    if(dp[curr].first==dp[i].first+(curr-i+1)*t-abs(b[curr]-b[i]) && dp[curr].second==dp[i].second+1){
        cnt++;
        // ans.pb(i+1);
        curr=i;
    }
   }
   curr = n -1;
    int ans[cnt+1];
    ans[cnt] = n;
   for(i=n-2;i>=0;i--){
    if(dp[curr].first==dp[i].first+(curr-i+1)*t-abs(b[curr]-b[i]) && dp[curr].second==dp[i].second+1){
        ans[--cnt] = i + 1;
        curr=i;
    }
   }
//    reverse(ans.begin(),ans.end());
   for(auto val:ans)Output::write_int(val) , Output::write_char(' ');
   Output::write_char('\n');
    init_output();
 }
 int main() {
    //  ios_base::sync_with_stdio(false);
    //  cin.tie(NULL);
     int tt = Input::read_int();
    //  cin >> tt;
     while (tt--) {
         solve();
     }
     return 0;
 }