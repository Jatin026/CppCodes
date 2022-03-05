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
void solve(){
    ll n,s,l=0,al,ar,size=INT_MIN;
    cin>>n>>s;
    int arr[n],r=n-1;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int r = 0; r < n; r++)
    {
        s+=arr[r];
        while(s<0 && l<=r){
            s-=arr[l];
            l++;
        }
        if(r-l+1>size && s>=0){
            al=l+1;
            ar=r+1;
            size=r-l+1;
        }
    }
    if(al>ar) cout<<-1<<"\n";
    else cout<<al<<" "<<ar<<"\n";
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