#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int dp[N],sum[N];
int inc(int n,int arr[],int k){
    int ans=0;
    if(n-k<0) return INT_MAX;
    if(dp[n]!=-1) return dp[n];
    ans=sum[n]-sum[n-k];
    return dp[n]=min(ans,inc(n-1,arr,k));
}
int main(){
    int n,k;
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
        sum[i+1]=sum[i]+arr[i];
    }
    int ans=inc(n,arr,k);  
    for (int i = 1; i <= n; i++)
    {
        if(dp[i]==ans){
            cout<<i-k+1<<endl;
            break;
        }
    }
    return 0;
}
