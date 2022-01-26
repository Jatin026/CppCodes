#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream in("q1.txt");
    string s;
    in>>s;
    for (int i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<endl;
    }
    
    return 0;
}