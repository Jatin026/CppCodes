#include<iostream>
#include<bitset>
using namespace std;

int main(){
    int n;
    cin>>n;
    string l=bitset <8> (n).to_string();
    string s="";
    string k="";
    while(n>0){
        if(n%2==0){
            s=s+"0";
            k="0"+k;
        }
        else{
            s=s+"1";
            k="1"+k;
        }
        n=n/2;
    }
    cout<<s<<endl;
    cout<<k<<endl;   
    cout<<l;
    return 0;
}