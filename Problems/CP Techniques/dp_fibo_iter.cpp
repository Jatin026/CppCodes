#include<iostream>
using namespace std;

int main(){
    int N=2e5+6,n;
    int arr[N]={0};
    cin>>n;
    arr[1]=1,arr[2]=1;
    for (int i = 3; i < n+1; i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<arr[n];
    return 0;
}