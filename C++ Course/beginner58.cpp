#include<iostream>
using namespace std;
template<class T >
void swapp(T  &a, T &b ){
    T temp = a;
    a=b;
    b=temp;
}
int main(){
    float x=5;
    float y=23.241;
    swapp(x,y);
    cout<<x<<endl<<y<<endl;
    return 0;
}