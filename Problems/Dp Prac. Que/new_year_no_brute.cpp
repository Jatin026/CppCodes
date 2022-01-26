#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       bool flag=false;
       cin>>n;
       for (int i = 0; i <=n/2021 ; i++)
       {
           for (int j = 0; j <= n/2020 ; j++)
           {
               if(i*2021+j*2020==n){
                   flag=true;
                   break;
               }
           }
           if(flag) break;
       }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}