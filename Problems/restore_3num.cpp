#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    int a;
    for (int i = 0; i < 4; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<3;i++){
        cout<<v[3]-v[i]<<" ";
    }
    
    return 0;
}