#include<iostream>
using namespace std;
typedef struct employee
{
    int eID;
    float salary;
    char favchar;
}cp;//cp is not compulsary , any word can be used
// type def can be used to reduce the effort of typing struct employee
// example of Union
union village
{
    /* data */
    int wheat;
    char favl;
    float pounds;
};

int main(){
    // example of enum
    enum Meal{Breakfast,Lunch,Dinner};
    Meal m1=Lunch;
    cout<<m1<<endl;
    union village p1;
    p1.wheat=5;
    cout<<p1.wheat<<endl;
    p1.favl='l';
    p1.pounds=21;
/*benefit of union is memory management, but the data should be 
used one at a time otherwise error*/
    struct employee shyam;
    cp balwinder;
    shyam.eID=1;
    shyam.salary=10000000;
    shyam.favchar='e';
    cout<<"The Employee ID of Shyam is : "<<shyam.eID<<endl;
    cout<<"The salary of Shyam is : "<<shyam.salary<<endl;
    cout<<"The favchar of Shyam is : "<<shyam.favchar<<endl;
    return 0;
}