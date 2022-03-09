#include<iostream>
using namespace std;
int fun_str(string s){
    int count=0;
    for (int i = 0; i < s.size(); ++i)
    {
        if(s[i]!=' ') count++;
    }
    return count;
}
int main(){
    string s;
    getline(cin,s);
    cout<<fun_str(s);
    return 0;
}