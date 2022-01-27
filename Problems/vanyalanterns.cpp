#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,l;
    cin>>n>>l;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int diff,maxd=2*arr[0];
    for (int i = 0; i < n-1; i++)
    {
        diff=(arr[i+1]-arr[i]);
        maxd=max(diff,maxd);
    }
    maxd=max(maxd,2*(l-arr[n-1])); 
    printf("%.10f",maxd/2.0);
    return 0;
}