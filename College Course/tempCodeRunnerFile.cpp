#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin>>n;
    bool flag=true;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        int ans=0;
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[i][j];
            ans+=arr[i][j];
        }
        if(ans!=0) flag=false;
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
    
    return 0;
}