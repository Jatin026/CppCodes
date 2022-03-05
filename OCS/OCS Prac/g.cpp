#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
using namespace std;

ll BinExpItr(ll a , ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}
void solve(){
    int n,lm=0,ans=0;
    cin>>n;
    int arr[n];
    inputarr(arr,n);
    for (int i = 1; i < n-1; i++)
    {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) lm++;
    }
    if(lm>0){
        if(lm==1){
            for (int i = 1; i < n-1; i++)
        {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            arr[i+1]=arr[i];
            ans++;
            break;
        }
        }
        }
        else{
           for (int i = 1; i < n-1; i++)
        {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1] && lm>1){
            if(i+2<n) arr[i+1]=max(arr[i],arr[i+2]);
            else arr[i+1]=arr[i];
            ans++;
            lm--;
        }
        else if(arr[i]>arr[i-1] && arr[i]>arr[i+1] && lm==1){
            arr[i+1]=arr[i];
            ans++;
            break;
        }
        }  
        }
    }
    cout<<ans<<'\n';
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
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