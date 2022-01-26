#include<iostream>
using namespace std;

int main(){
    int k,l,m,n;
    long long d;
    cin>>k>>l>>m>>n;
    cin>>d;
    int arr[d+1]={0};
    if(k==1||l==1||m==1||n==1){cout<<d; exit(0);}
    for(int i=1;i<=(d)/k;i++){
        arr[i*k]=1;
    }
    for(int i=1;i<=(d)/l;i++){
        arr[i*l]=1;
    }
    for(int i=1;i<=(d)/m;i++){
        arr[i*m]=1;
    }
    for(int i=1;i<=(d)/n;i++){
        arr[i*n]=1;
    }
    int count=0;
    for(int i=1;i<=d+1;i++){
        if(arr[i]==1){
            count+=1;
        }
    }
    cout<<count;
    return 0;
}