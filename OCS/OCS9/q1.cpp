#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
char arr[N];
int main(){
    int t,max_size=0;
    cin>>t;
    while (t--)
    {
    string s;
    cin>>s;
    max_size=max(int(s.size()),max_size);
    for (int i = 0; i <s.size(); i++)
    {
        if(int(arr[i])>96){
            if(s[i]!=arr[i]){
                if(s[i]!='?') arr[i]='~';
            }
        }
        else arr[i]=s[i];
    }
    }
    for (int i = 0; i < max_size; i++)
    {
        if(arr[i]=='?') arr[i]=('a');
        else if(arr[i]=='~') arr[i]=('?');
         
    }
    cout<<arr;
    return 0;
}