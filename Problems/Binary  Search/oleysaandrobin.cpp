#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,s;
    cin>>n>>s;
    
    if(n==1 && s==10){
        cout<<-1;
        return 0;
    }
    cout<<s;
    if(s==10) n--;
    for (int i = 1; i <n ; i++)
    {
        cout<<0;
    }
    
    return 0;
}