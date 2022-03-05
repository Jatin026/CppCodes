#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;

void solve(){
    int n;
    cin>>n;
    pair<pair<int,int>,int> p[n], m[n];
    int ans[n];
    memset(ans,-1,sizeof(ans));
    for (int i = 0; i < n; i++)
    {
        cin>>p[i].first.first>>p[i].first.second;
        m[i].first.first=p[i].first.second;
        m[i].first.second=p[i].first.first;
        p[i].second=i+1;
        m[i].second=i+1;
    }
    sort(p,p+n);
    sort(m,m+n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<p[i].first.first<<"   "<<p[i].first.second<<"   "<<p[i].second<<"  "<<m[i].second;
    //     cout<<"\n";
    // }
    bool flag=false;
    int index;
    for (int i = 0; i < n; i++)
    {
        if(flag){
            ans[p[i].second-1]=index;
        }
        else{
            if(p[i].first.second>p[0].first.second && p[i].first.first>p[0].first.first ){
                // cout<<p[i].first.first<<" "<<p[i].first.second<<"   "<<i<<"\n";
                index=p[i].second;
                flag=true;
            }
        }
    }
    flag=false;
    for (int i =0; i < n; i++)
    {
        if(flag){
            ans[m[i].second-1]=index;
        }
        else{
            if(m[i].first.second>m[0].first.second && m[i].first.first>m[0].first.first){
                index=m[i].second;
                flag=true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
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