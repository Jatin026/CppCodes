#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m,a;
    cin>>n>>m>>a;
    long long int k =(ceil((n*1.0/a))*ceil((m*1.0/a)));
    cout<<k;
    return 0;
}