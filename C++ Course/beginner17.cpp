// Reversing a number in C++
#include<iostream>
using namespace std;
int rev,r;
int revn(int n){
    while(n>0){ 
        r=n%10;
        rev=rev*10+r;
        n=n/10;}
    return rev;        
}

int main(){
    int n;
    cout<<"Enter the value of n you want reverse of : ";
    cin>>n;
    cout<<"The reverse of integer "<<n<<" is "<<revn(n); 
    return 0;
}