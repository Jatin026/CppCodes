#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
void solve(){
    int n,count=0;
    cin>>n;
    int arr[n];
    for(int i=0 ; i< n ; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for (int i = 0; i < n-1; i++)
    {
        for(int j=i+1; j<n ; j++){
        count+=(arr[i]&arr[j])>=(arr[i]^arr[j]) ;
    }
    }
    cout<<count<<'\n';
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