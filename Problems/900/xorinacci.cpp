#include<iostream>
using namespace std;
void solve(){
    int a,b,n;
    cin>>a>>b>>n;
    int dp[3];
    dp[0]=a;
    dp[1]=b;
    dp[2]=a^b;
    cout<<dp[n%3]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}