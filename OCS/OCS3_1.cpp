#include<iostream>
using namespace std;
void apartment(int n){
    int x=0,y=0,z=0,rem=n%10;
    if(n==1 || n==2 || n==4){
        cout<<-1<<endl;
    }
    else{
    if(n%5==0){
        y=n/5;
    }
    else if(n%3==0){
        x=n/3;      
    }
    else if(n%7==0){
        z=n/7;
    }
    else if(rem==7){
        y=(n-7)/5;
        z=1;
    }
    else if(rem==8 ){
        y=(n-3)/5;
        x=1;
    }
    else if(rem==6 || rem==3 || rem ==9){
        y=(n-rem)/5;
        x=rem/3;
    }
    else if( rem==4){
        if(n>10){
            z=2;
            y=(n-14)/5;
        }
    }
    else if(rem==2){
         
        y=(n-12)/5;
        x=4;
         
    }
    else if(rem==1) {
            y=(n-6)/5;
            x=2;
    }
    cout<<x<<" "<<y<<" "<<z<<endl;
    }
}
int main(){
    int t,n;
    cin>>t;
    int arr[t];
    for(int i=0;i<t;i++)
    {
        cin>>n;
        arr[i]=n;
         
    }
    for(int i=0;i<t;i++)
    {
        
        apartment(arr[i]);
         
    }
    return 0;
}