#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c ;
    cin>>a>>b>>c;
    int ans=a/3 + b/3 + c/3;
    for (int i = 1; i < min(3,min(min(a,b),c)); i++)
    {
        ans=max(ans,(a-i)/3  + (b-i)/3 + (c-i)/3 + i);
    }
    cout<<ans;
    return 0;
}