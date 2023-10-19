#include<bits/stdc++.h>

#define FAST         ios_base::sync_with_stdio(false); \
                     cin.tie(0);                       \
                     cout.tie(0);

#define ll long long
#define el "\n"
#define sp " "
#define ff first
#define ss second

using namespace std ;

int MOD = 998244353 ;

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
 

void solve_this_testcase ( )
{
    int n ;
    Mint  q ;
    cin>>n>>q;
    Mint p ;
    Mint t = 3 ;
    Mint tt = 10000 ;
    p = q / tt ;
    Mint pp = Mint(1) - p ;
    vector<Mint> D(n+1,0) ;
    D[0] = 1 ;
    for ( int i = 0 ; i < n  ; ++i )
    {
        vector<Mint> DD(n+1,0) ;
        DD[0] += D[0]*2*p;
        DD[1] += D[0]*p;
        for ( int j = 1 ; j < i + 1 ; ++j) 
        {
            DD[j-1] += D[j]*pp;
            DD[j]   += D[j]*2  ;
            DD[j+1] += D[j]*p    ;
        }
        for ( int k = 0 ; k < n + 1 ; ++k )
        {
            DD[k] /= t ;
        }
        swap(D,DD);
    }
    Mint ans = 0;
    for ( int i = 0 ; i < n + 1 ; ++i )
    {
        ans += D[i] ;
    }
    cout << ans ;
    
}

int main()
{
    
    FAST
    
    ll test = 1 ;
    
    //cin >> test ;
    
    for ( ll testtest = 0 ; testtest < test ; testtest++ ) 
    
    {
    
        solve_this_testcase ( ) ;
    
    }

}