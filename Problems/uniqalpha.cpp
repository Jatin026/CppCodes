#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int arr[27];
    for(int i=1;i<s.size()-1;i++){
        if(s[i]!=','&& s[i]!=' '){
            arr[int(s[i])-96]=1;
        }
    }
    int cnt=0;
    for(int i=0;i<27;i++){
        if(arr[i]==1){
            cnt++;
    }
    }
    cout<<cnt;
    return 0;
}