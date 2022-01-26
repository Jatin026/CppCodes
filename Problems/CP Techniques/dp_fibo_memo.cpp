#include<iostream>
using namespace std;
const int N=2e5+7;
int dp[N];
int fibo_memo(int n){
    if(dp[n]!=0) return dp[n];
    if(n<=2){
        dp[n]= 1;
    }
    else{
        dp[n]=fibo_memo(n-1)+fibo_memo(n-2);
    }
    return dp[n];
}
int main(){
    int n; cin>>n;
    cout<<fibo_memo(n);
    return 0;
}