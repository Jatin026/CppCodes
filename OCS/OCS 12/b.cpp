#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    int ans=0;
    map<char,int> m;
    for (int i = 0; i < s.size() ; i++)
    {
        m[s[i]]++;
    }
    for (char me = 'a'; me<='z'; me++)
    {
        if(m[me]%2==1) ans++;
    }
    
    if( ans%2==1 || (ans==0&& s.size()%2==0)) cout<<"First";
    else cout<<"Second";
    return 0;
}