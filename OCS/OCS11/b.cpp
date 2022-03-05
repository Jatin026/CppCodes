#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
#define PI 3.141592653589793
using namespace std;

void solve(){
    ll n,r;
    cin>>n>>r;
    long double  f1= (long double)tan(PI/n);
    long double f2= (long double)tan(PI/(2*n));
    cout<<setprecision(20)<<fixed<<((n*f1*f2)/(f1+f2))*r*r;
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