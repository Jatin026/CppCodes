#include <bits/stdc++.h>
#define ll long long int
#define loop(i,o,n,step) for(auto i{o}; i < n; i += step)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FAST
    ll n,m,ans{0};
    cin>>n>>m;
    map<ll,ll> mp;
    loop(i,0,n,1){
        ll tmp;
        cin>>tmp;
        mp[tmp]++;
        ans = (ans ^ tmp);
    }
    while(m--){
        ll a,b;
        cin>>a>>b;
        if(mp[a]%2 == 1) ans = ((ans ^a)^b);
        if ( a!= b){
        mp[b]+=mp[a];
        mp[a]=0;
        }
        cout << ans << "\n";
    }
}