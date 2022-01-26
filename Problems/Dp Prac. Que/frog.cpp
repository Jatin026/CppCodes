#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int dp[N],cost[N];
int k;
int frog(int n){
    if(dp[n]!=-1) return dp[n];
    int cp=INT_MAX;
    for(int j=1 ; j < k+1 ; j++){
        if(n-j>0)
        cp=min(cp,abs(cost[n-j]-cost[n])+frog(n-j));
    } 
    return dp[n]=cp;
}
int main(){
    int n;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for (int i = 1; i < n+1; i++)
    {
        cin>>cost[i];
    }
    dp[1]=0;
    dp[2]=(abs(cost[1]-cost[2]));
    cout<<frog(n);
    return 0;
}