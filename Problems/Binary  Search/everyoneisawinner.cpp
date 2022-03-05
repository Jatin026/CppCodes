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
    set<int> s;
    s.insert(0);
    for (int i = 1; i*i <= n; i++)
    {
        s.insert(i);
        s.insert(n/i);
    }
    cout<<s.size()<<"\n";
    for (int ele : s)
    {
        cout<<ele<<" ";
    }
    
    cout<<"\n";
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