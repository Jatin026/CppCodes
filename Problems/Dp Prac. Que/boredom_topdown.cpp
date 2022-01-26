#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
int cnt[N];
long long int dp[N];
long long int bore(long long int n){
    if(dp[n]!=-1) return dp[n];
    return dp[n]=max(bore(n-1),bore(n-2)+n*cnt[n]);
}
int main(){
    int n,max_ele=INT_MIN;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        max_ele=max(ele,max_ele);
        cnt[ele]++;
    }
    cout<<bore(max_ele);
    return 0;
}




