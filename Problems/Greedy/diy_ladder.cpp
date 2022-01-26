#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n; 
       int arr[n];
       for (int i = 0; i < n; i++)
       {
           cin>>arr[i];
           
       }
       sort(arr,arr+n);
       if(arr[n-1]>n-2 && arr[n-2]>n-2) cout<<n-2<<endl;
       else cout<<0<<endl;
        
    }
    return 0;
}