#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int arr[N],dp[N];
int lis(int n){
    int ans=1;
    if(dp[n]!=-1) return dp[n];
    for (int i = 1; i <= n; i++)
    {
        if(arr[n]>arr[i]){
            ans=max(ans,lis(i)+1);
        }
    }
    return dp[n]=ans;
}
int main(){
    int n,ans=1;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ans=max(lis(i),ans);
    }
    
    cout<<ans;
    return 0;
}