#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n+1],ans[n-k+1];
    arr[0]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    int index, min_ans=INT_MAX;
    for(int i=k;i<=n;i++){
        ans[i-k]=arr[i]-arr[i-k];
    }
    for(int i=0;i<=n-k;i++){
        if(ans[i]<min_ans){
            index=i+1;
            min_ans=ans[i];
        }
    }
    cout<<index;
    return 0;
}