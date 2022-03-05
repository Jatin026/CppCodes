#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n+1]={0},ans=INT_MIN;
    for(int i = 1 ; i <= n ; i++ ){
        int ele;
        cin>>ele;
        if(i==1) arr[i]=ele;
        else arr[i]=arr[i-1]+ele;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j =i; j <= n; j++)
        {
            ans=max(ans,(j-i+1)-(arr[j]-arr[i-1])+arr[i-1]+arr[n]-arr[j]);
        }   
    }
    cout<<ans;
    return 0;
}
 