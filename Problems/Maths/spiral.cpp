#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    if(y==0 &&(x==1 || x==0)) cout<<0;
    else if(abs(x) + 1 < y && y <= x){
        cout<<4*abs(x)-3;
    }
    else if(abs(y) <= x && x < y){
        cout<<4*abs(y)-2;
    }
    else if(x <= y && y < (-x)){
        cout<<4*abs(x)-1;
    }
   else cout<<abs(4*y);
     
    return 0;
}