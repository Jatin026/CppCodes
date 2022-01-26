#include<iostream>
using namespace std;
int binary_search(int arr[5],int ele){
    int l=0,h=4;
    bool ans=false;
    while(l<=h){
        int m=(l+h)/2;
        if(ele==arr[m]){
            return m+1;
        }
        else if(ele >arr[m] && ele<arr[m+1] ){
            return(m+1);
        }
        else if(ele>arr[m]){
            l=m+1;
            
        }
        else{
            h=m-1; 
        }
    }
    return 0;
}
int main(){
    int arr[5]={1,2,43,62,75};
    int n;
    cin>>n;
    cout<<binary_search(arr,n);
    return 0;
}