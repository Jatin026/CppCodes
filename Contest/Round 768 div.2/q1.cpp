#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int ans=INT_MAX,mul;
        for (int i = 0; i < n; i++)
        {
            if(a[i]<b[i]){
                swap(a[i],b[i]);
            }
        }
        sort(a,a+n); 
        sort(b,b+n);
        cout<<a[n-1]*b[n-1]<<endl; 
    }
    return 0;
}