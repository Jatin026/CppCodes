#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    ll n,s1=0,s2=0,ce=0;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for (int i = n-1; i >-1; --i)
    {
        if(ce%2==0){
            if(arr[i]%2==0) s2+=arr[i];
    }
        else{
            if(arr[i]%2==1) s1+=arr[i];
        }
        ce++;
    }
    if(s1==s2) cout<<"Tie\n";
    else if(s2>s1) cout<<"Alice\n";
    else cout<<"Bob\n";
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