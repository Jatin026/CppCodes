#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        long long int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b>=a) cout<<b<<endl;
        else{
            if((c-d)<=0) cout<<-1<<endl;
            else  {
                if(((a-b)%(c-d))==0){
                    cout<<((a-b)/(c-d))*c+b<<endl;
                }
                else{
                    cout<<(((a-b)/(c-d))+1)*c+b<<endl;
                }
            }
        }
    }
    return 0;
}