#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    int n,k,co,ce;
    cin>>n>>k;
    if(n*k%2==0){
        co=n*k/2;
        ce=co;
    }
    else{
        co=n*k/2+1;
        ce=co-1;
    }
    if(co%k==0 && ce%k==0){
        int count=0;
        cout<<"YES\n";
        for (int i = 1; i <= n*k; i++)
        {
            if(i%2==1){
                cout<<i<<" ";
                count++;
            }
            if(count%k==0 && i%2==1) cout<<'\n';
        }
        for (int i = 1; i <= n*k; i++)
        {
            if(i%2==0){
                cout<<i<<" ";
                count++;
            }
            if(count%k==0 && i%2==0) cout<<'\n';
        }
        
    }
    else{
        cout<<"NO"<<'\n';
    }
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
