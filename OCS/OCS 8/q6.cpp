#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    cin>>n>>d;
    string s;
    char arr[27];
    cin>>s;
    for (int i = 1; i < 27; i++)
    {
        arr[i]=96+i;
    }
    while(d--){
        char t,w;
        cin>>t>>w;
        for (int i = 1; i < 27; i++)
        {
            if(arr[i]==t) arr[i]=w;
            else if(arr[i]==w) arr[i]=t;
        }
        // replace(s.begin(),s.end(),w,'*');
        // replace(s.begin(),s.end(),t,w);
        // replace(s.begin(),s.end(),'*',t);
    }
    // cout<<s;
    for (int i = 0; i <n; i++)
    {
        cout<<arr[s[i]-96];
    }
    
    return 0;
}
//a->b  ,,  b<->a , a<->c
