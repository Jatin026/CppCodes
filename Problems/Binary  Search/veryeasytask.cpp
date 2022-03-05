#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;
bool check(int mid,int n , int x, int y){
    int count = (mid - min(x,y)>=0);
    mid=mid - min(x,y);
    count += (mid/x)+(mid/y);
    return (count>=n);
}
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    ll l=0,r=INT_MAX;
    while(l+1<r){
        ll mid=(l+r)/2;
        if(check(mid,n,x,y)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<r;
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