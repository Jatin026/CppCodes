#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    int n,max_v=INT_MIN;
    cin>>n;
    map<string , int > m;
    string ans;
    for (int i = 0; i < n ; i++)
    {
        string s;
        int k;
        cin>>s>>k;
        m[s]+=k;
        if(m[s]>max_v){
            ans=s;
            max_v=m[s]; 
    }
    }
    cout<<ans;
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