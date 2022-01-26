#include<iostream>
using namespace std;
class Complex{
    int a,b;
    public:
        void get_data(){
            cout<<"The value of a is : "<<a<<endl;
            cout<<"The value of b is : "<<b<<endl;

        }
        void set_data(int x , int y){
            a=x;
            b=y;
        }
};
int main(){
    Complex d;
    d.set_data(1,3);
    d.get_data();
    Complex* c=new Complex;
    (*c).set_data(2,6);    
    (*c).get_data();
    Complex* e=new Complex;
    e->set_data(3,9);
    e->get_data();    
    return 0;
}