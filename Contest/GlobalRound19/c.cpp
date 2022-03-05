#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    ll n,ans=0,c1=0;
    cin>>n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(arr[i]==1 && i!=0 && i!=n-1) c1++;
    }
    for(int i=1;i<n-1;i++){
		if(arr[i]%2)ans+=(arr[i]+1)/2;
		else ans+=arr[i]/2;
}
    if((n==3 && arr[1]%2==1) || c1==n-2 ) cout<<-1<<"\n";
    else cout<<ans<<"\n";
}
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}