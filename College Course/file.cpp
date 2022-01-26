#include<iostream>
#include<fstream>
using namespace std; 
int main(){
    ofstream out("output.txt");
    ifstream in("input.txt");
    string s;
    getline(in,s);
    for (int i = 0; i < s.size(); i++)
    {
        if(isupper(s[i])==1){
            s[i]=tolower(s[i]);
        }
        else{
            s[i]=toupper(s[i]);
        }
    }
    out<<s;
    return 0;
}
