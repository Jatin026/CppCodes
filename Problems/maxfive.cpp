#include<iostream>
using namespace std;

int main(){
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    int arr[5]={a,b,c,d,e};
    int maximum_no=arr[0];
    for(int i=0;i<5;i++){
        if(maximum_no<arr[i]){
            maximum_no=arr[i];
        }
    }
    cout<<"The maximum no. is : "<<maximum_no;
    return 0;
}