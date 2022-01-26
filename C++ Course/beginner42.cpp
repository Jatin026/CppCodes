#include<iostream>
#include<cmath>
using namespace std;
class SimpleCalculator{
    protected:
        int a,b ;
    public:
        SimpleCalculator(){}
        SimpleCalculator(int x , int y){
            a=x;
            b=y;
        }
        float addition(){    
            return(a+b);
        }
        float subtraction(){
             
            return(a-b);
        }
        float multiply(){
            
            return(a*b);
        }
        float division(){
             
            return(a/b);
        }
        void display(){
            cout<<"Their addition is : "<<addition()<<endl;
            cout<<"Their subtration is : "<<subtraction()<<endl;
            cout<<"Their multiplication is : "<<multiply()<<endl;
            cout<<"Their division is : "<<division()<<endl;
        }
};
class ScientificCalculator{
    protected:
        float  c ;
    public:
        ScientificCalculator(){}
        ScientificCalculator(int x){
            c=x;
        }
        float square(){
            return(pow(c,2)); 
        }
        float cube(){
            return(pow(c,3));

        }
        float squareroot(){
            return(sqrt(c));
        }
        float cuberoot(){
            return(cbrt(c));
        }
        float show(){
            cout<<"The square is : "<<square()<<endl;
            cout<<"The squareroot is : "<<squareroot()<<endl;
            cout<<"The cube is : "<<cube()<<endl;
            cout<<"The cuberoot is : "<<cuberoot()<<endl; 
        }

};
class HybridCalculator : public ScientificCalculator,public SimpleCalculator{
    protected:
        
    public:
        HybridCalculator(int x,int y):SimpleCalculator(x,y){};
        HybridCalculator(int x):ScientificCalculator(x){};
};

int main(){
    HybridCalculator l(4);
    HybridCalculator b(3);
    HybridCalculator h(l.square(),b.square());
    h.display();
    return 0;
}