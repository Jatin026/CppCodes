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
    int n;
    cin>>n;
    int arr[n],c1=0,c2=0;
    char col[n];
    bool flag=true;
    for (int i = 0; i < n ; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n ; i++)
    {
        cin>>col[i];
    }
    for (int i = 0; i < n ; i++)
    {
        if((arr[i]<1 && col[i]=='B') || (arr[i]>n && col[i]=='R') ){
                flag=false;
                break;
        }
        else if((arr[i]==1 && col[i]=='B')) c1++;
        else if((arr[i]==n && col[i]=='R')) c2++;
    }
    if(flag==false || c1>1 || c2>1  ) cout<<"NO\n";
    else cout<<"YES\n";
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