#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
bool binary(int n,int arr[],int size){
    int l=0,r=size-1,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(arr[mid]==n){
            return 1;
        }
        else if(arr[mid]>n){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return 0;
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
        if(binary(l,arr,n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}