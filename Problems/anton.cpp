#include<iostream>
using namespace std;

int main(){
    int tn;
    cin>>tn;
    string s;
    cin>>s;
    int ant=0, dan=0;
    for(int i=0;i<tn;i++){
        if(s[i]=='A'){
            ant++;
        }
        else{
            dan++;
        }
    }
    if(ant==dan){
        cout<<"Friendship";
    }
    else if(dan>ant){
        cout<<"Danik";
    }
    else{
        cout<<"Anton";
    }
    return 0;
}