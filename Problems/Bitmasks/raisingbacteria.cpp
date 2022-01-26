#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0;
    cin>>n;
    string s=bitset<32> (n).to_string();
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='1') ans++;
    }
    cout<<ans;
    return 0;
}