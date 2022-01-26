#include<iostream>
using namespace std;
bool find(string s){
    char arr[]={'H','Q','9','+'};
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]==arr[0] || s[i]==arr[1]||s[i]==arr[2]){
            return 1;
        }
    }
    return 0;
}
int main(){
    string s;
    cin>>s;
    if(find(s)==1) cout<<"YES";
    else cout<<"NO";
    return 0;
}