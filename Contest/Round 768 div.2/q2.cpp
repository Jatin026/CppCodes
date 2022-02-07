#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,countle=0,ans=0;
        cin>>n;
        int  a[n];
        for (int i = 0; i <n; i++)
        {
            cin>>a[i];
        }

        for (int i = n-1; i >-1; --i)
        {
            if(a[i]==a[n-1]) {
               countle++;
            } 
            else {
                countle*=2;
                i=n-countle;
                ans++;
            }
        }
        cout<<ans<<endl;
          
}
    return 0;
}