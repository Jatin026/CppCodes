#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    vector<char>v;
    string S;
    cin>>S;
    for(int i=0;i<S.size();i++){
        if(S[i]!='+')
            v.push_back(int(S[i]));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(i==v.size()-1){
            cout<<v[i];
        }
        else{cout<<v[i]<<"+";}
    }
    return 0;
}