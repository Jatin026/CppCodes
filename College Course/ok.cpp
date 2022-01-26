#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ,s1=0,s2=0,s3=0;
    cin>>n;
    int arr[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        s1+=arr[i][0];
        s2+=arr[i][1];
        s3+=arr[i][2];
    }
    if(s1==0 && s2==0 && s3==0) cout<<"YES";
    else cout<<"NO";
    
    return 0;
}