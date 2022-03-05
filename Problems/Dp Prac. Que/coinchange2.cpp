#include<bits/stdc++.h>
using namespace std;
int coin(int arr[], int n , int x){
    if(x==0) return 0;
    int ans=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(x-arr[i]>=0)
            ans=min(coin(arr,n,x-arr[i])+1LL,ans+0LL);
    }
    return ans;
}
int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<< (coin(arr,n,x)==INT_MAX) ? -1 :coin(arr,n,x) ;
    return 0;
}