#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    int a,b,persons=0,maxp;
    maxp=persons;
    while (t--)
    {
        cin>>a>>b;
        persons-=a;
        persons+=b;
        maxp=max(persons,maxp);
    }
    cout<<maxp;
    return 0;
}