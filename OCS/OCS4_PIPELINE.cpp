#include<iostream>
using namespace std;

int main(){
    int T,n,a,b;
    string s;
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        cin>>s;
        long long int price=0;
        price+=a*n+b*(n+1);
        for (int i = 0; i < s.size()-1; ++i)
        {
            if(s[1]=='0'){
                continue;
            } 
            else if(s[i]!=s[i+1]){
                price+=b+a;
            }
        }
        cout<<price<<endl;
    }
    return 0;
}