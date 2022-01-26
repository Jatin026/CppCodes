#include<bits/stdc++.h>
using namespace std;

int main(){
    set <char> s;
    string str;
    cin>>str;
    for(int i=0 ; i< str.size() ; i++){
        s.insert(str[i]);
    }
    if(s.size()%2==0)cout<<"CHAT WITH HER!"<<endl;
    else {
        cout<<"IGNORE HIM!"<<endl;   
    }
    return 0;
}