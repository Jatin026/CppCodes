#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;
int check(int x){
    for (int i = 31; i >-1; --i)
    {
        if(((x>>i)&1)){
            return i;
        }
    }
    
}
void solve(){
    int w,h,n,co=0,ce=0;
    cin>>w>>h>>n;
    while((w%2)!=1){
        co++;
        w=w/2;
    } 
    while((h%2)!=1){
        ce++;
        h=h/2;
    } 
    if((pow(2,co))*(pow(2,ce))>=n) cout<<"YES\n";
    else cout<<"NO\n";
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