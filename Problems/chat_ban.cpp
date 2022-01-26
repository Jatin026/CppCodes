#include<iostream>
#include<cmath>
using namespace std;

int main(){ 
    int t;
    cin>>t;
    long long int arr[t],x,k;
    for (int i = 0; i < t; i++)
    {
       
        cin>>k>>x;
        long long int z=k*(k+1)/2;
        if(z>=x){
            arr[i]=ceil((-1+sqrt(1+8*x))/2);
        }
        else if(k*k<=x){
            arr[i]=2*k-1;
        }         
        
        else{
            x=x-z;
            arr[i]=2*k-1-floor((-1+sqrt(1-4*(2*x+k-k*k)))/2);
        }
    }
    for (int i = 0; i < t ; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}