#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
using namespace std;
 
void solve(){
    int n,ans=INT_MIN,l=0;
    cin>>n;
    int arr[n];
    inputarr(arr,n);
    sort(arr,arr+n);
    for (int i = 0; i < n; i++)
    {
        arr[i]=l+arr[i];
        ans=max(ans,arr[i]);
        // cout<<arr[i]<<'\n';
        l-=arr[i];
           
    }
    cout<<ans<<"\n";
    
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