#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        if(s=="10" || s=="01"|| s=="1" || s=="0") cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}