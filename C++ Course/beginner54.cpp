#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ifstream in;
    string st;
    in.open("io.txt");
    // getline(in,st);
    // cout<<st; only single line will be shown.
    while(in.eof()==0){
        getline(in,st);
        cout<<st<<endl;
    }
    in.close();
    return 0;
}