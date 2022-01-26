#include<iostream>
#include<cmath>
using namespace std;
class Complex;
class Calculator{
    public:
        void sum(int a , int b){
            cout<<"The Sum is : "<<a+b;
        }
        int sumrealcomplex(Complex, Complex);
        int sumcompcomplex(Complex,Complex);
        Complex rotate(Complex,float);
};
class Complex
{
    int a;
    int b;
    friend class Calculator;//Example of making friend with whole class.
    //friend int  Calculator:: sumrealcomplex(Complex o1 , Complex o2); // Individual friend making 

public:
    Complex(){}
    Complex(int x , int y){
        a=x;
        b=y;
    }
    void getcomplex(int c1, int c2)
    {
        a = c1;
        b = c2;
    }
    void complexsum(Complex o1, Complex o2)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }
    void displaycomplex()
    {
        cout << "The complex number are : " << a << "+" << b << "i" << endl;
    }
};
Complex Calculator ::rotate(Complex o,float d){
    
    Complex c;
    float x = d*3.14159/180;
    c.a = cos(x);
    c.b= sin(x);
    Complex e(((o.a)*(c.a)-(o.b)*(c.b)),((o.b)*(c.a)+(o.a)*(c.b)));
    return(e);
}
int Calculator:: sumrealcomplex(Complex  o1, Complex o2){
    return(o1.a+o2.a);
}
int Calculator:: sumcompcomplex(Complex  o1, Complex o2){
    return(o1.b+o2.b);
}
int main(){
    Complex o1,o2;
    Calculator calc;
    o1.getcomplex(3,5);
    o1.displaycomplex();
    o2.getcomplex(8,11);
    o2.displaycomplex();
    int real=calc.sumrealcomplex(o1,o2);
    int comp=calc.sumcompcomplex(o1,o2);
    cout<<"The real sum of these complex numbers is : "<<real<<endl;
    cout<<"The imaginary  sum of these complex numbers is : "<<comp<<endl;
    Complex f =calc.rotate(o1,45);
    f.displaycomplex();
    return 0;
}  