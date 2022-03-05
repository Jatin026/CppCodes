#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    inputarr(arr,n);
    sortarr(arr);
    for (int i = 0; i < n-1 ; i++)
    {
        if(arr[i+1]-arr[i]==1){
            cout<<"2\n";
            return;
        }
    }
    cout<<"1\n";
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