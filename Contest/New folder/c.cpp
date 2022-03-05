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
    int n,ans=0;
    cin>>n;
    int arr[n];
    inputarr(arr,n);
    if(arr[n-2]>arr[n-1]){
        cout<<"-1\n";
    }
    else{
    if(arr[n-1]<0){
        if(is_sorted(arr,arr+n)){
        cout<<"0\n";
        }
        else cout<<"-1\n";
    }
    else{
        cout<<n-2<<"\n";
        for (int i = 1; i < n-1; i++)
        {
            cout<<i<<" "<<n-1<<" "<<n<<"\n";
        }
    }
    } 

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