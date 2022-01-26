#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int arr[N][3];
int dp[N];
int vacation(int n){
    if(n==1) return arr[1][2];
    else if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    else if(max(arr[n][2],max(arr[n][0],arr[n][1]))==max(arr[n-1][2],max(arr[n-1][0],arr[n-1][1]))){
        dp[n]=vacation(n-1)+arr[n][0]+arr[n][1]+arr[n][2]-max(arr[n][2],max(arr[n][0],arr[n][1]))-min(arr[n][2],min(arr[n][0],arr[n][1]));
    }
    else{
        dp[n]=vacation(n-1)+max(arr[n][2],max(arr[n][0],arr[n][1]));
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];

    }
    cout<<vacation(n);
    return 0;
}