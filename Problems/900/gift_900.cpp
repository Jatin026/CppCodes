#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,m,ele,diff,min_diff;
    cin>>n>>m;
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        cin>>ele;
        v.push_back(ele);
    }
    sort(v.begin(),v.end());
    min_diff=v[n-1]-v[0];
    for(int i=1;n-1+i<m;i++){
        diff=v[n-1+i]-v[i];
        min_diff=min(min_diff,diff);
    }
    cout<<min_diff;
    return 0;
}