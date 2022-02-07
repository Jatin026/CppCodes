#include<bits/stdc++.h>
using namespace std;
int check(int a, int b, int k){
    int count=0;
    for (int i = 0; i < 32; i++)
    {
        if(((a>>i)&1)!=((b>>i)&1)){
            count++;
        }
    }
    return (count<=k);
}
int main(){
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    int arr[m+1];
    for(int i=0;i < m+1; i++){
        cin>>arr[i];
    }
    for(int i=0;i < m; i++){
        ans+=check(arr[m],arr[i],k);
    }
    cout<<ans;
    return 0;
}