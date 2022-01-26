#include<iostream>
using namespace std;

int main(){
    int n,rem,temp=0;
    cin>>n;
    cout<<"The initial int : "<<n<<endl;  
    while(n>0){
        rem=n%10;
        temp=temp*(10)+rem;
        n=n/10;
    }
    cout<<"The reverse int : "<<temp;
    return 0;
}