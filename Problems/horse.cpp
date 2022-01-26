#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long ele;
    int count=0;
    vector<int> v;
    for (int i = 0; i < 4; i++)
    {
        cin>>ele;
        v.push_back(ele);
    }
    sort(v.begin(),v.end());
    for (int k=0; k<3;k++)
    {
        if(v[k]==v[k+1]){
            count+=1;
        }
    }
    cout<<count;
    return 0;
}