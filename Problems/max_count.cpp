#include<iostream>
using namespace std;

int main(){
    int count=1,t,max_count=1;
    cin>>t;
    int arr[t];
    for (int i = 0; i < t; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < t-1; i++)
    {
        if(arr[i]==arr[i+1]) count++;
        else if(arr[i]<arr[i+1]  ){
            count++;
        }
        else{
            max_count=max(max_count,count);
            count=1;
        }
    }
    max_count=max(max_count,count);
    cout<<max_count;
    return 0;
}