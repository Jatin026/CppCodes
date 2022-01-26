#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string st="Learning IO";
    ofstream out("io1.txt");
    out<<st;
    out.close();
    string st2;
    ifstream in("io.txt");
    // in>>st2;
    getline(in,st2);
    cout<<st2;
    in.close();
    return 0;
}