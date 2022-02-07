#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        int n,x;
        bool flag=true;
        cin>>n;
        x=(log(n)/log(2))+1e-5;
        for (int i = 1; i < n; i++)
        {
            if((i==(1<<x)&& flag )){
                cout<<0<<" ";
                flag=false;
                i--;
            }
            else if(n==(1<<x) && i==n-1){
                cout<<n-1<<" "<<0<<" ";
            }
            else cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}