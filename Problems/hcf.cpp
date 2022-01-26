#include<iostream>
using namespace std;
int find_hcf(int a,int b){
    a=a%b;
    if(a==0){
        return b;
    }
    b=b%a;
    if(b==0){
        return a;
    }
    else{
    return b;
    }
}
int main(){
    int a,b;
    cin>>a>>b;
    long long l,h;
    cin>>l>>h;
    long long hcf=find_hcf(b,a);
    if (hcf<l || hcf>h)
        {
            if(hcf<l){
                cout<<-1;
                exit(0);
                 
            }
            for(int i=2;i<hcf;i++){
                if(hcf%i==0){
                    int k=hcf/i;
                    if(k<h)
                    {
                        cout<<hcf/i;
                        break;
                    }
                }
            }
        }
    else cout<<hcf;
    return 0;
}