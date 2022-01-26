#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[]={420,3,324,69,240,1};
    cout<<sizeof(arr[0])<<endl;
    cout<<sizeof(arr)<<endl;
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}