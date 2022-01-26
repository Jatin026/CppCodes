#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
    int a,b,c;
    cin>>a>>b>>c;
    if((a+c)%2==1){
        if((a==b && b>c) || (b==c && a>b)) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    else{
        int k=(a+c)/2;
        if(k%b==0 || b%k==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    }
    return 0;
}