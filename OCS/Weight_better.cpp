#include<iostream>
using namespace std;
int arr[1000420]={0};
int main(){
    ios::sync_with_stdio(false);
    int t,ele;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        cin>>ele;
        arr[ele]++;
    }
    int ans=0;
    for (int i = 0; i < 1000419; i++)
    {
        arr[i+1]+=arr[i]/2;
        arr[i]%=2;
        ans+=arr[i];
    }
    cout<<ans;
    return 0;
}