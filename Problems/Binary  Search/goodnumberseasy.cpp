#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;
const int N=1e4+7;
vector<int> v;
bool check(int x){
    while(x>0){
        if(x%3==2) return 0;
        x=x/3;
    }
    return 1;
}
void solve(){
    int n;
    cin>>n;
    int l=0,r=v.size()+1;
    int ans;
    if(n==1){
        cout<<1<<"\n";
        return;
    }
    while(l+1<r){
        int mid=(l+r)/2;
        if(v[mid]>=n){
            ans=mid;
            r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<v[ans]<<"\n";
}
int main(){
    FAST
    for (int i = 1; i < 3*N; i++)
    {
        if(check(i)) v.push_back(i);
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}