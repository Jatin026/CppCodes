#include<iostream>
using namespace std;
const int M=1e9+7;
int main(){
    string s;
    cin>>s;
    int ans=1;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='w' || s[i]=='m'){
            cout<<0;
            exit(0);
        }
        else{
            int count=1;
            int j=i;
            while(s[j]==s[j+1])
            {
                count++;
                j++;
            }
            if(count>1){
                ans=((ans%M)*(count%M))%M;
        
            }
            i=j;
        }
    }
    cout<<ans;
    return 0;
}