#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans=0;

    if(s.size()>2){for (int i = 0; i < s.size()-2; i++)
    {
        for(int j=i+1;j<s.size()-1;j++){
            for (int l = j+1; l < s.size(); l++)
            {
                if(s[i]=='Q' && s[j]=='A' && s[l]=='Q'){
                    ans++;
                }
            }
            
        }   
    }
    }
    cout<<ans;
    return 0;
}