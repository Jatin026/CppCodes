#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int ans=0;
        int n;
        cin>>n;
        char c[n];
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin>>c[i]>>a[i];
            ans+=a[i]*(a[i]+1)/2;  
        }
        cout<<ans<<endl;
    }
    return 0;
}