#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,ele,sum=0;
    cin>>n;
    vector<int> v;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>ele;
        v.push_back(ele);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        sum+=v[i];
        arr[i]=sum;
        }
    sum=v[n-1];
    ele=1;
    for(int i=n-1;i>0;--i){
        if(sum>arr[i-1]){   
            break;
        }
        else{
            sum+=v[i-1];
            ele++;
        }
    }
    cout<<ele;
    return 0;
}