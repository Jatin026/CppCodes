#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
int cnt[N];
long long int dp[N];
long long int bore(int n){
    for (long long int i = 1; i <N; i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+i*cnt[i]);
    }  
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    dp[1]=cnt[1];
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        cnt[ele]++;
    }
    cout<<bore(100000);
    return 0;
}