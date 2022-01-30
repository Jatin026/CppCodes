#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int binary(int n,int arr[],int size){
    int l=0,r=size-1,mid,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(arr[mid]>n){
            r=mid-1;
        }
        else{
            l=mid+1;
            ans=l;
        }
    }
    return ans;
}
int main(){
    FAST
    int n,q;
    cin>>n>>q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    while (q--)
    {
        int l;
        cin>>l;
        cout<<binary(l,arr,n)<<"\n";
    }
    
    return 0;
}