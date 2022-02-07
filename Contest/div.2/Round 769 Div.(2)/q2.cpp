#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        int n,ans=INT_MAX;
        cin>>n;
        int arr[n],xo[n-1];
        for (int i = 0; i<n; i++)
        {
            arr[i]=i;
        }
        sort(arr,arr+n);
        for (int i = 0; i<n-1; i++)
        {
            ans=min(ans,arr[i]^arr[i+1]);
        }
        cout<<ans;
    }
    return 0;
}