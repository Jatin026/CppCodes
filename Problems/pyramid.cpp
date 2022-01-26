#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows :";
    cin>>n;
    int capacity;
    for(int i=0;i<n;i++){
        capacity=2*i+1;
        for(int j=0;j<(2*n-1);j++){
            if(i+j>=n-1 && capacity>0){
                cout<<"*";
                capacity--;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int i=n-2;i>=0;i--){
        capacity=2*i+1;
        for(int j=0;j<(2*n-1);j++){
            if(i+j>=n-1 && capacity>0){
                cout<<"*";
                capacity--;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}