#include<iostream>
using namespace std;
void solve(){
    int size;
    string s;
    cin>>size>>s;
    if(size==1){
        if(s[0]=='?') cout<<'B'<<endl;
        else cout<<s<<endl;
    }
    else{
        for (int i = 0; i < size; i++)
        {
            if(s[0]=='?'){
                if(s[1]=='B') s[0]='R';
                else s[0]='B';
            }
            else if(s[i]=='?'){
                if(s[i-1]=='B') s[i]='R';
                else s[i]='B';
            }
        }
        cout<<s<<endl; 
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