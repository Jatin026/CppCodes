#include<iostream>
using namespace std;
int numb=0;
class num{
    public:
        num(){
            numb++;
            cout<<"Enter constructor for object "<<numb<<endl;
        }
        ~num(){
            cout<<"Entering destructor for object "<<numb<<endl;
            numb--;
        }
};

int main(){
    cout<<"Entering the main function "<<endl;
    cout<<"Creating the first object  "<<endl;
    num n1;
    {
        cout<<"Entering the block "<<endl;
        cout<<"Creating the second and third object  "<<endl;
        num n2,n3;
        cout<<"Exiting the Block  "<<endl;
    }
    cout<<"Exiting the main function"<<endl;
    return 0;
}