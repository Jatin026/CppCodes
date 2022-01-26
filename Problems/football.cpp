#include<iostream>
using namespace std;

int main(){
    long long  n,p,w,d;
    cin>>n>>p>>w>>d;
    long long x=0,y=0,z=0;
    for(int i=0;i<=n;i++){
        for(int j=n-i;j>=0;j--){
            if(i*w+j*d==p ){
                x=i;
                y=j;
                z=n-x-y;
                cout<<x<<" "<<y<<" "<<z;
                exit(0);
            }
        }
    }
    cout<<-1;
    return 0;
}