#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,c,d,e;

    cout<<"Enter 5 numbers and after entering each number hit enter\n";
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;

    cout<<"Maximum number is: "<<max(max(max(a,b),max(c,d)),e);

    return 0;



}