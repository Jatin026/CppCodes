#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// const int N=1e6+7;
// int arr[N]={0};
int main(){
    // int t,ele,max_int=0,ans=0;
    // cin>>t;
    // while (t--)
    // {
    //     cin>>ele;
    //     max_int=max(max_int,ele);
    //     arr[ele]++;
    // }
    // for (int i = 0; i < N; i++)
    // {
    //     if(arr[i]==2) ans++;
    //     else if(arr[i]>2){ 
    //         cout<<-1;
    //         exit(0);
    //         }

    // }
    // cout<<ans;
    int t,ele,ans=0;
    vector<int> v;
    cin>>t;
    while (t--)
    {
        cin>>ele;
        v.push_back(ele);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < t; i++)
    {
        if(v[i]==v[i+1]){
            if(v[i]==v[i+2]){
                cout<<-1;
                exit(0);
            }
            else if(v[i]!=0) ans++;
        }
    }
    cout<<ans;
    return 0;
}