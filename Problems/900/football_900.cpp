#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]) count++ ;     
        else{
            if(count>=6) {cout<<"YES";
            exit(0);}
            else count=0;}
    }
    if(count>=6) cout<<"YES";
    else cout<<"NO";
    return 0;
}