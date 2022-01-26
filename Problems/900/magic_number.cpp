#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]!='1' && s[i]!='4'){
            cout<<"NO";
            exit(0);
        }
        else if(s[i]=='1' && s[i+1]=='4' &&  s[i+2]=='4'){
            i+=2;
        }
        else if(s[i]=='1' && s[i+1]=='4'){
            i+=1;
        }
        else if(s[i]=='1'){}
        else {
            cout<<"NO";
            exit(0);
        } 
    }
    cout<<"YES";
    return 0;
}