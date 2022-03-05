#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
using namespace std;

ll BinExpItr(int a , int b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string k="";
    for(int i=0 ; i< n ; i++){
        if(s[i]<s[i+1]){
            k=s.substr(0,i+1);
            break;
        }
    }
    if(k!=""){
    cout<<k;
    reverse(all(k));
    cout<<k<<"\n";
    }
    else{
        cout<<s;
        reverse(all(s));
        cout<<s<<"\n";
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