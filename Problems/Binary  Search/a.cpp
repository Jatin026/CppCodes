#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;
int check(int x){
    int cnt=0,ans=0;
    for (int i = 31 ;i>0; --i)
    {
        if((x>>i)&1){
            ans=max(i,ans);
            cnt++;
        }
    }
    if(cnt==1) return ans;
    else return ans+1;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    if(k<check(n)) cout<<0<<'\n';
    else cout<<k-check(n)<<'\n';
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
// #include<bits/stdc++.h>
// #define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #define ll long long
// #define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
// #define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
// using namespace std;

// void solve(){
//     ll n,k;
//     cin>>n>>k;
//     if(k<ceil(log2(n)+1)) cout<<0<<'\n';
//     else cout<<k-ceil(log2(n))<<'\n';
// }
// int main(){
//     FAST
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }