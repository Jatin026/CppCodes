#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define end "\n"
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
using namespace std;

void solve(){
    int n,k,sum=0;
    cin>>n>>k;
    pair<int,int> p[n];
    for (int i = 0; i < n; i++)
    {
        cin>>p[i].second>>p[i].first;
        if(p[i].second==1) sum+=p[i].first;
    }
    sortarr(p);
    for (int i = n-1; i >-1; --i)
    {
        if(k==0){
            cout<<sum<<end;
            return ;
        }
        else{
            sum+=p[i].first;
            k--;
        }
    }
    cout<<sum<<end;
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