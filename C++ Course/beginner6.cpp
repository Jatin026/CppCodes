#include <iostream>
using namespace std;
int main(){
    int age;
    cout<<"Tell me your age : \n";
    cin>>age;
    if (age<18){
        cout<<"You are ineligible for vaccination";
    }
    else{
        cout<<"Please visit your Nearby Vaccination Centre";
    }
    return 0;
}