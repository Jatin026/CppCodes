#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
#define print(x) cout<<"Case #"<<x<<": ";
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
void solve(){
    
}
int main(){
    FAST
    int t;
    cin>>t;
    for (int j = 1; j<= t; j++)
    {
        ll n,sum=0,k;
        cin>>n>>k;
        int arr[n];
        for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
        print(j);cout<<sum%k<<"\n";
    }
    
    return 0;
}