#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int weight[101],value[101];
long long int dp[101][N];
long long int knap(int n, long long int W){
    if(dp[n][W]!=-1) return dp[n][W];
    if(n==0 || W==0) return 0;
    if(W<weight[n]) return dp[n][W]=knap(n-1,W);
    return dp[n][W]=max(knap(n-1,W),knap(n-1,W-weight[n])+value[n]);
}
int main(){
    int n,W;
    memset(dp,-1,sizeof(dp));
    cin>>n>>W;
    for (int i = 1; i <=n ; i++)
    {
        cin>>weight[i]>>value[i];
    }
    cout<<knap(n,W)<<endl;  
    return 0;
}