#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    int n;
    ll sum=0;
    cin>>n;
    int a[n],b[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    for (int i = 1; i < n; i++)
    {
        if(abs(a[i]-a[i-1])>abs(b[i]-a[i-1])){
            swap(a[i],b[i]);
        }
    }
    for(int i=0; i< n-1; i++){
        for (int j = i+1; j < n; j++)
        {
            sum+=pow((a[i]+a[j]),2)+ pow((b[i]+b[j]),2);
        } 
    }
    cout<<sum<<"\n";
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