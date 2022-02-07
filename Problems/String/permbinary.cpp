#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s="",k;
    for (int i = 0; i < n; i++)
    {
        s+='0';
    }
    for (int i = 0; i < n; i++)
    {
        s+='1';
    }
    k=s;
    reverse(k.begin(),k.end());
    for (int i = stoll(s,0,2); i <= stoll(k,0,2); i++)
    {
        if(__builtin_popcount(i)==n){
            cout<<bitset<6> (i).to_string()<<"\n";
        }
    }

    return 0;
}