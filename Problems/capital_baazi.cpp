#include<iostream>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]!=' '){
            s[i]=toupper(s[i]);
            cout<<s[i];
        }
        else{
            cout<<endl;
        }
    }
    return 0;
}