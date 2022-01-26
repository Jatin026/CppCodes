#include<bits/stdc++.h>
using namespace std;
void input(int arr[],int n){
   for(int i=0; i<n ; i++){
        cin>>arr[i];
    } 
}
void selsort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int min_index=i;
        for (int j = i+1; j<n; j++)
        {
            if(arr[min_index]>arr[j]) min_index=j;
            else swap(arr[min_index],arr[i]);
        }   
    }   
}
void output(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    input(arr,n);
    selsort(arr,n);
    output(arr,n);
    return 0;
}