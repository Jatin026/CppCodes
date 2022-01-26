#include<iostream>
using namespace std;
class c2;
class c1{
    int val1;
    public:
        void setinfo(int a){
            val1=a;
        }
        void getData(){
            cout<<"The value of val1 is "<<val1<<endl;
        }
        friend void swap(c1 &,c2&);
};
class c2{
    int val2;
    public:
        void setinfo(int a){
            val2=a;
        }
        void getData(){
            cout<<"The value of val2 is "<<val2<<endl;
        }
        friend void swap(c1 &,c2&);
};
void swap( c1 & o1 ,c2 & o2){
    int temp=o2.val2;
    o2.val2=o1.val1;
    o1.val1=temp;
}
int main(){
    c1 o1;
    c2 o2;
    o1.setinfo(5);
    o2.setinfo(8);
    o1.getData();
    o2.getData();
    swap(o1, o2);
    o1.getData();
    o2.getData();

    return 0;
}