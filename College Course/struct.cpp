#include<bits/stdc++.h>
using namespace std;
struct Complex{
    double real,img;
    void input(){
        cin>>real>>img;
    }
    void magnitude(){
        cout<<pow(real*real+img*img,0.5)<<'\n';
    }
    void argument(){
        cout<<atan(img/real)<<'\n';
    }
    void display(){
        cout<<real<<" "<<img<<'\n';
    }
};
Complex add(Complex &c1, Complex &c2){
    Complex c3;
    c3.real=c1.real+c2.real;
    c3.img=c1.img+c2.img;
    return c3;
}
int main(){
    Complex c1,c2,c3;
    c1.input();
    c2.input();
    c3=add(c1,c2);
    c3.display();
    return 0;
}