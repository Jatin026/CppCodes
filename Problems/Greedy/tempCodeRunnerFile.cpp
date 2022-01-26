#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans[1001];
    memset(ans,-1,sizeof(ans));
    for (int i = 1; i < 1001; i++)
    {
        string k=to_string(i);
        for (int j = 0; j <k.size() ; j++)
        {
            if(k[j]!='4' && k[j]!='7'){
                ans[i]=0;
                break;
            }
        }
        if(ans[i]==-1) ans[i]=1;   
    }
    if(ans[n]==1) cout<<"YES";
    else{
        for (int i = 1; i <n; i++)
        {
            if(ans[i]==1){
                if(n%ans[i]==0){
                    cout<<"YES";
                    return 0;
                }
            }
        }
        cout<<"NO";
    } 
    return 0;
}