#include<iostream>
using namespace std;
string banao_binary(int n){
    string s="";
    int rem;
    while(n>0){
        rem=n%2;
        s=to_string(rem)+s;
        n=n/2;
    }
    return s;
}
int main(){
    float t;
    cin>>t;
    string str=banao_binary(t);
    if(str[0]=='1'){
    for(int i=1;i<str.size();i++){
        if(str[i]=='1'){
            cout<<"Jao apna kaam karo";
            exit(0);
        }
    }
    }
    cout<<"BOLO JAI MATA DI";  
    return 0;
}