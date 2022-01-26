#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, ans=0,count[5]={0};
    cin>>n;
    int arr[n];
    for(int i=0 ; i< n ; ++i){
        cin>>arr[i];
        count[arr[i]]++;
}  
    ans+=count[4];
    while (count[1]>0 && count[3]>0)
    {
        ans++;
        count[1]--;
        count[3]--;
    }
    ans+=count[3];
    ans+=count[2]/2;
    count[2]%=2;
    ans+=ceil(count[2]*0.5+0.25*count[1]);
    cout<<ans;
    return 0;
}