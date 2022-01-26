#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    int n,m,sum=0,ele;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        v.push_back(ele);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < m; i++)
    {
        if(v[i]<0 )sum+=abs(v[i]);
    }
    cout<<sum;
    return 0;
}