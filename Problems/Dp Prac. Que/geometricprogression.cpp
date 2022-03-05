#include<bits/stdc++.h>
using namespace std;
int count(int arr[], int x, int n, int s)
{   
  /* get the index of first occurrence of x */
  int *low = lower_bound(arr+n, arr+s, x);
 
  // If element is not present, return 0
  if (low == (arr + s) || *low != x)
     return 0;
    
  /* Else get the index of last occurrence of x.
     Note that we  are only looking in the
     subarray after first occurrence */  
  int *high = upper_bound(low, arr+s, x);    
    
  /* return count */
  return high - low;
}
int main(){
    int n,k,ans=0;
    cin>>n>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i]%k==0){
            cout<<count(arr,arr[i]/k,0,i)*count(arr,arr[i]*k,i+1,n)<<'\n';
            ans+=count(arr,arr[i]/k,0,i)*count(arr,arr[i]*k,i+1,n);
        }
    }
    cout<<ans;
    return 0;
}