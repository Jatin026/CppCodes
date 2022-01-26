#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int size_s,k;
        string s;
        cin>>size_s;
        cin>>s;
        cout<<stoll(s,0,2)<<endl;
    }
    return 0;
}