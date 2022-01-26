#include<bits/stdc++.h>
using namespace std;
int main(){
    int day,price,type;
    cout<<"Enter the number day of stay"<<endl;
    cin>>day;
    while(day>7 ||day<0){
        cout<<"Please enter the integer between 0 and 7 (Inclusive)"<<endl;
        cin>>day;
    }  
    cout<<"1)The Price of Deluxe AC is 2000 Rs for a single day"<<endl;
    cout<<"2)The Price of Deluxe non AC is 1500 Rs for a single day"<<endl;
    cout<<"3)The Price of Non Deluxe AC is 1000 Rs for a single day"<<endl;
    cout<<"4)The Price of Non Deluxe non AC is 750 Rs for a single day"<<endl;
    cout<<"Enter 1,2,3,4 respectively for the type of room "<<endl;
    cin>>type;
    while(type<1 || type>4){
        {
        cout<<"Please enter the integer between 1 and 4 (Inclusive)"<<endl;
        cin>>type;
        }
    }
    if(type==1) price=2000*day;
    else if(type==2) price=1500*day;
    else if(type==3) price=1000*day;
    else  price=750*day;
    cout<<"The price of stay is : "<<price;
    return 0;
}