#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][3];
    int elements;
    for(int i=0;i<n;i++){
        for(int j=0; j<3;j++){
            cin>>elements;
            arr[i][j]=elements;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i][0]+arr[i][1]+arr[i][2]>=2){
            sum+=1;
        }
    }
    cout<<sum;
    return 0;
}