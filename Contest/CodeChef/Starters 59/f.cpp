#include<bits/stdc++.h>
#include<chrono>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(s) s.begin(),s.end()
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define binarystring(n,x) bitset<n> (x).to_string()
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define MOD            1000000007
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
class Mint
{
//WARNING:
//Be very careful not to use two Mints with different mods for any operation
//No guarantee of behavior in this case
public:
ll val;
static ll mod_exp(ll a, ll b){ ll res=1;   a=a%MOD; while(b>0){ if(b%2==1) res=(res*a)%MOD; b/=2; a=(a*a)%MOD; } return res; }
static ll gcdExtended(ll a, ll b, ll *x, ll *y) { if (a == 0) { *x = 0, *y = 1; return b; } ll x1, y1; ll gcd = gcdExtended(b%a, a, &x1, &y1);*x = y1 - (b/a) * x1; *y = x1; return gcd; }
static ll modInverse(ll a) { ll x, y; 	ll g = gcdExtended(a, MOD, &x, &y); g++; ll res = (x%MOD);	if(res < 0) res += MOD;	return res;} 
Mint(){	val = 0;} 
Mint(ll x){	val = x%MOD;	if(val < 0) val += MOD;}
Mint& operator +=(const Mint &other){	val += other.val;	if(val >= MOD) val -= MOD; return (*this); }
Mint& operator -=(const Mint &other){   val -= other.val;if(val < 0) val += MOD;  return (*this); }
Mint& operator *=(const Mint &other){	val = (val * other.val)%MOD; return (*this); }
Mint& operator /=(const Mint &other){	val = (val * modInverse(other.val)) % MOD; return (*this); }
Mint& operator =(const Mint &other) { 	val = other.val; return (*this); }
Mint operator +(const Mint &other) const {	return Mint(*this) += other; }
Mint operator -(const Mint &other) const {	return Mint(*this) -= other; }
Mint operator *(const Mint &other) const {	return Mint(*this) *= other; }
Mint operator /(const Mint &other) const {	return Mint(*this) /= other; }
bool operator ==(const Mint &other) const {   return val == other.val; }
Mint operator ++() { ++val; if(val == MOD) val = 0; return (*this); }
Mint operator ++(int) { val++; if(val == MOD) val = 0; return Mint(val-1); }
Mint operator --() { --val; if(val == -1) val = MOD-1; return (*this); }
Mint operator --(int) { val--; if(val == -1) val = MOD-1; return Mint(val+1); }
// ^ has very low precedence, careful!!
template<typename T>
Mint& operator ^=(const T &other){   val = mod_exp(val, other); return (*this); }
template<typename T>
Mint operator ^(const T &other) const {  return Mint(*this) ^= other; }
Mint& operator ^=(const Mint &other){   val = mod_exp(val, other.val); return (*this); }
Mint operator ^(const Mint &other) const {  return Mint(*this) ^= other; }
template<typename T>
explicit operator T() {	return (T)val; }
template<typename T>
friend Mint operator +(T other, const Mint &M){	return Mint(other) + M; }
template<typename T>
friend Mint operator -(T other, const Mint &M){	return Mint(other) - M; }
template<typename T>
friend Mint operator *(T other, const Mint &M){	return Mint(other) * M; }
template<typename T>
friend Mint operator /(T other, const Mint &M){	return Mint(other) / M; }
template<typename T>
friend Mint operator ^(T other, const Mint &M){	return Mint(other) ^ M; }
friend std::ostream &operator << (std::ostream &output, const Mint &M){  return output << M.val; }
friend std::istream &operator >> (std::istream &input, Mint &M) { input >> M.val;	M.val %= MOD;	return input;}};




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

bool div2(string  s){
    if((s[s.size()-1]-48)%2==0) return 1;
    else return 0;
}
bool div5(string s){
    if((s[s.size()-1]-48)%5==0) return 1;
    else return 0; 
}
bool div3(string s){
    int sum=0;
    for (int i = 0; i < s.size(); i++)
    {
        sum+=s[i]-48;
    }
    if(sum%3==0) return 1;
    else return 0;
}
bool div4(string s){
    if(s.size() == 1){
        if((s[0]-48)%4==0) return 1;
        else return 0;
    }
    else{
        reverse(all(s));
        int a = s[0]-48;
        int b = s[1]-48;
        if((b*10+a)%4==0) return 1;
        else return 0;
    }
}
bool div6(string s){
    return (div2(s)&div3(s));
}
bool div8(string s){
    if(s.size() == 1){
        if((s[0]-48)%8==0) return 1;
        else return 0;
    }
    else {
        reverse(all(s));
        if(s.size()==2){
        int a = s[0]-48;
        int b = s[1]-48;
        if((b*10+a)%8==0) return 1;
        else return 0;
        }
        else{
            int a = s[0]-48;
            int b = s[1]-48;
            int c = s[2]-48;
            if((c*100+b*10+a)%8==0) return 1;
            else return 0;
        }
    }
}
bool div9(string s){
    int sum=0;
    for (int i = 0; i < s.size(); i++)
    {
        sum+=s[i]-48;
    }
    if(sum%9==0) return 1;
    else return 0;
}
bool div7(string num)
{
	int n = num.length(), gSum=0;
	if (n == 0)
		return 1;

	// Append required 0s at the beginning.
	if (n % 3 == 1) {
		num="00" + num;
		n += 2;
	}
	else if (n % 3 == 2) {
		num= "0" + num;
		n++;
	}

	// add digits in group of three in gSum
	int i, GSum = 0, p = 1;
	for (i = n - 1; i >= 0; i--) {

		// group saves 3-digit group
		int group = 0;
		group += num[i--] - '0';
		group += (num[i--] - '0') * 10;
		group += (num[i] - '0') * 100;

		gSum = gSum + group * p;

		// generate alternate series of plus
		// and minus
		p *= (-1);
	}

	return (gSum % 7 == 0);
}
 
void solve(){
    string s; cin>>s;
    vi cost(8);  for (int i = 0; i < 7; i++)
    {
        cin>>cost[i+1];
    }
    
    vi val(10);
    val[0]=cost[1]+cost[2]+cost[3]+cost[4]+cost[5]+cost[6];
    val[1]=cost[2]+cost[3];
    val[2]=cost[1]+cost[2]+cost[4]+cost[5]+cost[7];
    val[3]=cost[1]+cost[2]+cost[3]+cost[4]+cost[7];
    val[4]=cost[2]+cost[3]+cost[7]+cost[6];
    val[5]=cost[1]+cost[3]+cost[4]+cost[6]+cost[7];
    val[6]=cost[1]+cost[3]+cost[4]+cost[5]+cost[6]+cost[7];
    val[7]=cost[1]+cost[2]+cost[3] ;
    val[8]=cost[1]+cost[2]+cost[3]+cost[4]+cost[5]+cost[6]+cost[7];
    val[9]=cost[1]+cost[2]+cost[3]+cost[4]+cost[6]+cost[7];
    int ans=1e9;
    ans=min(ans,val[1]);
    debug(ans)
    if(div2(s)) ans=min(ans,val[2]);
    if(div3(s)) ans=min(ans,val[3]);
    if(div4(s)) ans=min(ans,val[4]);
    if(div5(s)) ans=min(ans,val[5]);
    if(div6(s)) ans=min(ans,val[6]);
    if(div8(s)) ans=min(ans,val[8]);
    if(div9(s)) ans=min(ans,val[9]);
    if(div7(s)&div8(s)) ans=min(ans,val[5]+val[6]);
    debug(div7(s)&div8(s))
    debug(ans)
    int vall=0;
    if(s.size()<=10){
        ll num = stoll(s);
        for (ll i = 1; i*i <= num; i++)
        {
            if(num%i==0){
                string s1 = to_string(i);
                for (int j = 0; j < s1.size(); j++)
                {
                    vall+=val[s1[j]-48];

                }
                debug(i)
                debug(vall)
                ans=min(ans,vall);
                vall=0;
                s1 = to_string(num/i);
                for (int j = 0; j < s1.size(); j++)
                {
                    vall+=val[s1[j]-48];

                }
                debug(num/i) debug(vall)
                ans=min(ans,vall);
                vall=0;
            }
        }
        
    }
    for (int i = 0; i < s.size(); i++)
    {
        vall+=val[(s[i]-48)];
    }
    
    
    cout<<min(ans,vall)<<nline;
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

 

 