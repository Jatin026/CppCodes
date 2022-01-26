#include<iostream>
using namespace std;

int main(){
    string arr[5];
    string *ptr=&arr[0];
    string * ptrdost=&arr[0];
    string n;
    for(int i=0;i<5;i++){
        cin>>n;
        *(ptr+i)=n;
    }
    for (int j = 0; j < 5 ; j++)
    {
        for(int i=0;i<5;i++){
        cout<<*(ptr)<<" ";
        if(*(ptr)==arr[4]){
            ptr=ptrdost;
        }
        else{
            ptr++;
        }
        }
        ptr++;      
        cout<<endl;
    }
    
    return 0;
}