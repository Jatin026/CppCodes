#include<bits/stdc++.h>
using namespace std;

bool func(int arr[],int n, int i , int sum,int cnt=1){
    if(sum==0) return 1;
    else if(n==i || sum<0) return 0;
    return (func(arr,n,i+1,sum-cnt*arr[i],cnt+1) | func(arr,n,i+1,sum) ) ;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<func(arr,n,0,k);
    return 0;
}