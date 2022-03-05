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
int maxDistance(int arr[], int n)
{
    // max and min variables as described
    // in algorithm.
    int max1 = INT_MIN, min1 = INT_MAX;
    int max2 = INT_MIN, min2 = INT_MAX;
 
    for (int i = 0; i < n; i++) {
 
        // Updating max and min variables
        // as described in algorithm.
        max1 = max(max1, arr[i] + i);
        min1 = min(min1, arr[i] + i);
        max2 = max(max2, arr[i] - i);
        min2 = min(min2, arr[i] - i);
    }
 
    // Calculating maximum absolute difference.
    return max(max1 - min1, max2 - min2);
}
void solve(){
    int n,maxi=INT_MIN,mini=INT_MAX;
    cin>>n;
    int  arr[n];
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<maxDistance(arr,n)<<'\n';
   
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