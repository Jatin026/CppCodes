#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a,b,t,sum;
    cin>>t;
    int arr[t];
    for (int i = 0; i < t; ++i)
    {
        cin>>a>>b;
        sum=abs(a-b);
        arr[i]=ceil(sum/10.0);
    }
    for (int i = 0; i < t; ++i)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}