#include<bits/stdc++.h>
using namespace std;
void hello(){
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,sum=0;
        bool flag=false;
        cin>>n>>x;
        int v[n];
        for(int i=0 ; i< n ; i++){
          cin>>v[i];  
        }
        sort(v,v+n);
        for (int i = n-1; i >-1; --i)
        {
            sum+=v[i];
            if(sum>=x){
                flag=true;
                sum=n-i;
                break;     
            }
        }
        if(flag){
            cout<<sum<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}