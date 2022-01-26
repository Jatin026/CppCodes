#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int c=max(a,b);
        int d=min(a,b);
        if(c<=2*d){
            cout<<4*d*d<<endl;
        }
        else{
            cout<<c*c<<endl;
        }
    }
    return 0;
}