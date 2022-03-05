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
// 1 2 5 6
// 1 6 5 2
void solve(){
int n,ind=0,c=0,val;
    cin>>n;
    bool flag=false;
    int arr[n],temp[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        temp[i]=arr[i];
    }
    sort(temp,temp+n);
    for (int i = 0; i < n; i++)
    {
       if(arr[i]!=temp[i] ){
           ind=i;
           break;
       }
    }
    for (int i = 0; i < n; i++)
    {
       if(temp[ind]==arr[i]){
           c=i;
           break;
       }
    }
    // cout<<ind<<" "<<c;
    reverse(arr+ind,arr+c+1);
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