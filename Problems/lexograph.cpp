#include<iostream>
#include<string>
using namespace std;

int main(){
    string s,l;
    cin>>s>>l;
    for (int i = 0; i < s.size(); i++)
    {
        s[i]=tolower(s[i]);
        l[i]=tolower(l[i]);
    }
    for (int i = 0; i < s.size(); i++)
    {
        if(int(s[i])!=int(l[i])){
            if(int(s[i])>int(l[i])){
            cout<<1;
            exit(0);}
            else{
                cout<<-1;
                exit(0);
            }
        }
    }
    cout<<0;
    return 0;
}