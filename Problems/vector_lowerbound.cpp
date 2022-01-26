#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v={1,3,5,7,9};
    int n;
    cin>>n;
    cout<<lower_bound(v.begin(),v.end(),n)-v.begin();
    return 0;
}