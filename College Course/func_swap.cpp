#include<bits/stdc++.h>
using namespace std;
void func(int &a , int &b , int &c){
    swap(a,c);
    swap(a,b);
    cout<<a<<"\t"<<b<<"\t"<<c;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    func(a,b,c);
    return 0;
}