#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define end "\n"
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
using namespace std;

void solve(){
    ll hc,dc,hm,dm,k,w,a;
    cin>>hc>>dc>>hm>>dm>>k>>w>>a;
    for (int i = 0; i <= k; i++)
    {
        if(ceil((hc+i*a)*1.0/dm)*(dc+(k-i)*w)>=hm){
            cout<<"YES"<<end;
            return;
        }
    }
    cout<<"NO"<<end;

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