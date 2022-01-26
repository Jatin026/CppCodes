#include<iostream>
using namespace std;

int main(){
    int Marks[]={35,40,45,50};
    for (int i=0;i<4;i++)
    {
        cout<<Marks[i]<<endl;
    }
    // Printing the data using pointers
    int* p=Marks;
    cout<<"The address at 0 is : "<<p<<endl;
    cout<<"The value at 0 is : "<<*p<<endl;
    cout<<"The address at 1 is : "<<(p+1)<<endl;
    cout<<"The value at 1 is : "<<*(p+1)<<endl;
    return 0;
}