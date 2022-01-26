#include<iostream>
using namespace std;
bool chk_prime(int a){
    for(int b=2; b<a ; b++)
    {
       if( a%b == 0) {
        return 0; 
       }
    }
    return 1;
}
int main(){
    int a,b;
    cin>>a>>b;
    for (int i = a; i < b; i++)
    {
        if(chk_prime(i)==1){
            cout<<i<<endl;
        }
    }
    
    return 0;
}