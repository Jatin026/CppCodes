#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;
int binary(int q , int x[] , int n ){
    ll l=0, r=n;
    while(l+1<r){
        ll mid=(l+r)/2;
        if(x[mid]>q){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    if(r==1){
        if(x[0]<=q) return 1;
        else return 0;
    }
    else return r;
}
void solve(){
    ll n,q;
    cin>>n;
    int x[n];
    inputarr(x,n);
    sortarr(x);
    int l;
    cin>>l;
    while(l--){
        int q;
        cin>>q;
        cout<<binary(q,x,n)<<"\n";
    }

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