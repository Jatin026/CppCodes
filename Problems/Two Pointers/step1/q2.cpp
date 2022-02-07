#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];

#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
using namespace std;

void solve(){
    int n,k,i=0,j=0;
    cin>>n>>k;
    int a1[n],a2[k],cnt[k+1];
    memset(cnt,0,sizeof(cnt));
    inputarr(a1,n);
    inputarr(a2,k);
    while(i<n){
        if(a2[j]>a1[i]){
            cnt[j+1]++;
            i++;
        }
        else{
            j++;
        }
    }
    for(int index=1; index < k+1 ; index++) cnt[index]+=cnt[index-1];
    for(int index=1; index < k+1 ; index++) cout<<cnt[index]<<" ";
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