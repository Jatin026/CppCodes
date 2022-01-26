#include<iostream>
using namespace std;
const int N=1e7 +7;//No. taken as the maximum size of array(The maximum no. which can be given as an input).
int arr[N]={0};
//code to find how many times a number occur in a given array.
int main(){
    int n,ele;//The size of array
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>ele;
        arr[ele]++;
    }
    int t;//No. of test cases
    cin>>t;
    while (t--)
    {
        cin>>ele;
        cout<<arr[ele]<<" ";
    }
    
    return 0;
}