#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    k=k%s.size();
    rotate(s.begin(),s.begin()+s.size()-k,s.end());
    cout<<s;
    return 0;
}