#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    rotate(s.begin()+1,s.begin()+3,s.begin()+s.size()-2);
    cout<<s;
    return 0;
}