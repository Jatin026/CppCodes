#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
const int N =  1e6+3;
using namespace std;
using namespace std;
ll binexprec(ll a , ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}
ll BinExpItr(int a , int b){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}
bool good(ll x , ll n){
    return ((x*x+x*x*x)>=n);
}
ll binary(ll n){
    ll l=0,r=n,ans;
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
    return ans;
}
void solve(){
    ll n;
    cin>>n;
    ll mi=LONG_MAX;ll p=LONG_MAX,q=LONG_MAX,r=LONG_MAX;
    ll t=binary(n);
    for(ll c=0;BinExpItr(c,7)<=2*n;c++)
    {
       for(ll b=0;BinExpItr(b,5)<=2*n;b++)
       {
        for(ll a=0;a<=min(100,(int)cbrt(n));a++)
        {    ll check=abs(n-(a*a)-(a*a*a)-binexprec(b,5)-binexprec(c,7));
            if(check<=mi )
            {
                mi=check;
                   p=a;
                   q=b;
                   r=c;
                //cout<<p<<" "<<q<<" "<<r<<" "<<mi<<endl;   
            }
        }
       } 
    }  set<string> s;
    for(ll c=0;BinExpItr(c,7)<=2*n;c++)
    {  //cout << " I was here1\n";
       for(ll b=0;BinExpItr(b,5)<=2*n;b++)
       { //cout << " I was here2\n";
        for(ll a=0;a<=min(100,(int)cbrt(n));a++)
        {    ll check=abs(n-(a*a)-(a*a*a)-binexprec(b,5)-binexprec(c,7));
         //cout << " I was here3\n";
            if(check==mi )
            {  //    cout << " I was here4\n";
                   mi=check;
                   p=a;
                   q=b;
                   r=c;
                 
                    string k="";
                    k+=to_string(a);
                    k+=" ";
                    k+=to_string(b);
                    k+=" ";
                    k+=to_string(c);
                    s.insert(k);
                  //cout<<p<<" "<<q<<" "<<r<<" "<<mi<<endl;   
            }
        }
       } 
    }
     
    auto it = s.begin();
    cout<<*(it);
      
}
signed main(){
    FAST
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}



 