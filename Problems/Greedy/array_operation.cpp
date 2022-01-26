#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        int temp=k;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int ans=0,count=n-1;
        while(temp--){
            ans+=arr[count-1]/arr[count];
            count-=2;
        }
        for (int i = 0; i < n-2*k; i++)
        {
            ans+=arr[i];
        }
        cout<<ans<<endl;        
    }
    return 0;
}








