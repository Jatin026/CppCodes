#include<iostream>
#include <cmath>
using namespace std;

int main(){
    int i=8,j=5;
    float x=0.005,y=-0.01;
    cout<<5*fmod(((i/7)+(j*(i-3))),((x+y-2+i)));
    return 0;
}