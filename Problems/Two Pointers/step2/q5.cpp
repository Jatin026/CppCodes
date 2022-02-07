#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;
const int N = 1e5+7;
int cnt[N];
void solve(){
    ll n,k;
    cin>>n>>k;
    ll arr[n+1]={0};
    for (int i = 1; i <=n ; i++)
    {
        cin>>arr[i];
    }
    ll l=1 , ans=0, num=0 ;
    for (int r = 1; r <= n ; r++)
    {
        cnt[arr[r]]++;
        if(cnt[arr[r]]==1) num++;
        while(num > k){

            cnt[arr[l]]--;
            if(cnt[arr[l]]==0) num--;
            l++;
        }
        ans+=r-l+1;
    }
    cout<<ans;
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