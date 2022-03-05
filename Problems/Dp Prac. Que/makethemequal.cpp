#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
using namespace std;
const int N=1e3+1;
ll BinExpItr(int a , int b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}
int knapSack(int W, int wt[], int val[], int n)
{
    // making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {
 
            if (wt[i - 1] <= w)
                // finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}
int main(){
    FAST
    vector<int> dp(N,N);
    dp[1]=0;
    for (int i = 1; i < N; i++)
    {
        for (int x = 1; x <= i ; x++)
        {
            int j=i+i/x;
            if(j<N) dp[j]=min(dp[i]+1,dp[j]);
        }
        
    }
    int t;
    cin>>t;
    while(t--){
        int n,k,ans=0;
        cin>>n>>k;
        int arr[n],cst[n];
        for (int i = 0; i < n ; i++)
        {
            int ele;
            cin>>ele;
            arr[i]=dp[ele];
        }
        for (int i = 0; i < n ; i++)
        {
            cin>>cst[i];
        }
        cout<<knapSack(k,arr,cst,n)<<"\n";
    }
    return 0;
}