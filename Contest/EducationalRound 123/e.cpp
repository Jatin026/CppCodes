#include<bits/stdc++.h>
using namespace std;
struct point{
int x,y;
point(){}
point(double a, double b){
x=a; y=b;}
double add(int a, int b){
x+=a; y+=b;
return x+y;
}
};
int main(){
    point p1, p2(-3.3, 2.1);
    cout<<p2.add(p1.add(1,2),p2.add(3.3,2));
    return 0;
}