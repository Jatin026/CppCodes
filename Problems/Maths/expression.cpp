#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,ans[4];
    cin>>a>>b>>c;
    ans[0]=a+b+c;
    ans[1]=a*b*c;
    ans[2]=(a+b)*c;
    ans[3]=a*(b+c);
    sort(ans,ans+4);
    cout<<ans[3];
    return 0;
}