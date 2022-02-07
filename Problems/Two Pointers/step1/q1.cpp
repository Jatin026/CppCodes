#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define sortv(arr) sort(arr.begin(),arr.end())

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v1(n),v2(k);
    for (int i = 0; i < n; i++)
    {
        cin>>v1[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin>>v2[i];
    }
    // v1.resize(n+k);
    // v1.insert(v1.end(),v2.begin(),v2.end());
    // sortv(v1);
    // for (int i = 0; i < n+k; i++)
    // {
    //     cout<<v1[i]<<" ";
    // }
    
    int i = 0,j=0;
    while(i<n || j<k){
        if( i < n && v1[i]<v2[j] || j==k){
            cout<<v1[i]<<" ";
            i++;
        }
        else {
            cout<<v2[j]<<" ";
            j++;
        }
    }
    // for (int l = i; l  < n; l++)
    // {
    //     cout<<v1[l]<<" ";
    // }
    // for (int l = j; l < k; l++)
    // {
    //     cout<<v2[l]<<" ";
    // }
    
}
int main(){
    FAST
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}