#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    ll r,x,y,x1,y1;
    cin>>r>>x>>y>>x1>>y1;
    long double d= pow( pow(x1-x,2)+pow(y1-y,2)  , 0.5); 
    cout<<ceil(d/(2*r));
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