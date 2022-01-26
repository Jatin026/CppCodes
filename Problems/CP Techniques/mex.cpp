#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int arr[N];
int main(){
    int n,max_ele=0;
    cin>>n;
    int q[n];
    for (int i = 0; i < n; i++)
    {
        cin>>q[i];
        if(q[i]>=0) arr[q[i]]=1;
        max_ele=max(q[i],max_ele);
    }
    for (int i = 1; i <=max_ele; i++)
    {
        if(arr[i]==0){
            cout<<i;
            exit(0);
        } 
    }
    cout<<max_ele+1;
    return 0;
}