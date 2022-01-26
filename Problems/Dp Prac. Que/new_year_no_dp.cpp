#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int dp[N];
void dp_func(){
   for (int i = 0; i <=N/2020 ; i++)
    {
        for (int j = 0; j <=N/2021 ; j++)
        {
            if(i*2020+j*2021>N) break;
            dp[i*2020+j*2021]=1;
        }
    } 
}
int main(){
    int t;
    cin>>t;
    dp_func();
    while (t--)
    {
        int n;
        cin>>n;
        if(dp[n]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}