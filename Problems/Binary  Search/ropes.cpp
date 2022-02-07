#include<bits/stdc++.h>
using namespace std;
bool f(int arr[] , long double x, int n,long double k){
    long long int sum=0;
    for (int i = 0; i <n; i++)
    {
        sum+=floor(arr[i]/x) ;
   }
   return (sum>=k) ;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    long double l=0,r=1e8;
    for (int i = 0; i < 100; i++)
    {
        long double mid=1.0*(l+r)/2;
        if(f(arr,mid,n,k)){
            l=mid ;
        }
        else{
            r=mid ;
        }
    }
    cout<<setprecision(20)<<l;
    return 0;
}