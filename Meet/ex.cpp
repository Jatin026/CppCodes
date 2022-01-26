#include<bits/stdc++.h>
using namespace std;

int main(){
    map <int,int> m;
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        m[arr[i]]=i;
    }
    sort(arr,arr+n);
    return 0;
}