#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    long double l,h,t, count=1, mid;
    cin>>h>>l>>t;
    if(l==t || h==t){
        cout<<1;
        return;
    }
    while(l<=h){
        mid=(l+h)/2;
        if(mid>t) h=mid+0.001;
        else if(mid<t) l=mid-0.001;
        else {
            count++;
            break;
        }

        count++;
    }
    cout<<count<<"\n";
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