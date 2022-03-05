#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n),sorta(n),temp(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        sorta[i]=v[i];
        temp[i]=v[i];
    }
    sort(all(sorta));
    if(sorta==v){
        cout<<"NO\n";
        return;
    }
    for (int i = 1; i <n ; i++)
    {
        sort(v.begin(),v.begin()+i);
        sort(v.begin()+i,v.end());
        if(v!=sorta){
            cout<<"YES\n";
            return;
        }
        v=temp;
    }
    cout<<"NO\n";

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