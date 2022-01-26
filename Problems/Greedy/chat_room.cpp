#include<bits/stdc++.h>
using namespace std;

int main(){
    int alpha[27];
    bool flag=false;
    memset(alpha,0,sizeof(alpha));
    string s;
    cin>>s;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='h') alpha[s[i]-96]++;
        else if(s[i]=='e' && alpha['h'-96]>0 ) alpha[s[i]-96]++;
        else if(alpha['e'-96]>0 && s[i]=='l') alpha[s[i]-96]++;
        else if(alpha['l'-96]>1 && s[i]=='o'){
            alpha[s[i]-96]++;
            flag=true;
        }
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
    return 0;
}