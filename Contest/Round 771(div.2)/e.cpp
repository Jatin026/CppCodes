#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
using namespace std;

ll BinExpItr(int a , int b){
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
int cnt(int x){
    int ans=0;
    for(int i=31; i>-1; --i){
        if(((x>>i)&1)){
            ans+=1;
        }
    }
    return ans;
}
 
void solve(){
    int n,k,sum=0,ans=0;
    cin>>n>>k;
    int arr[n];
    int z[31]={0},e[31]={0};
    for (int i = 0; i < n ; i++)
    {
        cin>>arr[i];
        for (int j = 0; j < 32; j++)
        {
            if((arr[i]>>j)&1){
                e[j]++;
            }
            else{
                z[j]++;
            }
        }
    }
    for (int i = 0; i < 32; i++)
    {
        if(z[i]<e[i]){
            ans+=BinExpItr(2,i);
        }
    }
    cout<<ans<<'\n';
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