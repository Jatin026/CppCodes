#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    int temp=n, temp2=n;
    int digits=0;
    while(temp>0){
        digits++;
        temp=temp/10;
    }
    int sum=0;
    while(n>0){
        sum+=pow((n%10),digits);
        n=n/10;
    }
    if(sum==temp2){
        cout<<"Armstrong";
    }
    else{
        cout<<"NO";
    }
    return 0;
}