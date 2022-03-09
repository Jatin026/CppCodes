#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int sum=0;
        string s,num;
        cin>>s>>num;
        for(int j=0 ;  j < num.size(); j++){
            sum+=num[j]-48;
        }
        if(sum%2==0) cout<<s<<"\n";
    }
    
    return 0;
}