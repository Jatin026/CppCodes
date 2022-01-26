#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a,b,cost,minc=INT_MAX;
    cin>>n>>m>>a>>b;
    for (int i = 0; i <=n ; i++)
    {
        for (int j = 0; j <= n/m+1; j++)
        {
            if(i+j*m>=n){
                cost=i*a+b*j;
                minc=min(cost,minc);
            }
        }
        
    }
    cout<<minc;
    return 0;
}