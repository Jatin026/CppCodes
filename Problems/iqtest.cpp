#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ans;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        arr[i]%=2;
    }
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]!=arr[i+1]){
            if(i==0 && arr[i]!=arr[i+2]){
                cout<<1;
                exit(0);
            }
            else{
            cout<<i+2;
            exit(0);}
        }
    }
    return 0;
}