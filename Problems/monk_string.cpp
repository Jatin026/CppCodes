#include<iostream>
using namespace std;
bool chk_prime(int n){
    for (int i = 2; i*i < n; i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
int main(){
    string s;
    int sum=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isupper(s[i])){
            s[i]=tolower(s[i]);
            sum+=-int(s[i]);
        }
        else{
            s[i]=toupper(s[i]);
            sum+=int(s[i]);
        }   
    }
    if(chk_prime(abs(sum))) cout<<1;
    else cout<<0;
    return 0;
}