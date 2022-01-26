#include<iostream>
#include<cmath>
using namespace std;
int fac(int n){
    if (n==1){
        return 1;
    }
    else if(n==0){
        return 1;
    }
    else{
        return(n*fac(n-1));
    } 
    }
int main(){
    int n,x,sum=1,i=1;
    cin>>n>>x;
    while (n-->1)
    {
        sum+=(i+1)*pow(-x,i)/fac(i);
        i++;
    }
    cout<<sum;
    return 0;
}