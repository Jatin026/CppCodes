#include<iostream>
using namespace std;
const int N=1e7+6;
long long int arr[N];
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b,val;
        cin>>a>>b>>val;
        arr[a]+=val;
        arr[b+1]-=val;
    }
    long long int maxe=arr[1];
    for (int i = 1; i <n+1 ; i++)
    {
        arr[i]+=arr[i-1];
        maxe=max(maxe,arr[i]);
    }
    cout<<maxe;
    return 0;
}