#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s[2];
    s[0]="I hate";
    s[1]="I love";
    for (int i = 0; i < n; i++)
    {
        cout<<s[i%2];
        if(i!=n-1) cout<<" that ";
        else cout<<" it";
    }
    map <pair<int,int>,int> m;
    pair<int,int> p;
    m[p]++;
    return 0;
}