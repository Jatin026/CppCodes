#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    int n,max_v=INT_MIN;
    cin>>n;
    int score[n];
    map<string , int > m,p;
    string s[n],ans;
    for (int i = 0; i < n ; i++)
    {
        
        cin>>s[i]>>score[i];
        m[s[i]]+=score[i];
    }
    for (int i = 0; i < n ; i++)
    {
        max_v=max(max_v,m[s[i]]);
    }
    for (int i = 0; i < n; i++)
    {
        p[s[i]]+=score[i];
        if(p[s[i]]>=max_v && m[s[i]]==max_v ){
            cout<<s[i];
            return;
        }
    }
}
int main(){
    FAST
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}