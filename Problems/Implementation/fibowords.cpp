#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int arr[s.size()+1]={0},co=0,ce=0;
    for (int i = 3; i <= s.size(); i++)
    {
        arr[i]+=(s[i-1]+s[i-2]-128)%26;
    }
    string k="";
    for (int i = 1; i <= s.size(); i++)
    {
        k+=char(arr[i]+65);
    }
    cout<<k<<"    ";
    if(k==s) cout<<"YES";
    else cout<<"NO";
    return 0;
}