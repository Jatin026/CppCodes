#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    k=240-k;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=5*(i)*(i+1)/2;
    }
    int l=0,r=n-1,m;
    if(arr[n-1]<=k){
        cout<<n;
    }
    else{
    while(l<r){
        m=(l+r)/2;
        if(arr[m]==k ){
            cout<<m+1;
            break;
        }
        else if (arr[m]>k && arr[m+1]<k){
            cout<<m;
            break;
        }
        else if (arr[m]<k){
            l=m+1;
        }
        else{
            r=m-1;
        }

        
    }
    }
    return 0;
}
//Giving wrong output , needs to be checked.
