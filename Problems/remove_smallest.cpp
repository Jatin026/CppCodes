#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t,n,ele;
    cin>>t;
    string arr[t];
    for (int i = 0; i < t; i++)
    {
        vector<int> v;
        cin>>n;
        for (int j = 0; j < n; j++)
        {
            cin>>ele;
            v.push_back(ele);
        }
        if(n==1){
            arr[i]="YES";
            continue;
        }
        sort(v.begin(),v.end());
        for (int j = n-1; j >0; j--)
        {
            if((v[j]-v[j-1])<=1){
                v[j]=v[j-1];
                v.pop_back();
            }
        }
        if(v.size()==1) arr[i]="YES";
        else arr[i]="NO";
    }
    for (int j = 0; j< t; j++)
    {
           cout<<arr[j]<<endl;  
    }
    return 0;
}