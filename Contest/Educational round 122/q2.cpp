#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endli "\n"
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
using namespace std;

void solve(){
    string s;
    cin>>s;
    int c0=0,c1=0;
    // c1=count(s.begin(),s.end(),'1');
    // c0=count(s.begin(),s.end(),'0');
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='0') c0++;
        else c1++;
    }
    if(s.size()<=2) cout<<0<<endli;
    else if(c1==c0){
        cout<<c1-1<<endli;
    }
    else cout<<min(c1,c0)<<endli;
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