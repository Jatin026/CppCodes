#include<iostream>
using namespace std;
const int N=1e5+7;
const int M=1e9+7;
long long int dp[N];
int main(){
    string s;
    cin>>s;
    dp[1]=1;
    dp[0]=1;
    //To check m or w in string
    for (int i =0; i < s.size(); i++)
    {
        if (s[i] == 'w' || s[i] == 'm')
        {
            cout << 0;
            exit(0);
        }    
    }
    for (int i = 2; i <=s.size(); i++)
    {
        if(s.substr(i-2,2)=="nn" || s.substr(i-2,2)=="uu"){
            dp[i]=dp[i-1]+dp[i-2];
            dp[i]=dp[i]%M;
        }
        else{
            dp[i]=dp[i-1];
        }
    }
     
    cout<<dp[s.size()];
    return 0;
}