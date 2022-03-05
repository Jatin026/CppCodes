#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int N=2e5+7;
int dp[N];
int lis(int arr[], int n){
    int ans=1;
    if(dp[n]!=-1) return dp[n];
    if(n==1) return 1;
    for (int i = 0; i < n; i++)
    {
        if(arr[n-1]-arr[i]==1){
            // cout<<n<<"   "<<arr[n-1] <<"   " << i <<"   ";
            ans=max(ans,lis(arr,i+1)+1);
        }
    }
    return dp[n]=ans;
}
int main(){
    FAST
    memset(dp,-1,sizeof(dp));
    int n,ans=INT_MIN,index;
    cin>>n;
    int arr[n];
    for(int i=0 ; i< n ; i++){
        cin>>arr[i];
    }
    int value=lis(arr,n);
    for(int i= 0; i < n; i++){
        if(lis(arr,i+1)>ans){
            index=i;
        }
        ans=max(ans,lis(arr,i+1));
    }
    cout<<ans<<'\n';
    int l=1;
    for (int i = 0; i <= index; i++)
    {
        if(arr[i]+ans-l==arr[index]){
            cout<<i+1<<" ";
            l++;
        }
    }
    
    return 0;
}