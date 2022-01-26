#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> v={1,1,5,5,7,7};
    // replace(v.begin(),v.end(),8,16);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    cout<<endl;
    vector<int>::iterator itr=adjacent_find(v.begin(),v.end());
    cout<<*itr<<endl;
    *(itr+1)=(*itr)+1;
    itr=v.erase(itr);
    cout<<*itr<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    itr=adjacent_find(v.begin(),v.end());
    return 0;
}