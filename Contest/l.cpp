#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[3]={1,2,3};
    int *p=a;
    int**ptr=&p;
    cout<<*a<<endl;
    cout<<*p<<endl;
    cout<<(*ptr)[1];
    return 0;
}