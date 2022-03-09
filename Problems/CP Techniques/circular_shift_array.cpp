#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int max_e=0,temp1=n,max_i=0;
    for(int i=0 ; i< n ; i++){
        if(max_e<=arr[i]) max_i=i;
        max_e=max(arr[i],max_e);
    }
    int x=n-1-max_i,sum=0;
    for (int i = 0; i < n; i++)
    {
        int l=(i+x)%n;
        cout<<l<<" "<<l*arr[i]<<endl;
        sum+=l*arr[i];
    }
     
    return 0;
}