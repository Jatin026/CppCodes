#include<iostream>
using namespace std;
bool check_prime(int x){
    if(x==2) return 1;
    else if(x%2==0 )  return 0;
    else{for (int i = 2; i < x/2; i++)
    {
        if(x%i==0){
            return 0;
        }
    }
    return 1;}
    
}
int main(){
    long int n;
    cin>>n;
    long int x,y;
    for(int i=4;i<n-3;i++){
        if(check_prime(i)==0 && check_prime(n-i)==0){
            cout<<i<<" "<<n-i;
            break;
        }
    }
    return 0;
}