#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    string s;
    cin>>s;
    string v="";
    for(int i =0 ;i<s.size()-1;++i)
    {
        if(s.substr(i,2)=="AB" ||s.substr(i,2)=="BA" ){
            v+=s.substr(i,2);
            i++;
        }
    }
    cout<<v;
    for(int i =0 ;i<v.size();++i)
    {
        if(v[i] == v[i+1])
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
signed main(){
    FAST
    int t=1;
  //  cin>>t;
    while(t--){
        solve();
    }
    return 0;
}