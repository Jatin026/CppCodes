#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    if(a==9 && b==1) cout<<9<<" "<<10;
    else if(b-a>1 || b-a<0) cout<<-1;
    else{
        if(b-a==1) cout<<a*100+99<<" "<<b*100;
        else cout<<a*100+12<<" "<<b*100+13;
    }
    return 0;
}