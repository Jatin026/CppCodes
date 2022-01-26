#include<iostream>
using namespace std;
bool check_prime(int x){
    for(int i=2;i<=x/2;i++){
        if (x%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n=0;
    int findindex;
    cin>>findindex;
    int prime_index=0;
    while(prime_index!=findindex){
        n++;
        if(check_prime(n)==1){
            prime_index+=1;
        }
    }
    cout<<n;
    return 0;
}