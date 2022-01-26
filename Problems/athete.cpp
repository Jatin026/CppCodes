#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    int t,n,ele;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v;
        bool flag=true;
        for(int i=0;i<n;++i){
            cin>>ele;
            v.push_back(ele);
        }
        sort(v.begin(),v.end());
        int diff=v[1]-v[0];
        for(int i=0;i<n-1;++i){
            if((-v[i]+v[i+1])<diff){
                diff=v[i+1]-v[i];
            }
        }
        cout<<diff<<endl;
    }
    return 0;
}