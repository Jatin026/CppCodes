#include<bits/stdc++.h>
using namespace std;
int value[6],weight[6];
int knap(int n,int W){
    if(W==0 || n==0) return 0;
    if(weight[n]>W){
        return knap(n-1,W);
    }
    else{
        return max(knap(n-1,W-weight[n])+value[n],knap(n-1,W));
    }
}
int main(){
    int W;
    cin>>W;
    for (int i = 1; i <= 5; i++)
    {
        cin>>value[i]>>weight[i];
    }
    cout<<knap(5,W);
    return 0;
}