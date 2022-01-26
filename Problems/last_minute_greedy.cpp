#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int arr[200009]={0};
        int n,ele,ans=0;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>ele;
            if(arr[ele]==0) arr[ele]+=1;
            else if(arr[ele]>0 && arr[ele+1]==0) arr[ele+1]+=1;
            else ans++;  
        }
        cout<<n-ans<<endl;
    }
    return 0;
}