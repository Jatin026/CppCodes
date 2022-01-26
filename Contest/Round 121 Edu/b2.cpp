#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int doub=0;
    for(int i=0;i<s.length()-1;i++){
        if((s[i]-'0'+s[i+1]-'0')>=10){
            doub++;
        }
        
    }
    if(doub>=1){
       for(int i=s.length()-1;i>0;i--){
        if((s[i]-'0'+s[i-1]-'0')>=10){
            cout<<s.substr(0,i-1);
            cout<<s[i]-'0'+s[i-1]-'0';
            cout<<s.substr(i+1)<<endl;
            return;
        }
       }
    }
    else{
        cout<<(s[0]-'0'+s[1]-'0');
        cout<<s.substr(2)<<endl;
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}