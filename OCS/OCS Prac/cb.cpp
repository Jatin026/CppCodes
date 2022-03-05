#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
using namespace std;

ll BinExpItr(ll a , ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a);
        }
        a=(a*a);
        b>>=1;
    }
    return res;
}

bool good(ll x , ll n){
    return ((x*x+x*x*x)>=n);
}
ll binary(ll n){    
    ll l=0,r=cbrt(n)+1,ans;
    while (l+1<r)
    {
        ll mid=(l+r)/2;
        if(good(mid,n)){
            ans=mid;
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return r;
}
void solve(){
    ll n;
    cin>>n;
 
    ll mi=LONG_LONG_MAX;ll p=LONG_LONG_MAX,q=LONG_LONG_MAX,r=LONG_LONG_MAX;
    set<string> s;
    
       for (int b = 0; BinExpItr(b,5) <= n; b++)
        {
            for (int c = 0; BinExpItr(c,7) <= n; c++)
        {
            
            ll a=binary(n-BinExpItr(b,5)-BinExpItr(c,7));// N-> N-b^5-c^7  , a^2+a^3>=n,
            ll check=abs(n-(a*a)-(a*a*a)-BinExpItr(b,5)-BinExpItr(c,7));
            mi=min(check,mi);
            a-=1;
            check=abs(n-(a*a)-(a*a*a)-BinExpItr(b,5)-BinExpItr(c,7));
            mi=min(check,mi);
            a+=2;
            check=abs(n-(a*a)-(a*a*a)-BinExpItr(b,5)-BinExpItr(c,7));
            mi=min(check,mi);
        }
        }
        for (int b = 0; BinExpItr(b,5) <= n; b++)
        {
            for (int c = 0; BinExpItr(c,7) <= n; c++)
        {
            ll a=binary(n-BinExpItr(b,5)-BinExpItr(c,7));
            ll check=abs(n-(a*a)-(a*a*a)-BinExpItr(b,5)-BinExpItr(c,7));
            if(check<=mi){
                 
                string k="";
                k+=to_string(a);
                k+=" ";
                k+=to_string(b);
                k+=" ";
                k+=to_string(c);
                s.insert(k);
                 
            }
            a-=1;
            check=abs(n-(a*a)-(a*a*a)-BinExpItr(b,5)-BinExpItr(c,7));
            if(check<=mi){
                 
                string k="";
                k+=to_string(a);
                k+=" ";
                k+=to_string(b);
                k+=" ";
                k+=to_string(c);
                s.insert(k);
                
            }
            a+=2;
            check=abs(n-(a*a)-(a*a*a)-BinExpItr(b,5)-BinExpItr(c,7));
            if(check<=mi){
                 
                string k="";
                k+=to_string(a);
                k+=" ";
                k+=to_string(b);
                k+=" ";
                k+=to_string(c);
                s.insert(k);
                 
            }
        }
        } 
  
    auto it = s.begin();
    cout<<*(it);
        
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