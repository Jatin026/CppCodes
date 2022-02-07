#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define inputarr(arr,n) for(ll index=0; index < n ; index++) cin>>arr[index];

#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
using namespace std;

void solve(){
    ll n,k,i=0,j=0 ;
    cin>>n>>k;
    ll a1[n],a2[k],cnt[k+1]={0};
    inputarr(a1,n);
    inputarr(a2,k);
    while( j<=k){
        if(a2[j]==a1[i]){
            cnt[j+1]++;
            i++;
        }
        else if(a2[j]>a1[i]) i++;
        else{
            ll temp=j+1;
            while(a2[temp]==a2[j] && temp<k){
                cnt[temp+1]=cnt[j+1];
                temp++;
            }
            j=temp;
        }
    }
    for(ll index=1; index < k+1 ; index++) cnt[index]+=cnt[index-1] ;
    cout<<cnt[k];
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