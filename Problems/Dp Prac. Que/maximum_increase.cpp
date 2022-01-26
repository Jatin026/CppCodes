#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int arr[N],dp[N];
//Solution of Strict Increasing sub-array
int sequence(int n){
    int ans=1;
    if(dp[n]!=-1) return dp[n];
    else if(n<=1) return n;
    else if(arr[n]>arr[n-1]){
        ans=max(sequence(n-1)+1,ans);
    }
    return dp[n]=ans;
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1; i< n+1 ; i++ ){
        cin>>arr[i];
    }
    int ans=0;
    for (int i = 1; i <=n; i++)
    {
        ans=max(ans,sequence(i));
    }
    cout<<ans;
    return 0;
}