#include<iostream>
using namespace std;
class Number{
    int x;
    public:
        Number(){
            x=0;
        }
        Number(int a){
            x=a;
        }
        void display(){
            cout<<"Your entered number is : "<<x<<endl;
        }
        Number(Number &obj){//***********Example of Copy Constructor*****************
            x=obj.x;
            cout<<"****The copy constructor is called****"<<endl;
        }

};
//Compiler supplies its own copy constructor to the program when there is no copy constructor.   
int main(){
    Number a,b,c(7),e;
    a.display();
    b.display();
    c.display();
    Number d(c);
    d.display();
    e=c;
    e.display();
    Number f=c;
    return 0;
}