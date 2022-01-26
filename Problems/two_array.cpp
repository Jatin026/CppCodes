#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t,size,chance,ele;
    cin>>t;
    int arr[t];
    for (int i = 0; i < t; ++i)
    {
        int sum=0;
        cin>>size>>chance;
        vector<int> a,b;
        for (int j = 0; j < size; ++j)
    {
        cin>>ele;
        a.push_back(ele);
    }
        for (int j = 0; j < size; ++j)
    {
        cin>>ele;
        b.push_back(ele);
    }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int k=0;
        while(chance--){
            if(a[k]<b[size-1-k]){
            a[k]=b[size-1-k];
            k++;
            }
        }
        for (int j = 0; j < size; ++j)
    {
        sum+=a[j];
    }
        arr[i]=sum;
    }

    for (int i = 0; i < t; ++i)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
