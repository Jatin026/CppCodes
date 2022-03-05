#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream out("results.out");
    ifstream in("infile.dat");
    int n,d,cnt=1;
    in>>n>>d;
    while(n>0){
        if(n%10==d){
            out<<cnt;
            return 0;
        }
        n=n/10;
        cnt++;
    }
    out<<"NOT PRESENT";
    return 0;
}