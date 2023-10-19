#include<bits/stdc++.h>
using namespace std;
 
# define ll long long
# define ld long double
# define pb push_back
# define pll pair<long long,long long>
# define vll vector<long long>
# define vld vector<long double>
# define vpll vector<pair<long long,long long>>
 
const ll mod = 1e9+7;
ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1) {
        // q is quotient
        ll q = a / m;
        ll t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
vll fac,inv_fac;

ll nCr(ll n, ll r){
    if (n < r || n < 0){        
        return 1;
    }
    ll tmp = fac[n];
    tmp *= inv_fac[n-r];
    tmp %= mod;
    tmp *= inv_fac[r];
    tmp %= mod;
    return tmp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tt = 1;
    fac.assign(2e5+5,1);
    inv_fac.assign(2e5+5,1);
    for (ll i=1;i<2e5+5;i++){
        fac[i] = i*fac[i-1];
        fac[i] %= mod;
        inv_fac[i] = modInverse(fac[i],mod);
    }
    // cout<<fixed<<setprecision(15);
    cin>>tt;
    while (tt--)    
    {
        ll n,m; cin>>n>>m;
        vll x(n),y(m);
        map<ll,ll>mpx,mpy;   
        for (ll i=0;i<n;i++){
            cin>>x[i];
            mpx[x[i]]++;
        }
        ll sum = 0;
        for (ll i=0;i<m;i++){
            cin>>y[i];
            mpy[y[i]]++;
            sum += y[i];
        }
        sum = -sum;
        y.pb(sum);
        mpy[sum]++;
        ll res = 0;
        ll ans = 1;
        multiset<ll>st;
        for (pll i : mpy){
            if (mpx[i.first] < mpy[i.second]-1){
                cout<<"0\n";
                return 0;
            }          
            if (mpx[i.first] < mpy[i.second])
                st.insert(i.first);  
            ans *= nCr(mpx[i.first],i.second);
            ans %= mod;
        }                
      
        for (ll i : y){
            ll tmp = ans;            
            tmp *= modInverse(nCr(mpx[i],mpy[i]),mod);
            tmp %= mod;
            bool flag = 0;
            if (st.find(i) != st.end()){
                flag = 1;
                st.erase(st.find(i));
            }
            if (st.size() == 0)
                res += tmp;
            if (flag)
                st.insert(i);
            
            res %= mod;
        }
        cout<<res<<'\n';
        
    }
    return 0;
}