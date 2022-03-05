#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FAST
    map<int,int> dp;
    int n,ans=INT_MIN,index;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        dp[arr[i]]= (dp[arr[i]-1]+1);
        if(dp[arr[i]]>ans){
            index=i;
        }
        ans=max(ans,dp[arr[i]]);
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