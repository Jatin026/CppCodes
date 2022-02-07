#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
#define reverses(s) reverse(s.begin(),s.end());
using namespace std;
bool check(string s){
    string k=s;
    reverse(s.begin(),s.end());
    return (s==k);
}
int f(string str, int m ){
    set<string> s;
    string l;
    for (int i = 0; i < m; i++)
    {
        string k=str;
        reverse(str.begin(),str.end());
        l=str+k;
        s.insert(l);
        s.insert(k+str);
        str=k+str;
    }
    return s.size();
}
void solve(){
    int n,m;
    cin>>n>>m;
    string str,l;
    cin>>str;
    // set<string> s;
    // if(m==0) cout<<1<<'\n';
    // else cout<<f(str,m)f(str,m-1)<<'\n';
    if(check(str) || m==0) cout<<1<<'\n';
    else cout<<2<<'\n';
    
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