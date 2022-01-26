#include<iostream>
using namespace std;
int sort(int array[5]){
    for(int i=0;i<5;i++){
        if (i==4){
            break;
        }
        else if (array[i]<array[i+1]){
            int temp;
            temp=array[i+1];
            array[i+1]=array[i];
            array[i]=temp;
        }
        return array[5];
        
    }
}
int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
     

     

    
    return 0;
}