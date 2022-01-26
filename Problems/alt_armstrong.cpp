#include<iostream>
#include<cmath>
using namespace std;

int main(){
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<s.size();i++){
        sum+=pow(int(s[i])-48,s.size());
    }
    if(sum==stoi(s)){
        cout<<"Armstrong";
    }
    else{
        cout<<"NO";
    }
    return 0;
}